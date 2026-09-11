#include <iostream>
using namespace std;

// ================= CAU 1 =================
class SoPhuc {
private:
    double thuc;
    double ao;

public:
    // Ham tao khong doi
    SoPhuc() {
        thuc = 0;
        ao = 0;
    }

    // Ham tao co doi
    SoPhuc(double thuc, double ao) {
        this->thuc = thuc;
        this->ao = ao;
    }

    // Ham huy
    ~SoPhuc() {
        // Khong co cap phat dong nen ham huy de trong
    }

    // ================= CAU 2 =================
    // Khai bao toan tu nhap, xuat (dung friend de truy cap thuoc tinh private)
    friend istream& operator>>(istream& is, SoPhuc& sp);
    friend ostream& operator<<(ostream& os, const SoPhuc& sp);

    // ================= CAU 3 =================
    // Dinh nghia cac toan tu +, -, *, /
    SoPhuc operator+(const SoPhuc& sp) {
        return SoPhuc(this->thuc + sp.thuc, this->ao + sp.ao);
    }

    SoPhuc operator-(const SoPhuc& sp) {
        return SoPhuc(this->thuc - sp.thuc, this->ao - sp.ao);
    }

    SoPhuc operator*(const SoPhuc& sp) {
        // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
        return SoPhuc(this->thuc * sp.thuc - this->ao * sp.ao, 
                      this->thuc * sp.ao + this->ao * sp.thuc);
    }

    SoPhuc operator/(const SoPhuc& sp) {
        // (a + bi)/(c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
        double mau_so = sp.thuc * sp.thuc + sp.ao * sp.ao;
        return SoPhuc((this->thuc * sp.thuc + this->ao * sp.ao) / mau_so, 
                      (this->ao * sp.thuc - this->thuc * sp.ao) / mau_so);
    }
};

// ================= DINH NGHIA CAU 2 =================
istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "  Nhap phan thuc: ";
    is >> sp.thuc;
    cout << "  Nhap phan ao: ";
    is >> sp.ao;
    return is;
}

ostream& operator<<(ostream& os, const SoPhuc& sp) {
    os << sp.thuc;
    if (sp.ao >= 0) {
        os << " + " << sp.ao << "i";
    } else {
        os << " - " << -sp.ao << "i"; // Tranh in ra dang a + -bi
    }
    return os;
}

// ================= HAM MAIN KIEM THU =================
int main() {
    SoPhuc sp1, sp2;

    cout << "--- Nhap so phuc thu nhat ---\n";
    cin >> sp1;
    cout << "--- Nhap so phuc thu hai ---\n";
    cin >> sp2;

    cout << "\n=> So phuc 1: " << sp1 << endl;
    cout << "=> So phuc 2: " << sp2 << endl;

    cout << "\n--- KET QUA PHEP TINH ---\n";
    SoPhuc tong = sp1 + sp2;
    SoPhuc hieu = sp1 - sp2;
    SoPhuc tich = sp1 * sp2;
    SoPhuc thuong = sp1 / sp2;

    cout << "Cong: (" << sp1 << ") + (" << sp2 << ") = " << tong << endl;
    cout << "Tru : (" << sp1 << ") - (" << sp2 << ") = " << hieu << endl;
    cout << "Nhan: (" << sp1 << ") * (" << sp2 << ") = " << tich << endl;
    cout << "Chia: (" << sp1 << ") / (" << sp2 << ") = " << thuong << endl;

    return 0;
}
