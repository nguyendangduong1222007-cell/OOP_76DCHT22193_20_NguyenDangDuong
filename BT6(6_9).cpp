#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Cau 1: Khai bao lop sinh vien voi cac thuoc tinh
class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];
    string tenMon[5] = {"Mon 1", "Mon 2", "Mon 3", "Mon 4", "Mon 5"}; // Dat ten mon mac dinh

public:
    // Cau 2: Phuong thuc nhap
    void nhap() {
        cout << "Nhap ho ten: ";
        // Dung cin >> ws de xoa ki tu xuong dong con sot lai trong bo nho dem
        getline(cin >> ws, hoTen); 
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem 5 mon hoc:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "  Diem " << tenMon[i] << ": ";
            cin >> diem[i];
        }
    }

    // Cau 2: Phuong thuc tinh diem trung binh
    float tinhDTB() {
        float tong = 0;
        for (int i = 0; i < 5; i++) {
            tong += diem[i];
        }
        return tong / 5.0;
    }

    // Cau 2: Phuong thuc xuat
    void xuat() {
        cout << "Ho ten: " << hoTen 
             << " | Nam sinh: " << namSinh 
             << " | Diem trung binh: " << fixed << setprecision(2) << tinhDTB() << endl;
    }

    // Phuong thuc ho tro cho Cau 3: Kiem tra xem co mon nao duoi 5 khong
    bool kiemTraThiLai() {
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5.0) {
                return true;
            }
        }
        return false;
    }

    // Phuong thuc ho tro cho Cau 3: In ra ten mon va diem phai thi lai
    void inThongTinThiLai() {
        cout << "- Sinh vien: " << hoTen << endl;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5.0) {
                cout << "  + Mon thi lai: " << tenMon[i] << " | Diem: " << diem[i] << endl;
            }
        }
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

    // Cau 3: In ra man hinh thong tin cac sinh vien phai thi lai
    cout << "\n=== DANH SACH SINH VIEN PHAI THI LAI ===" << endl;
    bool coThiLai = false;
    for (int i = 0; i < n; i++) {
        if (dsSinhVien[i].kiemTraThiLai()) {
            dsSinhVien[i].inThongTinThiLai();
            coThiLai = true;
        }
    }

    // Truong hop ca lop deu qua mon
    if (!coThiLai) {
        cout << "Khong co sinh vien nao phai thi lai." << endl;
    }

    return 0;
}
