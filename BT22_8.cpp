#include <iostream>
#include <string>
#include <vector>

using namespace std;


class NhanVien {
private:
    string maNV;
    string tenNV;
public:
    void nhap() {
        cout << "  - Nhap ma NV: ";
        cin >> maNV;
        cin.ignore(); 
        cout << "  - Nhap ten NV: ";
        getline(cin, tenNV);
    }

    void xuat() {
        cout << "Ma NV: " << maNV << ", Ten NV: " << tenNV << endl;
    }
};

//c1
void nhapBangMangTinh() {
    cout << "\n--- CÁCH 1: MaNG TINH ---" << endl;
    NhanVien dsNhanVien[10]; 
    
    for (int i = 0; i < 10; i++) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        dsNhanVien[i].nhap();
    }
    cout << "-> Da nhap xong (Mang tinh)!\n";
}

//c2
void nhapBangMangDong() {
    cout << "\n--- CÁCH 2: MaNG ÐoNG ---" << endl;
    NhanVien* dsNhanVien = new NhanVien[10]; 
    
    for (int i = 0; i < 10; i++) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        dsNhanVien[i].nhap(); 
    }
    
    delete[] dsNhanVien; 
    cout << "-> Da nhap xong va giai phong bo nho (Mang dong)!\n";
}

//c3
void nhapBangVector() {
    cout << "\n--- CÁCH 3: DÙNG STD::VECTOR ---" << endl;
    vector<NhanVien> dsNhanVien(10); 
    
    for (int i = 0; i < 10; i++) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        dsNhanVien[i].nhap();
    }
    cout << "-> Da nhap xong (Vector)!\n";
}

int main() {
    cout << "CHON CACH NHAP THONG TIN 10 NHAN VIEN:\n";
    
    // co the bo comment de chay thu
    
    nhapBangMangTinh();
    
    // nhapBangMangDong();
    
    // nhapBangVector();

    return 0;
}
