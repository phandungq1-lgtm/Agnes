#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
using namespace std;

/*
    Lop KhachHang
    - Luu thong tin cua khach hang
*/
class KhachHang {
public:
    char maKH[10];        // Ma khach hang
    char tenKH[30];       // Ten khach hang
    char sdt[15];         // So dien thoai

    void nhap();          // Nhap thong tin khach hang
    void xuat();          // Xuat thong tin khach hang
};

#endif
