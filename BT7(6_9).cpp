#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Cau 1: Khai bao lop sinh vien voi cac thuoc tinh ho ten, nam sinh, diem 4 mon hoc
class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];
    string tenMon[4] = {"Mon 1", "Mon 2", "Mon 3", "Mon 4"}; 

public:
    // Cau 2: Phuong thuc nhap
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen); 
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem 4 mon hoc:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "  Diem " << tenMon[i] << ": ";
            cin >> diem[i];
        }
    }

    // Cau 2: Phuong thuc tinh diem trung binh
    float tinhDTB() {
        float tong = 0;
        for (int i = 0; i < 4; i++) {
            tong += diem[i];
        }
        return tong / 4.0;
    }

    // Cau 2: Phuong thuc xuat
    void xuat() {
        cout << "- Ho ten: " << hoTen 
             << " | Nam sinh: " << namSinh 
             << " | Diem trung binh: " << fixed << setprecision(2) << tinhDTB() << endl;
    }

    // Phuong thuc kiem tra tieu chuan thi tot nghiep (Cau 3)
    // Dieu kien: DTB < 7 va khong co mon nao duoi 5
    bool kiemTraThiTotNghiep() {
        if (tinhDTB() >= 7.0) {
            return false; 
        }
        
        for (int i = 0; i < 4; i++) {
            if (diem[i] < 5.0) {
                return false; 
            }
        }
        
        return true; 
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien (n): ";
    cin >> n;

    // Cau 3: Nhap vao n sinh vien
    vector<SinhVien> dsSinhVien(n);
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---" << endl;
        dsSinhVien[i].nhap();
    }

    // Cau 3: In ra man hinh thong tin cac sinh vien phai thi tot nghiep
    cout << "\n=== DANH SACH SINH VIEN PHAI THI TOT NGHIEP ===" << endl;
    bool coThiTotNghiep = false;
    for (int i = 0; i < n; i++) {
        if (dsSinhVien[i].kiemTraThiTotNghiep()) {
            dsSinhVien[i].xuat();
            coThiTotNghiep = true;
        }
    }

    // Truong hop khong co ai thoa man dieu kien
    if (!coThiTotNghiep) {
        cout << "Khong co sinh vien nao phai thi tot nghiep theo tieu chuan nay." << endl;
    }

    return 0;
}
