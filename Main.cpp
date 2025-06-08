#include <iostream>
#include <vector>
#include <iomanip>
#include "nhanvien.h"

using namespace std;

int main() {
    vector<NVSX> dsSX;
    vector<NVVP> dsVP;
    int n, m;

    cout << "Nhap so nhan vien san xuat: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap NVSX thu " << i + 1 << ":\n";
        NVSX nv;
        nv.nhap();
        nv.tinhLuong();
        dsSX.push_back(nv);
    }

    cout << "\nNhap so nhan vien van phong: ";
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; ++i) {
        cout << "\nNhap NVVP thu " << i + 1 << ":\n";
        NVVP nv;
        nv.nhap();
        nv.tinhLuong();
        dsVP.push_back(nv);
    }

    // Xuất danh sách
    cout << "\n--- Danh sach nhan vien san xuat ---\n";
    for (const auto& nv : dsSX)
        nv.xuat();

    cout << "\n--- Danh sach nhan vien van phong ---\n";
    for (const auto& nv : dsVP)
        nv.xuat();

    // Tính tổng lương
    double tongLuong = 0;
    for (const auto& nv : dsSX)
        tongLuong += nv.getLuong();
    for (const auto& nv : dsVP)
        tongLuong += nv.getLuong();
    cout << "\nTong luong cong ty phai tra: " << fixed << setprecision(2) << tongLuong << endl;

    // NVSX có lương thấp nhất
    if (!dsSX.empty()) {
        int viTriMin = 0;
        for (int i = 1; i < dsSX.size(); ++i) {
            if (dsSX[i].getLuong() < dsSX[viTriMin].getLuong())
                viTriMin = i;
        }
        cout << "\nNhan vien san xuat co luong thap nhat:\n";
        dsSX[viTriMin].xuat();
    }

    // NVVP có tuổi cao nhất
    if (!dsVP.empty()) {
        int viTriMax = 0;
        for (int i = 1; i < dsVP.size(); ++i) {
            if (dsVP[i].tinhTuoi() > dsVP[viTriMax].tinhTuoi())
                viTriMax = i;
        }
        cout << "\nNhan vien van phong co tuoi cao nhat:\n";
        dsVP[viTriMax].xuat();
        cout << "Tuoi: " << dsVP[viTriMax].tinhTuoi() << endl;
    }

    return 0;
}
