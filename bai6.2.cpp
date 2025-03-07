#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct hocSinh{
    string hoTen;
    float toan, van, nn;
};
//hàm kiểm tra điều kiện của tên 
bool isValidName(string name) {
    // Kiểm tra độ dài (tối thiểu 2, tối đa 50 ký tự)
    if (name.length() < 2 || name.length() > 50) {
        return false;
    }

    // Kiểm tra từng ký tự trong chuỗi
    for (char c : name) {
        if (!isalpha(c) && c != ' ') { // Phải là chữ cái hoặc khoảng trắng
            return false;
        }
    }

    return true;
}
//input: một học sinh 
//output: các thông tin của học sinh (thông tin phải thỏa điều kiện đề bài)
void Nhap(hocSinh &hs) {
    while (true) { // Lặp vô hạn đến khi nhập đúng
        cin.ignore(); // Xóa bộ đệm trước khi nhập chuỗi
        cout << "Nhap ho ten: ";
        getline(cin, hs.hoTen);

        cout << "Nhap diem toan: ";
        cin >> hs.toan;

        cout << "Nhap diem van: ";
        cin >> hs.van;

        cout << "Nhap diem ngoai ngu: ";
        cin >> hs.nn;

        // Kiểm tra điều kiện nhập
        if (isValidName(hs.hoTen) && hs.toan >= 0 && hs.toan <= 10 &&
            hs.van >= 0 && hs.van <= 10 && hs.nn >= 0 && hs.nn <= 10) {
            break; // Thoát khỏi vòng lặp nếu nhập đúng
        }

        cout << "Thong tin khong hop le, vui long nhap lai!\n";
        cin.clear(); // Xóa lỗi nhập (nếu có)
        cin.ignore(1000, '\n'); // Loại bỏ dữ liệu sai còn lại trong bộ đệm
    }
}

//hàm tính điểm trung bình của học sinh dựa theo công thức
float diemTrungBinh(hocSinh hs){
    return ( (2*hs.toan) + hs.van + hs.nn) / 4;
}
//hàm phân loại học sinh dựa trên điểm trung bình
string xepLoai(hocSinh hs){
    if(diemTrungBinh(hs)>=9){
        return "Xuat sac";
    }else if(diemTrungBinh(hs)>=8){
        return "Gioi";
    }else if(diemTrungBinh(hs)>=6.5){
        return "Kha";
    }else if(diemTrungBinh(hs)>=5){
        return "Trung binh";
    }else{
        return "Yeu";
    }
}
// hàm tìm học sinh có điểm trung bình lớn nhất
//intput: mảng các học sinh
//output: học sinh có điểm trung bình lớn nhất 

vector<hocSinh> timMax(hocSinh hs[], int n){
    vector<hocSinh>v;
    float dtbMax = diemTrungBinh(hs[0]);
    for(int i=1;i<n;i++){
        if(diemTrungBinh(hs[i])>dtbMax){
            dtbMax = diemTrungBinh(hs[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(diemTrungBinh(hs[i])==dtbMax){
            v.push_back(hs[i]);
        }
    }
    return v;
    
    
}
//viêt hàm chuyển các kí tự về dạng in thường để tiện so sánh tên
void chuyen(string& s){
    for(int i=0;i<s.size();i++){
        s[i] = tolower(s[i]);
    }

}
//viết hàm tìm kiếm học sinh theo tên 
//input:nhập vào một tên cần tìm
//output: các học sinh có tên giống tên cần tìm

vector<hocSinh> timKiem(hocSinh hs[], int n){
    cout << "Nhap vao ten hoc sinh can tim: ";
    vector<hocSinh> v;
    cin.ignore();
    string s;
    getline(cin, s);

    chuyen(s); // Chuyển tên cần tìm về chữ thường

    for (int i = 0; i < n; i++) {
        string temp = hs[i].hoTen; // Lưu tên gốc
        chuyen(temp); // Chuyển tên sang chữ thường

        if (temp.find(s) != string::npos) { // Tìm kiếm đúng cách
            v.push_back(hs[i]);
        }
    }
    return v;
}
//viết hàm tìm kiếm các học sinh có điểm toán thấp nhất
vector<hocSinh> toanMin(hocSinh hs[], int n){
    int ans = hs[0].toan;
    for(int i=1;i<n;i++){
        if(hs[i].toan<ans){
            ans = hs[i].toan;
        }
    }
    vector<hocSinh>v;
    for(int i=0;i<n;i++){
        if(hs[i].toan==ans){
            v.push_back(hs[i]);
        }
    }
    return v;
}
int main(){
   int n;
   hocSinh hs[100];
   cout<<"Nhap vao so luong hoc sinh: ";
   cin>>n;
   for(int i=0;i<n;i++){
    cout<<"Nhap vao thong tin hoc sinh thu "<<i+1<<endl;
    Nhap(hs[i]);
   }
   cout<<"Diem trung binh va phan loai cua tung hoc sinh: "<<endl;
   for(int i=0;i<n;i++){
    cout<<hs[i].hoTen<<": "<<diemTrungBinh(hs[i])<<" - "<<xepLoai(hs[i])<<endl;
   }
   cout<<"Hoc sinh co diem trung binh cao nhat la: "<<endl;
   vector<hocSinh>diemMax;
   diemMax = timMax(hs,n);
   for(hocSinh x:diemMax){
        cout<<x.hoTen;
   }
   cout<<endl;
   //tìm kiếm học sinh theo tên
   
   vector<hocSinh>ten = timKiem(hs,n);
   cout<<"Nhung hoc sinh co ten can tim: "<<endl;
   for(hocSinh x:ten){
    cout<<x.hoTen<<" ";
   }
   cout<<endl;
   cout<<"Danh sach hoc sinh co diem toan thap nhat: "<<endl;
   vector<hocSinh>minToan = toanMin(hs,n);
   for(hocSinh x:minToan){
    cout<<x.hoTen<<endl;
   }
   cout<<endl;

}