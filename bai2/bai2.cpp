#include "bai2.h"

// Constructor không đối số
SoPhuc::SoPhuc() {
    dThuc = 0;
    dAo = 0;
}

// Constructor có đối số
SoPhuc::SoPhuc(double thuc, double ao) {
    dThuc = thuc;
    dAo = ao;
}

// Toán tử cộng
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const {
    return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo);
}

// Toán tử trừ
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const {
    return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo);
}

// Toán tử nhân
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const {
    return SoPhuc(dThuc * sp.dThuc - dAo * sp.dAo, dThuc * sp.dAo + dAo * sp.dThuc);
}

// Toán tử chia
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const {
    double mau = sp.dThuc * sp.dThuc + sp.dAo * sp.dAo;
    return SoPhuc((dThuc * sp.dThuc + dAo * sp.dAo) / mau, (dAo * sp.dThuc - dThuc * sp.dAo) / mau);
}

// Toán tử so sánh bằng
bool SoPhuc::operator==(const SoPhuc& sp) const {
    return (dThuc == sp.dThuc && dAo == sp.dAo);
}

// Toán tử so sánh khác
bool SoPhuc::operator!=(const SoPhuc& sp) const {
    return !(*this == sp);
}

// Toán tử nhập
istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.dThuc;
    cout << "Nhap phan ao: ";
    is >> sp.dAo;
    return is;
}

// Toán tử xuất
ostream& operator<<(ostream& os, const SoPhuc& sp) {
    os << sp.dThuc << " + " << sp.dAo << "i";
    return os;
}

