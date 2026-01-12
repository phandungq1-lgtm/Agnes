#include <iostream>
#include <fstream>
#include <cstring>
#include "Phong.h"
#include "KhachHang.h"
#include <bits/stdc++.h>



using namespace std;

/* ===== KHAI BAO NGUYEN MAU HAM ===== */
// Phong
void themPhong();
void suaPhong();
void xoaPhong();
void lietKePhong();

// Khach hang
void themKhachHang();
void xoaKhachHang();

// Dat phong
void datPhong();
void traPhong();

/* ===== THEM PHONG ===== */
void themPhong() {
    cout << "Nhap thong tin phong \n";
    Phong p;
    cin.ignore();
    p.nhap();

    // luu file
    ofstream f("phong.dat", ios::binary | ios::app);
    f.write((char*)&p, sizeof(p));
    f.close();
    cout << "Them phong thanh cong !";
}

/* ===== SUA PHONG ===== */
void suaPhong() {
    Phong p;
    char ma[10];
    char loaiPhongMoi[20];
    cin.ignore();
    // Nhap ma phong, khong duoc de trong
    do {
        cout << "Nhap ma phong can sua (khong duoc de trong): ";
        cin.getline(ma, 10);
        if (strlen(ma) == 0) {
            cout << "Ma phong khong duoc de trong!\n";
        }
    } while (strlen(ma) == 0);

    // Nhap loai phong moi, khong duoc de trong
    do {
        cout << "Nhap loai phong moi (khong duoc de trong): ";
        cin.getline(loaiPhongMoi, 20);
        if (strlen(loaiPhongMoi) == 0) {
            cout << "Loai phong khong duoc de trong!\n";
        }
    } while (strlen(loaiPhongMoi) == 0);

    fstream f("phong.dat", ios::binary | ios::in | ios::out);

    while (f.read((char*)&p, sizeof(p))) {
        if (strcmp(p.maPhong, ma) == 0) {
            strcpy(p.loaiPhong, loaiPhongMoi);

            f.seekp(-sizeof(p), ios::cur);
            f.write((char*)&p, sizeof(p));

            cout << "Sua phong thanh cong!\n";
            f.close();
            return;
        }
    }

    cout << "Khong tim thay phong!\n";
    f.close();
}

/* ===== XOA PHONG ===== */
void xoaPhong() {

    Phong p;
    char ma[10];
    bool timThay = false;
    bool phongDuDieuKienXoa = false;

    cout << "Nhap ma phong can xoa: ";
    cin.ignore(); // xóa rác từ trước
    cin.getline(ma, 10); // đọc "vip 2"

    ifstream f("phong.dat", ios::binary);
    ofstream t("temp.dat", ios::binary);

    while (f.read((char*)&p, sizeof(p))) {
        if (strcmp(p.maPhong, ma) == 0) {
             timThay = true;
            if (p.dangThue) {
                cout << "Phong dang thue, khong xoa duoc!\n";
                t.write((char*)&p, sizeof(p));
            } else {
                phongDuDieuKienXoa = true;
            }
        } else {
            t.write((char*)&p, sizeof(p));
        }
    }
    f.close();
    t.close();
    remove("phong.dat");
    rename("temp.dat", "phong.dat");
    if (!timThay) {
        cout << "Khong tim thay phong!\n";
    }
    if (phongDuDieuKienXoa) {
        cout << "Xoa phong thanh cong!\n";
    }
}

/* ===== LIET KE PHONG DANG DUOC THUE ===== */
void lietKePhongDangDuocThue() {
    Phong p;                              // Tạo biến p để đọc từng phòng
    ifstream f("phong.dat", ios::binary); // Mở file phòng ở chế độ đọc nhị phân

    cout << "\nDanh sach phong dang duoc thue:\n";

    // Đọc lần lượt từng bản ghi phòng trong file
    while (f.read((char*)&p, sizeof(p))) {
        if (p.dangThue) {                // Nếu phòng đang được thuê
             p.xuat();                  // In thông tin phòng đó ra màn hình
        }
    }
    f.close();                          // Đóng file
}


/* ===== LIET KE PHONG ===== */
void lietKePhong() {
    Phong p;
    ifstream f("phong.dat", ios::binary);

    cout << "\nDanh sach phong:\n";
    while (f.read((char*)&p, sizeof(p))) {
        p.xuat();
    }
    f.close();
}

/* ===== THEM KHACH HANG ===== */
void themKhachHang() {
    KhachHang k;
    k.nhap();
    cout << "Them khach hang thanh cong !";

    ofstream f("khachhang.dat", ios::binary | ios::app);
    f.write((char*)&k, sizeof(k));
    f.close();
}

/* ======SUA KHACH HANG ====*/
void suaKhachHang() {
    KhachHang k;
    char ma[10];
    cin.ignore();
    do{
        cout << "Nhap ma khach hang can sua: ";
        cin.getline(ma, 10);
        if (strlen(ma)==0){
            cout << "Ma khach hang khong duoc de trong () \n";
        }
    }while(strlen(ma)==0);
    fstream f("khachhang.dat", ios::binary | ios::in | ios::out);

    while (f.read((char*)&k, sizeof(k))) {
        if (strcmp(k.maKH, ma) == 0) {
            k.nhap();   // nhập lại tên, sdt...

            f.seekp(-sizeof(KhachHang), ios::cur);
            f.write((char*)&k, sizeof(KhachHang));

            f.close();
            cout << "Sua khach hang thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay khach hang!\n";
    f.close();
}


/* ===== XOA KHACH HANG ===== */
void xoaKhachHang() {
    KhachHang k;
    Phong p;
    char ma[10];
    bool coKhach = false;   // kiểm tra có tồn tại khách không
    cout << "Nhap ma khach hang can xoa: ";
    cin >> ma;

    // Kiem tra khach co dang thue phong nao khong
    ifstream fp("phong.dat", ios::binary);
    while (fp.read((char*)&p, sizeof(p))) {
        if (p.dangThue && strcmp(p.maKH, ma) == 0) {
            cout << "Khach dang thue phong, khong xoa duoc!\n";
            fp.close();
            return;
        }
    }
    fp.close();

    // Neu khong thue phong thi tien hanh xoa
    ifstream f("khachhang.dat", ios::binary);
    ofstream t("temp.dat", ios::binary);

    while (f.read((char*)&k, sizeof(k))) {
        if (strcmp(k.maKH, ma) == 0) {
            coKhach = true;          // tim thay khach can xoa
        } else {
            t.write((char*)&k, sizeof(k));
        }
    }

    f.close();
    t.close();

    if (!coKhach) {
        cout << "Khong tim thay khach hang!\n";
        remove("temp.dat");
        return;
    }

    remove("khachhang.dat");
    rename("temp.dat", "khachhang.dat");
    cout << "Xoa khach hang thanh cong!\n";
}

/* ===== DAT PHONG ===== */
void datPhong() {

    char maKH[10];
    char maPhong[10];

    cout << "Nhap ma KH: ";
    cin >> ws;
    cin.getline(maKH, 10);
    cout << "Nhap ma phong: ";
    cin.getline(maPhong, 10);

    Phong p;
    fstream f("phong.dat", ios::binary | ios::in | ios::out);

    while (f.read((char*)&p, sizeof(p))) {
        if (strcmp(p.maPhong, maPhong) == 0 && p.dangThue) {
            cout << "Phong nay da co nguoi thue roi!\n";
            f.close();
            return;
        }
        if (strcmp(p.maPhong, maPhong) == 0 && !p.dangThue) {
            // buoc quan trong
            p.dangThue = true;
            strcpy(p.maKH, maKH);

            f.seekp(-sizeof(p), ios::cur);
            f.write((char*)&p, sizeof(p));

            cout << "Dat phong thanh cong!\n";
            f.close();
            return;
        }
    }

    cout << "Khong dat duoc phong!\n";
    f.close();
}

/* ===== TRA PHONG ===== */
void traPhong() {
    char maPhong[10];

    cout << "Nhap ma phong: ";
    cin >> ws;
    cin.getline(maPhong, 10);

    Phong p;
    fstream f("phong.dat", ios::binary | ios::in | ios::out);

    while (f.read((char*)&p, sizeof(p))) {
        if (strcmp(p.maPhong, maPhong) == 0 && p.dangThue) {
            // buoc quan trong
            p.dangThue = false;
            strcpy(p.maKH, "\0");

            f.seekp(-sizeof(p), ios::cur);
            f.write((char*)&p, sizeof(p));

            f.close();
        }
    }

    cout << "tra phong thanh cong!\n";
    f.close();
}

/* ===== MENU CHINH ===== */
int main() {
    int chon;
    do {
        cout << "\n===== QUAN LY KHACH SAN =====\n";
        cout << "1. Nhap them 1 phong\n";
        cout << "2. Sua thong tin phong (theo ma)\n";
        cout << "3. Xoa 1 phong (theo ma, khong xoa neu dang thue)\n";
        cout << "4. Nhap thong tin khach hang\n";
        cout << "5. Sua thong tin khach hang (theo ma)\n";
        cout << "6. Xoa thong tin khach hang (theo ma, khong xoa neu dang dat phong)\n";
        cout << "7. Dat phong\n";
        cout << "8. Tra phong\n";
        cout << "9. Liet ke toan bo phong\n";
        cout << "10. Liet ke phong dang duoc thue\n";
        cout << "11. Thoat\n";
        cout << "Lua chon: ";

        if (!(cin >> chon)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nhap sai! Vui long nhap so tu 1 den 11.\n";
            continue;
        }

        if (chon < 1 || chon > 11) {
            cout << "Lua chon khong hop le! Nhap tu 1 den 11.\n";
            continue;
        }

        switch (chon) {
        case 1: themPhong(); break;
        case 2: suaPhong(); break;
        case 3: xoaPhong(); break;
        case 4: themKhachHang(); break;
        case 5: suaKhachHang(); break;
        case 6: xoaKhachHang(); break;
        case 7: datPhong(); break;
        case 8: traPhong(); break;
        case 9: lietKePhong(); break;
        case 10: lietKePhongDangDuocThue(); break;
        case 11: cout << "Thoat chuong trinh!\n"; break;
        }
    } while (chon != 11);

    return 0;
}
