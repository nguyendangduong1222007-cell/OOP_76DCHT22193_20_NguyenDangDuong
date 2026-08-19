#include <iostream>
#include <string>
using namespace std;

// Dinh nghia cau truc NhanVien
struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

int main() {
    int n;
    // Khai bao mang nhan vien toi da 100 phan tu
    NhanVien ds[100];
    
    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

// Ham nhap thong tin 1 nhan vien
void nhap1NV(NhanVien &nv) {
    cout << "Nhap ma NV: ";
    getline(cin, nv.maNV);
    cout << "Nhap ten NV: ";
    getline(cin, nv.tenNV);
    cout << "Nhap luong co ban: ";
    cin >> nv.luongCoBan;
    cout << "Nhap he so luong: ";
    cin >> nv.heSo;
    cin.ignore(); // Xoa bo nho dem sau khi nhap so
}

// Ham xuat thong tin 1 nhan vien
void xuat1NV(const NhanVien &nv) {
    cout << left << setw(12) << nv.maNV 
         << setw(25) << nv.tenNV 
         << setw(15) << fixed << setprecision(0) << nv.luongCoBan 
         << setw(10) << setprecision(2) << nv.heSo << endl;
}

// Ham nhap danh sach n nhan vien
void nhapDS(NhanVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        nhap1NV(ds[i]);
    }
}

// Ham xuat danh sach n nhan vien
void xuatDS(NhanVien ds[], int n) {
    cout << "\n================ DANH SACH NHAN VIEN ================\n";
    cout << left << setw(12) << "Ma NV" 
         << setw(25) << "Ho Ten" 
         << setw(15) << "Luong CB" 
         << setw(10) << "He So" << endl;
    cout << "-----------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        xuat1NV(ds[i]);
    }
}

int main() {
    int n;
    NhanVien ds[100];
    return 0;
}
