#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Can thiet de can le va xuat theo cot

using namespace std;

class NhanVien {
private:
    string maNV;
    string tenNV;
public:
    // 1. Constructor khong doi
    NhanVien() {
        maNV = "";
        tenNV = "";
    }

    // 2. Constructor co doi
    NhanVien(string ma, string ten) {
        maNV = ma;
        tenNV = ten;
    }

    // Ham xuat du lieu ra man hinh theo cot
    void xuatTheoCot() {
        // Can trai, maNV chiem 15 ky tu, tenNV chiem 30 ky tu
        cout << left << setw(15) << maNV << setw(30) << tenNV << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien (n): ";
    cin >> n;

    // Khoi tao vector rong (Cach 3)
    vector<NhanVien> dsNhanVien;

    cout << "\n--- NHAP THONG TIN NHAN VIEN ---" << endl;
    for (int i = 0; i < n; i++) {
        string ma, ten;
        cout << "\nNhan vien thu " << i + 1 << ":" << endl;
        cout << "  - Nhap ma NV: ";
        cin >> ma;
        cin.ignore(); 
        cout << "  - Nhap ten NV: ";
        getline(cin, ten);

        // 3. Su dung constructor co doi de tao doi tuong va dua vao mang
        NhanVien nv(ma, ten);
        dsNhanVien.push_back(nv); 
        // Hoac viet gon: dsNhanVien.push_back(NhanVien(ma, ten));
    }

    // 4. Xuat du lieu nhan vien theo cot
    cout << "\n--- DANH SACH NHAN VIEN ---" << endl;
    cout << left << setw(15) << "MA NV" << setw(30) << "TEN NV" << endl;
    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl; // Dong ke ngang
    
    for (int i = 0; i < n; i++) {
        dsNhanVien[i].xuatTheoCot();
    }

    return 0;
}
