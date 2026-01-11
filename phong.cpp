#include "Phong.h"
#include<bits/stdc++.h>
/*
    Ham nhap thong tin phong
*/
void Phong::nhap() {
    do {
        cout << "Nhap ma phong: ";
        // cai ham nay dung de lam gi??? de clear thang menu roi lay data
        // lay data trong 1 line
        cin.getline(maPhong, 10);

        if (strlen(maPhong) == 0)
            cout << "Khong duoc de trong ma phong!\n";
    } while (strlen(maPhong) == 0);

    do {
        cout << "Nhap loai phong: ";
        cin.getline(loaiPhong, 20);      // nhập loại phòng (có thể có dấu cách)

        if (strlen(loaiPhong) == 0)
            cout << "Khong duoc de trong loai phong!\n";
    } while (strlen(loaiPhong) == 0);

    dangThue = false;     // Mac dinh phong chua duoc thue
    maKH[0] = '\0';
}


/*
    Ham xuat thong tin phong
*/
void Phong::xuat() {
    cout << "Ma phong: " << maPhong
         << " | Loai phong: " << loaiPhong
         << " | Trang thai phong: " << (dangThue ? "Dang co nguoi thue" : "Phong trong");

    if (dangThue) {
        cout << " | Ma khach hang dang thue: " << maKH;
    }

    cout << endl;
}
