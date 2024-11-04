#include "bai4.h"

// Constructor không đối số
NgayThangNam::NgayThangNam() : iNam(0), iThang(1), iNgay(1) {}

// Constructor có đối số
NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) : iNam(Nam), iThang(Thang), iNgay(Ngay) {
    if (Thang < 1 || Thang > 12 || Ngay < 1 || Ngay > daysInMonth(Thang, Nam)) {
        // Đặt về ngày 1 tháng 1 năm 0 nếu không hợp lệ
        iNam = 0;
        iThang = 1;
        iNgay = 1;
    }
}

// Kiểm tra năm nhuận
bool NgayThangNam::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Số ngày trong tháng
int NgayThangNam::daysInMonth(int month, int year) const {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

// Tính số ngày từ 1/1/0000
int NgayThangNam::TinhNgay() const {
    int days = 0;
    for (int year = 0; year < iNam; ++year) {
        days += isLeapYear(year) ? 366 : 365;
    }
    for (int month = 1; month < iThang; ++month) {
        days += daysInMonth(month, iNam);
    }
    days += iNgay - 1; // Trừ đi 1 để tính từ 1/1
    return days;
}

// Toán tử cộng với số ngày
NgayThangNam NgayThangNam::operator+(int ngay) const {
    NgayThangNam result = *this;
    result.iNgay += ngay;

    while (result.iNgay > result.daysInMonth(result.iThang, result.iNam)) {
        result.iNgay -= result.daysInMonth(result.iThang, result.iNam);
        result.iThang++;
        if (result.iThang > 12) {
            result.iThang = 1;
            result.iNam++;
        }
    }

    return result;
}

// Toán tử trừ với số ngày
NgayThangNam NgayThangNam::operator-(int ngay) const {
    NgayThangNam result = *this;
    result.iNgay -= ngay;

    while (result.iNgay <= 0) {
        result.iThang--;
        if (result.iThang < 1) {
            result.iThang = 12;
            result.iNam--;
        }
        result.iNgay += result.daysInMonth(result.iThang, result.iNam);
    }

    return result;
}

// Toán tử trừ giữa hai ngày
int NgayThangNam::operator-(const NgayThangNam& a) const {
    return abs(TinhNgay() - a.TinhNgay());
}

// Toán tử tăng
NgayThangNam NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

// Toán tử giảm
NgayThangNam NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

// Toán tử so sánh bằng
bool NgayThangNam::operator==(const NgayThangNam& a) const {
    return (iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam);
}

// Toán tử so sánh khác
bool NgayThangNam::operator!=(const NgayThangNam& a) const {
    return !(*this == a);
}

// Toán tử so sánh lớn hơn hoặc bằng
bool NgayThangNam::operator>=(const NgayThangNam& a) const {
    return TinhNgay() >= a.TinhNgay();
}

// Toán tử so sánh nhỏ hơn hoặc bằng
bool NgayThangNam::operator<=(const NgayThangNam& a) const {
    return TinhNgay() <= a.TinhNgay();
}

// Toán tử so sánh lớn hơn
bool NgayThangNam::operator>(const NgayThangNam& a) const {
    return TinhNgay() > a.TinhNgay();
}

// Toán tử so sánh nhỏ hơn
bool NgayThangNam::operator<(const NgayThangNam& a) const {
    return TinhNgay() < a.TinhNgay();
}

// Toán tử nhập
std::istream& operator>>(std::istream& is, NgayThangNam& date) {
    std::cout << "Nhap ngay: ";
    is >> date.iNgay;
    std::cout << "Nhap thang: ";
    is >> date.iThang;
    std::cout << "Nhap nam: ";
    is >> date.iNam;
    return is;
}

// Toán tử xuất
std::ostream& operator<<(std::ostream& os, const NgayThangNam& date) {
    os << date.iNgay << "/" << date.iThang << "/" << date.iNam;
    return os;
}

