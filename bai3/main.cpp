#include "bai3.h"

int main() {
    ThoiGian tg1, tg2;

    cout << "Nhap thoi gian thu nhat:\n";
    cin >> tg1;

    cout << "Nhap thoi gian thu hai:\n";
    cin >> tg2;

    // Cộng hai thời gian
    ThoiGian tong = tg1 + tg2;
    cout << "Tong: " << tong << endl;

    // Trừ hai thời gian
    ThoiGian hieu = tg1 - tg2;

    cout << "Hieu: " << hieu << endl;

    // Cộng giây vào thời gian
    int giayCong;
    cout << "Nhap so giay de cong: ";
    cin >> giayCong;
    ThoiGian tgCong1 = tg1 + giayCong;
    cout << "Thoi gian 1 sau khi cong " << giayCong << " giay: " << tgCong1 << endl;

    ThoiGian tgCong2 = tg2 + giayCong;
    cout << "Thoi gian 2 sau khi cong " << giayCong << " giay: " << tgCong2 << endl;

    // Trừ giây khỏi thời gian
    int giayTru;
    cout << "Nhap so giay de tru: ";
    cin >> giayTru;
    ThoiGian tgTru1 = tg1 - giayTru;
    cout << "Thoi gian 1 sau khi tru " << giayTru << " giay: " << tgTru1 << endl;

    ThoiGian tgTru2 = tg2 - giayTru;
    cout << "Thoi gian 2 sau khi tru " << giayTru << " giay: " << tgTru2 << endl;


    // So sánh
    cout << "Thoi gian 1 " << (tg1 == tg2 ? "bang" : "khac") << " thoi gian 2" << endl;

    return 0;
}
