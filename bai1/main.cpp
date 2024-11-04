#include "bai1.h"

int main() {
    PhanSo ps1, ps2;

    // Nhập hai phân số
    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;

    cout << "Nhap phan so thu hai:\n";
    cin >> ps2;

    // Cộng hai phân số
    PhanSo tong = ps1 + ps2;
    cout << "Tong: " << tong << endl;

    // Trừ hai phân số
    PhanSo hieu = ps1 - ps2;
    cout << "Hieu: " << hieu << endl;

    // Nhân hai phân số
    PhanSo tich = ps1 * ps2;
    cout << "Tich: " << tich << endl;

    // Chia hai phân số
    PhanSo thuong = ps1 / ps2;
    cout << "Thuong: " << thuong << endl;

    // So sánh
    if(ps1 == ps2){
        cout << "Phan so 1 bang phan so 2" << endl;
    }
    else if (ps1 > ps2){
        cout << "Phan so 1 lon hon phan so 2" << endl;
    }
    else cout << "Phan so 1 be hon phan so 2" << endl;

    return 0;
}

