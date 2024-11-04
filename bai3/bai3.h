#include <iostream>
using namespace std;

class ThoiGian {
private:
    int iGio, iPhut, iGiay;

    // Hàm điều chỉnh lại giờ, phút, giây
    void normalize();

public:
    // Constructor không đối số
    ThoiGian();

    // Constructor có đối số
    ThoiGian(int Gio, int Phut, int Giay);

    // Tính tổng số giây
    int TinhGiay() const;

    // Tính lại giờ từ giây
    void TinhLaiGio(int Giay);

    // Toán tử cộng với số giây
    ThoiGian operator+(int Giay) const;

    // Toán tử trừ với số giây
    ThoiGian operator-(int Giay) const;

    // Toán tử cộng với thời gian
    ThoiGian operator+(const ThoiGian& a) const;

    // Toán tử trừ với thời gian
    ThoiGian operator-(const ThoiGian& a) const;

    // Toán tử tăng
    ThoiGian operator++();

    // Toán tử giảm
    ThoiGian operator--();

    // Toán tử so sánh bằng
    bool operator==(const ThoiGian& a) const;

    // Toán tử so sánh khác
    bool operator!=(const ThoiGian& a) const;

    // Toán tử so sánh lớn hơn hoặc bằng
    bool operator>=(const ThoiGian& a) const;

    // Toán tử so sánh nhỏ hơn hoặc bằng
    bool operator<=(const ThoiGian& a) const;

    // Toán tử so sánh lớn hơn
    bool operator>(const ThoiGian& a) const;

    // Toán tử so sánh nhỏ hơn
    bool operator<(const ThoiGian& a) const;

    // Toán tử nhập (>>)
    friend istream& operator>>(istream& is, ThoiGian& tg);

    // Toán tử xuất (<<)
    friend ostream& operator<<(ostream& os, const ThoiGian& tg);
};


