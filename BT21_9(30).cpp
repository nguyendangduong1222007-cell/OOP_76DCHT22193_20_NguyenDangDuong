#include <iostream>
#include <cmath> // Thu vien ho tro ham sqrt() de tinh can bac 2

using namespace std;

// ================= CAU 1 =================
class SP1 {
protected:
    float thuc;
    float ao;

public:
    // Ham tao (Co gan gia tri mac dinh la 0 neu khong truyen tham so)
    SP1(float t = 0, float a = 0) {
        thuc = t;
        ao = a;
    }

    // Phuong thuc nhap so phuc
    void nhap() {
        cout << "  + Nhap phan thuc: ";
        cin >> thuc;
        cout << "  + Nhap phan ao: ";
        cin >> ao;
    }

    // Phuong thuc in so phuc
    void in() const {
        if (ao >= 0) {
            cout << thuc << " + " << ao << "i";
        } else {
            cout << thuc << " - " << abs(ao) << "i"; // In dau tru truoc phan ao am
        }
    }

    // Tinh module so phuc: can bac 2 cua (thuc^2 + ao^2)
    float tinhModule() const {
        return sqrt(thuc * thuc + ao * ao);
    }
};

// ================= CAU 2 =================
class SP2 : public SP1 {
public:
    // Ham tao goi lai ham tao cua lop cha SP1
    SP2() : SP1() {}

    // Nap chong toan tu gan (=)
    SP2& operator=(const SP2& right) {
        if (this != &right) {
            this->thuc = right.thuc;
            this->ao = right.ao;
        }
        return *this;
    }

    // Nap chong toan tu lon hon (>) dua tren so sanh module
    bool operator>(const SP2& right) const {
        return this->tinhModule() > right.tinhModule();
    }
};

// ================= CAU 3 =================
int main() {
    int n;

    // Nhap so luong phan tu (toi da 10)
    do {
        cout << "Nhap so luong so phuc (1 - 10): ";
        cin >> n;
        if (n <= 0 || n > 10) {
            cout << "So luong khong hop le. Vui long nhap lai!\n";
        }
    } while (n <= 0 || n > 10);

    // Khai bao mang chua danh sach cac doi tuong SP2
    SP2 ds[10];

    // Nhap danh sach so phuc
    cout << "\n--- NHAP DANH SACH SO PHUC ---\n";
    for (int i = 0; i < n; i++) {
        cout << "- So phuc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sap xep lai danh sach da nhap theo trat tu giam dan cua module
    // Thuat toan sap xep noi bot (Bubble Sort) su dung toan tu > va =
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) { // Goi toan tu > da nap chong
                SP2 temp;
                temp = ds[i];    // Goi toan tu = da nap chong
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // In danh sach sau khi sap xep
    cout << "\n--- DANH SACH GIAM DAN THEO MODULE ---\n";
    for (int i = 0; i < n; i++) {
        cout << "So phuc " << i + 1 << ": ";
        ds[i].in();
        // In them gia tri module de ban de dang kiem tra ket qua sap xep
        cout << " (Module = " << ds[i].tinhModule() << ")\n"; 
    }

    return 0;
}
