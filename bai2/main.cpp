#include "bai2.h"

int main() {
    SoPhuc sp1, sp2;

    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;

    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;

    // Cộng hai số phức
    SoPhuc tong = sp1 + sp2;
    cout << "Tong: " << tong << endl;

    // Trừ hai số phức
    SoPhuc hieu = sp1 - sp2;
    cout << "Hieu: " << hieu << endl;

    // Nhân hai số phức
    SoPhuc tich = sp1 * sp2;
    cout << "Tich: " << tich << endl;

    // Chia hai số phức
    SoPhuc thuong = sp1 / sp2;
    cout << "Thuong: " << thuong << endl;

    // So sánh
     if(sp1 == sp2){
        cout << "So phuc 1 bang so phuc 2" << endl;
    }
    else {
        cout << "So phuc 1 khac so phuc 2" << endl;
    }


    return 0;
}
