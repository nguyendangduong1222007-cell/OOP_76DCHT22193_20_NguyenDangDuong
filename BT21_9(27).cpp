#include<iostream>
#include<cmath> 
using namespace std;

class PS1{
    protected:
        int ts;
        int ms;
    public:
        void nhap(){
            cout<<"Nhap ts: ";cin>>ts;
            do{
                cout<<"Nhap ms: ";cin>>ms;
            }while (ms==0);
        }
        
        void in(){ 
            toigian();
            if (ms<0) {
                ts=-ts;
                ms=-ms;
            }
            cout<<ts<<"/"<<ms<<endl;
        }
        
        // Toi gian phan so
        void toigian(){
            // Tim ucln cua ts va ms
            int a=abs(ts), b=abs(ms);
            // Thuat toan oclid
            while (b!=0) 
            {
                int r=a%b; // Tim phan du a chia b
                a=b;
                b=r;
            }
            int uc=a; // ucln=a
            ts=ts/uc;
            ms=ms/uc;
        }
};

class PS2 : public PS1 {
public:
    // Nap chong toan tu gan (=)
    PS2& operator=(const PS2& right) {
        if (this != &right) {
            this->ts = right.ts;
            this->ms = right.ms;
        }
        return *this;
    }

    // Nap chong toan tu lon hon (>)
    bool operator>(const PS2& right) {
        // Ep kieu tu so va mau so sang float de so sanh gia tri
        return (float)this->ts / this->ms > (float)right.ts / right.ms;
    }
};

// ================= CAU 3 =================
int main()
{
    int n;
    
    // Nhap so luong phan tu (toi da 10)
    do {
        cout << "Nhap so luong phan so (1 - 10): ";
        cin >> n;
        if (n <= 0 || n > 10) {
            cout << "So luong khong hop le. Vui long nhap lai!\n";
        }
    } while (n <= 0 || n > 10);

    // Khai bao mang chua danh sach cac doi tuong PS2
    PS2 ds[10];

    // Nhap danh sach phan so
    cout << "\n--- NHAP DANH SACH PHAN SO ---\n";
    for (int i = 0; i < n; i++) {
        cout << "- Phan so thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sap xep lai danh sach da nhap theo trat tu giam dan
    // Thuat toan noi bot, su dung toan tu > va = da duoc nap chong o lop PS2
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) {
                PS2 temp;
                temp = ds[i];       
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // In danh sach sau khi sap xep
    cout << "\n--- DANH SACH PHAN SO GIAM DAN ---\n";
    for (int i = 0; i < n; i++) {
        ds[i].in();
    }

    return 0;
}
