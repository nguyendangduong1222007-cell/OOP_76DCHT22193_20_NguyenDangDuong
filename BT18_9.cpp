#include <iostream>
#include <string>

using namespace std;

// ================= CAU 1 & CAU 2 =================
class Nguoi {
protected:
    string hoTen;
    int namSinh;
public:
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }
    
    void xuat() {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh;
    }
    
    string getHoTen() { 
        return hoTen; 
    }
};

class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;
public:
    void nhap() {
        // Goi lai ham nhap cua lop cha (Nguoi)
        Nguoi::nhap(); 
        
        cin.ignore(); // Xoa phim Enter bi thua sau khi nhap so (nam sinh)
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }
    
    void xuat() {
        // Goi lai ham xuat cua lop cha (Nguoi)
        Nguoi::xuat(); 
        cout << " | Ma SV: " << maSV << " | Diem TB: " << diemTB << endl;
    }
    
    string getMaSV() { 
        return maSV; 
    }
};

// ================= CAU 3 =================
int main() {
    int n;
    cout << "Nhap so luong sinh vien (n): ";
    cin >> n;

    // Khai bao mang dong chua n sinh vien (cach thong dung thay vi dung vector)
    SinhVien* dsSV = new SinhVien[n];

    // Nhap danh sach sinh vien
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---\n";
        cin.ignore(); // Xoa phim Enter thua truoc khi dung getline de nhap chuoi
        dsSV[i].nhap();
    }

    // Nhap thong tin tim kiem
    string tuKhoa;
    cout << "\n--- TIM KIEM ---\n";
    cout << "Nhap ma sinh vien hoac ho ten can tim: ";
    cin.ignore(); 
    getline(cin, tuKhoa);

    // Tim kiem va in ra ket qua
    bool timThay = false;
    cout << "\n--- KET QUA TIM KIEM ---\n";
    for (int i = 0; i < n; i++) {
        // Kiem tra xem tu khoa co khop voi Ma SV hoac Ho ten khong
        if (dsSV[i].getMaSV() == tuKhoa || dsSV[i].getHoTen() == tuKhoa) {
            dsSV[i].xuat();
            timThay = true;
        }
    }

    if (timThay == false) {
        cout << "Khong tim thay sinh vien phu hop!" << endl;
    }

    // Giai phong bo nho cua mang dong
    delete[] dsSV;

    return 0;
}
