#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    int ngay, thang, nam;
    double luong;

public:
    NhanVien() : luong(0) {}
    virtual void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> ngay >> thang >> nam;
        cin.ignore();
    }

    virtual void xuat() const {
        cout << setw(20) << hoTen 
             << " | " << setw(2) << setfill('0') << ngay << "/" 
             << setw(2) << thang << "/" << nam 
             << " | Luong: " << fixed << setprecision(2) << luong << endl;
    }

    virtual void tinhLuong() = 0;

    double getLuong() const {
        return luong;
    }

    int tinhTuoi(int namHienTai = 2025) const {
        return namHienTai - nam;
    }

    virtual ~NhanVien() {}
};

class NVSX : public NhanVien {
private:
    int soSanPham;
    double luongCoBan;

public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        cin.ignore();
    }

    void tinhLuong() override {
        luong = luongCoBan + soSanPham * 5000;
    }

    void xuat() const override {
        cout << "[SX] ";
        NhanVien::xuat();
    }
};

class NVVP : public NhanVien {
private:
    int soNgayLam;

public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLam;
        cin.ignore();
    }

    void tinhLuong() override {
        luong = soNgayLam * 100000;
    }

    void xuat() const override {
        cout << "[VP] ";
        NhanVien::xuat();
    }
};

#endif
