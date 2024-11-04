#include <iostream>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

    bool isLeapYear(int year) const; // Kiểm tra năm nhuận
    int daysInMonth(int month, int year) const; // Số ngày trong tháng

public:
    NgayThangNam(); // Constructor không đối số
    NgayThangNam(int Nam, int Thang, int Ngay); // Constructor có đối số

    int TinhNgay() const; // Tính số ngày từ 1/1/0000

    // Toán tử
    NgayThangNam operator+(int ngay) const; // Cộng số ngày
    NgayThangNam operator-(int ngay) const; // Trừ số ngày
    int operator-(const NgayThangNam& a) const; // Trừ ngày tháng năm khác
    NgayThangNam operator++(); // Tăng ngày
    NgayThangNam operator--(); // Giảm ngày
    bool operator==(const NgayThangNam& a) const; // So sánh bằng
    bool operator!=(const NgayThangNam& a) const; // So sánh khác
    bool operator>=(const NgayThangNam& a) const; // So sánh lớn hơn hoặc bằng
    bool operator<=(const NgayThangNam& a) const; // So sánh nhỏ hơn hoặc bằng
    bool operator>(const NgayThangNam& a) const; // So sánh lớn hơn
    bool operator<(const NgayThangNam& a) const; // So sánh nhỏ hơn

    // Nhập xuất
    friend std::istream& operator>>(std::istream& is, NgayThangNam& date);
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& date);
};

