#include "KhachHang.h"
#include <bits/stdc++.h>
using namespace std;

/*
    Ham nhap thong tin khach hang
*/
void KhachHang::nhap() {
    cin.ignore();
    do {
        cout << "Ma KH: ";
        cin.getline(maKH, 10);
        if (strlen(maKH) == 0)
            cout << "Khong duoc phep de trong!\n";
    } while (strlen(maKH) == 0);

    do {
        cout << "Ten KH: ";
        cin.getline(tenKH, 30);
        if (strlen(tenKH) == 0)
            cout << "Khong duoc phep de trong!\n";
    } while (strlen(tenKH) == 0);

    do {
        cout << "SDT: ";
        cin.getline(sdt, 15);
        if (strlen(sdt) == 0)
            cout << "Khong duoc phep de trong!\n";
    } while (strlen(sdt) == 0);
}

/*
    Ham xuat thong tin khach hang
*/
void KhachHang::xuat() {
    cout << maKH << " | " << tenKH << " | " << sdt << endl;
}
