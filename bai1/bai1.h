#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;

    // Phương thức rút gọn phân số (tối giản)
    int gcd(int a, int b);
    void rutgon();

public:
    // Constructor không đối số
    PhanSo();

    // Constructor có đối số
    PhanSo(int Tu, int Mau);

    // Toán tử cộng
    PhanSo operator+(const PhanSo& ps) const;

    // Toán tử trừ
    PhanSo operator-(const PhanSo& ps) const;

    // Toán tử nhân
    PhanSo operator*(const PhanSo& ps) const;

    // Toán tử chia
    PhanSo operator/(const PhanSo& ps) const;

    // Toán tử so sánh bằng
    bool operator==(const PhanSo& ps) const;

    // Toán tử so sánh khác
    bool operator!=(const PhanSo& ps) const;

    // Toán tử lớn hơn hoặc bằng
    bool operator>=(const PhanSo& ps) const;

    // Toán tử nhỏ hơn hoặc bằng
    bool operator<=(const PhanSo& ps) const;

    // Toán tử lớn hơn
    bool operator>(const PhanSo& ps) const;

    // Toán tử nhỏ hơn
    bool operator<(const PhanSo& ps) const;

    // Toán tử nhập (>>)
    friend istream& operator>>(istream& is, PhanSo& ps);

    // Toán tử xuất (<<)
    friend ostream& operator<<(ostream& os, const PhanSo& ps);
};

