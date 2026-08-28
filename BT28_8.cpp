#include <iostream>

using namespace std;

// Cau 1: Khai bao lop ma tran
class MaTran {
private:
    int soHang;
    int soCot;
    int a[100][100]; // Mang 2 chieu luu cac phan tu, gioi han kich thuoc 100x100

public:
    // Cau 2: Khai bao cac phuong thuc nhap, xuat
    void nhap();
    void xuat();
    
    // Cau 3: Khai bao ham ban de thuc hien cong hai ma tran
    friend MaTran congMaTran(MaTran mt1, MaTran mt2);
};

// --- Dinh nghia cac phuong thuc ---

void MaTran::nhap() {
    cout << "Nhap so hang: ";
    cin >> soHang;
    cout << "Nhap so cot: ";
    cin >> soCot;
    
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void MaTran::xuat() {
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

// Dinh nghia ham ban (khong thuoc lop nen khong co pham vi MaTran::)
MaTran congMaTran(MaTran mt1, MaTran mt2) {
    MaTran ketQua;
    
    // Gia su nguoi dung nhap 2 ma tran dong cap (cung so hang, so cot)
    ketQua.soHang = mt1.soHang;
    ketQua.soCot = mt1.soCot;
    
    for (int i = 0; i < mt1.soHang; i++) {
        for (int j = 0; j < mt1.soCot; j++) {
            ketQua.a[i][j] = mt1.a[i][j] + mt2.a[i][j];
        }
    }
    
    return ketQua;
}

// --- Ham chinh (Cau 3 - thuc thi) ---
int main() {
    MaTran mt1, mt2, mtTong;
    
    cout << "==== NHAP MA TRAN THU 1 ====" << endl;
    mt1.nhap();
    
    cout << "\n==== NHAP MA TRAN THU 2 (Dong cap voi ma tran 1) ====" << endl;
    mt2.nhap();
    
    // Thuc hien cong 2 ma tran bang ham ban
    mtTong = congMaTran(mt1, mt2);
    
    // In ra man hinh cac ma tran
    cout << "\n--- MA TRAN 1 BAN DAU ---" << endl;
    mt1.xuat();
    
    cout << "\n--- MA TRAN 2 BAN DAU ---" << endl;
    mt2.xuat();
    
    cout << "\n--- MA TRAN KET QUA TONG ---" << endl;
    mtTong.xuat();
    
    return 0;
}
