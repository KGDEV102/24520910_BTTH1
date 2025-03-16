#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

struct hocSinh {
    string hoTen;
    float toan, van, nn;
};

// Kiểm tra tên hợp lệ
bool isValidName(string name) {
    if (name.length() < 2 || name.length() > 50) return false;
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

// Hàm nhập học sinh
void Nhap(hocSinh &hs) {
    while (true) {
        cout << "Nhap ho ten: ";
        getline(cin, hs.hoTen);

        cout << "Nhap diem toan: ";
        cin >> hs.toan;

        cout << "Nhap diem van: ";
        cin >> hs.van;

        cout << "Nhap diem ngoai ngu: ";
        cin >> hs.nn;

        if (isValidName(hs.hoTen) && hs.toan >= 0 && hs.toan <= 10 &&
            hs.van >= 0 && hs.van <= 10 && hs.nn >= 0 && hs.nn <= 10) {
            cin.ignore(); // Xóa bộ đệm trước khi nhập tiếp
            break;
        }

        cout << "Thong tin khong hop le, vui long nhap lai!\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// Tính điểm trung bình
float diemTrungBinh(hocSinh hs) {
    return ( (2*hs.toan) + hs.van + hs.nn) / 4;
}

// Xếp loại học sinh
string xepLoai(hocSinh hs) {
    float dtb = diemTrungBinh(hs);
    if (dtb >= 9) return "Xuat sac";
    if (dtb >= 8) return "Gioi";
    if (dtb >= 6.5) return "Kha";
    if (dtb >= 5) return "Trung binh";
    return "Yeu";
}

// Tìm học sinh có điểm TB cao nhất
vector<hocSinh> timMax(hocSinh hs[], int n) {
    vector<hocSinh> v;
    float dtbMax = diemTrungBinh(hs[0]);

    for (int i = 0; i < n; i++) {
        float dtb = diemTrungBinh(hs[i]);
        if (dtb > dtbMax) {
            dtbMax = dtb;
            v.clear();
        }
        if (dtb == dtbMax) {
            v.push_back(hs[i]);
        }
    }
    return v;
}

// Chuyển toàn bộ chuỗi thành chữ thường
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Hàm tìm kiếm học sinh theo từ khóa (không phân biệt hoa thường)
vector<hocSinh> timKiem(hocSinh hs[], int n, string keyword) {
    vector<hocSinh> result;
    keyword = toLower(keyword);  // Chuyển từ khóa về chữ thường

    for (int i = 0; i < n; i++) {
        string hoTenLower = toLower(hs[i].hoTen); // Chuyển họ tên về chữ thường

        // Kiểm tra nếu từ khóa xuất hiện trong họ tên
        if (hoTenLower.find(keyword) != string::npos) {
            result.push_back(hs[i]);
        }
    }
    return result;
}


// Tìm học sinh có điểm Toán thấp nhất
vector<hocSinh> toanMin(hocSinh hs[], int n) {
    vector<hocSinh> v;
    float minToan = hs[0].toan;

    for (int i = 0; i < n; i++) {
        if (hs[i].toan < minToan) {
            minToan = hs[i].toan;
            v.clear();
        }
        if (hs[i].toan == minToan) {
            v.push_back(hs[i]);
        }
    }
    return v;
}

int main() {
    int n;
    hocSinh hs[100];
    cout << "Nhap vao so luong hoc sinh: ";
    cin >> n;
    cin.ignore(); // Xóa bộ đệm trước khi nhập chuỗi đầu tiên

    for (int i = 0; i < n; i++) {
        cout << "Nhap vao thong tin hoc sinh thu " << i + 1 << endl;
        Nhap(hs[i]);
    }

    cout << "Diem trung binh va phan loai cua tung hoc sinh:\n";
    for (int i = 0; i < n; i++) {
        cout << hs[i].hoTen << ": " << diemTrungBinh(hs[i]) << " - " << xepLoai(hs[i]) << endl;
    }

    cout << "Hoc sinh co diem trung binh cao nhat:\n";
    for (hocSinh x : timMax(hs, n)) {
        cout << x.hoTen << endl;
    }

    cout << "\nNhap hoc sinh tim kiem: ";
    string keyword;
    getline(cin, keyword);

    vector<hocSinh> ketQua = timKiem(hs, n, keyword);

    if (ketQua.empty()) {
        cout << "Khong tim thay hoc sinh nao!\n";
    } else {
        cout << "Nhung hoc sinh tim thay:\n";
        for (hocSinh x : ketQua) {
            cout << x.hoTen << endl;
        }
    }


    cout << "Danh sach hoc sinh co diem toan thap nhat:\n";
    for (hocSinh x : toanMin(hs, n)) {
        cout << x.hoTen << endl;
    }
}
