#include <iostream>
#include <string>

using namespace std;

// ================= CAU 1 =================
class MonHoc {
protected:
    string tenMon;
    float diemCC; // Diem chuyen can
    float diemKT; // Diem kiem tra
    float diemDT; // Diem thi
public:
    void nhap() {
        cout << "Nhap ten mon hoc: ";
        getline(cin, tenMon);
        cout << "Nhap diem chuyen can (CC): ";
        cin >> diemCC;
        cout << "Nhap diem kiem tra (KT): ";
        cin >> diemKT;
        cout << "Nhap diem thi (DT): ";
        cin >> diemDT;
    }

    void xuat() {
        cout << "Mon: " << tenMon 
             << " | CC: " << diemCC 
             << " | KT: " << diemKT 
             << " | DT: " << diemDT;
    }
};

// Khai bao lop sinh vien ke thua tu lop mon hoc
class SinhVien : public MonHoc {
private:
    string hoTen;
    string lop;
    string maSV;
public:
    // ================= CAU 2 =================
    void nhap() {
        cout << "Nhap ho ten sinh vien: ";
        getline(cin, hoTen);
        cout << "Nhap lop: ";
        getline(cin, lop);
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);
        
        // Goi ham nhap cua lop cha (MonHoc)
        MonHoc::nhap();
    }

    void xuat() {
        cout << "SV: " << hoTen 
             << " | Lop: " << lop 
             << " | Ma SV: " << maSV << " | ";
        // Goi ham xuat cua lop cha (MonHoc)
        MonHoc::xuat();
        cout << " | Diem HP: " << tinhDiemHP() << endl;
    }

    // Tinh diem hoc phan (Ban co the sua lai cong thuc nay theo dung yeu cau rieng cua truong)
    float tinhDiemHP() {
        return (diemCC * 0.1) + (diemKT * 0.2) + (diemDT * 0.7); 
    }

    // Ham ho tro kiem tra dieu kien cam thi (Phuc vu cho Cau 3)
    bool kiemTraCamThi() {
        if (diemCC < 5 || diemKT == 0) {
            return true;
        }
        return false;
    }
};

// ================= CAU 3 =================
int main() {
    int n;
    cout << "Nhap so luong sinh vien (n): ";
    cin >> n;

    // Khai bao mang dong chua n sinh vien
    SinhVien* dsSV = new SinhVien[n];

    // Nhap thong tin n sinh vien
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---\n";
        cin.ignore(); // Xoa phim Enter thua truoc khi dung getline
        dsSV[i].nhap();
    }

    // In ra man hinh thong tin cac sinh vien bi cam thi
    cout << "\n=============================================\n";
    cout << "--- DANH SACH SINH VIEN BI CAM THI ---\n";
    bool coNguoiCamThi = false;
    
    for (int i = 0; i < n; i++) {
        // Kiem tra dieu kien: CC < 5 hoac KT == 0
        if (dsSV[i].kiemTraCamThi() == true) {
            dsSV[i].xuat();
            coNguoiCamThi = true;
        }
    }

    if (coNguoiCamThi == false) {
        cout << "Khong co sinh vien nao bi cam thi (Tat ca deu dat dieu kien)." << endl;
    }

    // Giai phong bo nho cua mang dong
    delete[] dsSV;

    return 0;
}
