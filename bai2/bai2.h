#include <bits/stdc++.h>
using namespace std;

class SoPhuc {
private:
    double dThuc, dAo;

public:
    // Constructor không đối số
    SoPhuc();

    // Constructor có đối số
    SoPhuc(double thuc, double ao);

    // Toán tử cộng
    SoPhuc operator+(const SoPhuc& sp) const;

    // Toán tử trừ
    SoPhuc operator-(const SoPhuc& sp) const;

    // Toán tử nhân
    SoPhuc operator*(const SoPhuc& sp) const;

    // Toán tử chia
    SoPhuc operator/(const SoPhuc& sp) const;

    // Toán tử so sánh bằng
    bool operator==(const SoPhuc& sp) const;

    // Toán tử so sánh khác
    bool operator!=(const SoPhuc& sp) const;

    // Toán tử nhập (>>)
    friend istream& operator>>(istream& is, SoPhuc& sp);

    // Toán tử xuất (<<)
    friend ostream& operator<<(ostream& os, const SoPhuc& sp);
};

