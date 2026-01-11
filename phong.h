#ifndef PHONG_H
#define PHONG_H

#include <iostream>
using namespace std;

/*
    Lop Phong
    - Luu tru thong tin cua mot phong trong khach san
    - Chi khai bao thuoc tinh va ham
*/
class Phong {
public:
    char maPhong[10];     // Ma phong
    char loaiPhong[20];
    bool dangThue;        // Trang thai thue (true: dang thue)
    char maKH[10];

    void nhap();          // Nhap thong tin phong
    void xuat();          // Xuat thong tin phong
};

#endif
