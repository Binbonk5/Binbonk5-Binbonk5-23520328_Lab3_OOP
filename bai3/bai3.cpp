#include "bai3.h"

// Constructor không đối số
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

// Constructor có đối số
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    normalize();
}

// Hàm điều chỉnh lại giờ, phút, giây
void ThoiGian::normalize() {
    if (iGiay >= 60) {
        iPhut += iGiay / 60;
        iGiay %= 60;
    }
    if (iPhut >= 60) {
        iGio += iPhut / 60;
        iPhut %= 60;
    }
    if (iGio < 0) {
        iGio = 0;
        iPhut = 0;
        iGiay = 0;
    }
}

// Tính tổng số giây
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Tính lại giờ từ giây
void ThoiGian::TinhLaiGio(int Giay) {
    iGiay += Giay;
    normalize();
}

// Toán tử cộng với số giây
ThoiGian ThoiGian::operator+(int Giay) const {
    ThoiGian result = *this;
    result.TinhLaiGio(Giay);
    return result;
}

// Toán tử trừ với số giây
ThoiGian ThoiGian::operator-(int Giay) const {
    ThoiGian result = *this; // Sao chép đối tượng hiện tại

    result.iGiay -= Giay; // Trừ giây
    while (result.iGiay < 0) { // Nếu giây âm
        result.iGiay += 60; // Thêm 60 giây
        result.iPhut--; // Giảm phút
        if (result.iPhut < 0) { // Nếu phút âm
            result.iPhut += 60; // Thêm 60 phút
            result.iGio--; // Giảm giờ
            if (result.iGio < 0) { // Nếu giờ âm
                result.iGio = 0; // Đặt giờ về 0
                result.iPhut = 0; // Đặt phút về 0
                result.iGiay = 0; // Đặt giây về 0
                break; // Kết thúc
            }
        }
    }
    result.normalize();

    return result;
}
// Toán tử cộng với thời gian
ThoiGian ThoiGian::operator+(const ThoiGian& a) const {
    return ThoiGian(iGio + a.iGio, iPhut + a.iPhut, iGiay + a.iGiay);
}

// Toán tử trừ với thời gian
ThoiGian ThoiGian::operator-(const ThoiGian& a) const {
    int giay1 = iGio * 3600 + iPhut * 60 + iGiay;
    int giay2 = a.iGio * 3600 + a.iPhut * 60 + a.iGiay;
    int result = giay1 - giay2;
    int gio = result / 3600;
    int phut = (result - gio * 3600) / 60;
    int giay = result - gio * 3600 - phut * 60;
    return ThoiGian(gio, phut , giay);
}

// Toán tử tăng
ThoiGian ThoiGian::operator++() {
    TinhLaiGio(1);
    return *this;
}

// Toán tử giảm
ThoiGian ThoiGian::operator--() {
    TinhLaiGio(-1);
    return *this;
}

// Toán tử so sánh bằng
bool ThoiGian::operator==(const ThoiGian& a) const {
    return (iGio == a.iGio && iPhut == a.iPhut && iGiay == a.iGiay);
}

// Toán tử so sánh khác
bool ThoiGian::operator!=(const ThoiGian& a) const {
    return !(*this == a);
}

// Toán tử so sánh lớn hơn hoặc bằng
bool ThoiGian::operator>=(const ThoiGian& a) const {
    return TinhGiay() >= a.TinhGiay();
}

// Toán tử so sánh nhỏ hơn hoặc bằng
bool ThoiGian::operator<=(const ThoiGian& a) const {
    return TinhGiay() <= a.TinhGiay();
}

// Toán tử so sánh lớn hơn
bool ThoiGian::operator>(const ThoiGian& a) const {
    return TinhGiay() > a.TinhGiay();
}

// Toán tử so sánh nhỏ hơn
bool ThoiGian::operator<(const ThoiGian& a) const {
    return TinhGiay() < a.TinhGiay();
}

// Toán tử nhập
istream& operator>>(istream& is, ThoiGian& tg) {
    cout << "Nhap gio: ";
    is >> tg.iGio;
    cout << "Nhap phut: ";
    is >> tg.iPhut;
    cout << "Nhap giay: ";
    is >> tg.iGiay;
    tg.normalize(); // Đảm bảo thời gian hợp lệ
    return is;
}

// Toán tử xuất
ostream& operator<<(ostream& os, const ThoiGian& tg) {
    os << tg.iGio << " gio " << tg.iPhut << " phut " << tg.iGiay << " giay";
    return os;
}

