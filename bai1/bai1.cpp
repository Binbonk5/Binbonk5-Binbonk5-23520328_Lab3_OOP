#include "bai1.h"

// Hàm tìm UCLN
int PhanSo::gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Hàm rút gọn phân số
void PhanSo::rutgon() {
    int ucln = gcd(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
    if (iMau < 0) {  // Đưa mẫu số về dương
        iTu = -iTu;
        iMau = -iMau;
    }
}

// Constructor không đối số
PhanSo::PhanSo() {
    iTu = 0;
    iMau = 1;
}

// Constructor có đối số
PhanSo::PhanSo(int Tu, int Mau) {
    iTu = Tu;
    iMau = (Mau != 0) ? Mau : 1; // Kiểm tra mẫu khác 0
    rutgon();
}

// Toán tử cộng
PhanSo PhanSo::operator+(const PhanSo& ps) const {
    PhanSo result(iTu * ps.iMau + ps.iTu * iMau, iMau * ps.iMau);
    result.rutgon();
    return result;
}

// Toán tử trừ
PhanSo PhanSo::operator-(const PhanSo& ps) const {
    PhanSo result(iTu * ps.iMau - ps.iTu * iMau, iMau * ps.iMau);
    result.rutgon();
    return result;
}

// Toán tử nhân
PhanSo PhanSo::operator*(const PhanSo& ps) const {
    PhanSo result(iTu * ps.iTu, iMau * ps.iMau);
    result.rutgon();
    return result;
}

// Toán tử chia
PhanSo PhanSo::operator/(const PhanSo& ps) const {
    PhanSo result(iTu * ps.iMau, iMau * ps.iTu);
    result.rutgon();
    return result;
}

// Toán tử so sánh bằng
bool PhanSo::operator==(const PhanSo& ps) const {
    return (iTu == ps.iTu && iMau == ps.iMau);
}

// Toán tử so sánh khác
bool PhanSo::operator!=(const PhanSo& ps) const {
    return !(*this == ps);
}

// Toán tử lớn hơn hoặc bằng
bool PhanSo::operator>=(const PhanSo& ps) const {
    return (iTu * ps.iMau >= ps.iTu * iMau);
}

// Toán tử nhỏ hơn hoặc bằng
bool PhanSo::operator<=(const PhanSo& ps) const {
    return (iTu * ps.iMau <= ps.iTu * iMau);
}

// Toán tử lớn hơn
bool PhanSo::operator>(const PhanSo& ps) const {
    return (iTu * ps.iMau > ps.iTu * iMau);
}

// Toán tử nhỏ hơn
bool PhanSo::operator<(const PhanSo& ps) const {
    return (iTu * ps.iMau < ps.iTu * iMau);
}

// Toán tử nhập
istream& operator>>(istream& is, PhanSo& ps) {
    cout << "Nhap tu so: ";
    is >> ps.iTu;
    do {
        cout << "Nhap mau so (khac 0): ";
        is >> ps.iMau;
    } while (ps.iMau == 0);
    ps.rutgon();
    return is;
}

// Toán tử xuất
ostream& operator<<(ostream& os, const PhanSo& ps) {
    if (ps.iMau == 1) {
        os << ps.iTu;
    } else {
        os << ps.iTu << "/" << ps.iMau;
    }
    return os;
}
