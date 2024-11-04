#include "bai4.h"
using namespace std;

int main() {
    NgayThangNam date1, date2;

    cout << "Nhap ngay thang nam 1: " << endl;
    cin >> date1;

    int ngay;
    cout << "Nhap so ngay cong: ";
    cin >> ngay;

    NgayThangNam datecong = date1 + ngay;
    cout << "Ngay thang nam 1 sau khi tang " << ngay << " la: " << datecong << endl;

    cout << "Nhap so ngay tru: ";
    cin >> ngay;
    NgayThangNam datetru = date1 - ngay;
    cout << "Ngay thang nam 1 sau khi giam " << ngay << " la: " << datetru << endl;

    cout << "Nhap ngay thang nam 2: " << endl;
    cin >> date2;

    cout << "Chenh lech cua ngay thang nam 1 va ngay thang nam 2 la: " << date1 - date2 << " ngay" << endl;

    // so sanh
    if(date1 > date2){
        cout << "Ngay thang nam 1 lon hon ngay thang nam 2" << endl;
    }
    else if(date1 < date2){
        cout << "Ngay thang nam 1 be hon ngay thang nam 2" << endl;
    }
    else cout << "Ngay thang nam 1 bang ngay thang nam 2" << endl;

    ++date1;
    cout << "Ngay thang nam 1 sau khi tang 1 ngay la " << date1 << endl;

    --date1;
    --date1;
    cout << "Ngay thang nam 1 sau khi giam 1 ngay la " << date1 << endl;

    return 0;
}

