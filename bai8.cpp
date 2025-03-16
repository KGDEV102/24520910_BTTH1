#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;
struct date{
    int ngay, thang, nam;
};
struct soTietKiem{
    string ma;
    string loai;
    string hoTen;
    long long cmnd;
    date ngay;
    float soTien;
};
//hàm kiểm tra mã sổ 
bool isMa(string ma){
    if(ma.size()>5) return false;
    for(char c: ma){
        if(!isalpha(c) && !isdigit(c)){
            return false;
        }
    }
    return true;
}
//hàm kiểm tra CMND có hợp lệ hay không
bool iscmnd(long long cmnd){
    int cnt =0;
    while(cmnd!=0){
        ++cnt;
        cmnd/=10;
    }
    if(cnt==9 || cnt ==12){
        return true;
    }
    return false;
}
// các hàm hỗ trợ kiểm tra ngày hợp lệ 
int ngayOfthang(int thang, int nam){
    switch(thang){
        case 1: case 3: case 5: case 7: case 8: case 10 : case 12:
            return 31;
        case 4: case 6: case 9: case 11: 
            return 30;
        case 2:
            if(nam%400==0 || (nam%4==0 && nam%100!=0)){
                return 29;
            }else{
                return 28;
            }
    }
}
void nhapDate(date& N){
    cout<<"Nhap vao ngay: ";
    cin>>N.ngay;
    cout<<"Nhap vao thang: ";
    cin>>N.thang;
    cout<<"Nhap vao nam: ";
    cin>>N.nam;
   
}
bool isDate(date N){
    if(N.ngay<=0 || N.ngay>ngayOfthang(N.thang,N.nam) || N.thang<=0 || N.thang > 12 || N.nam <=0){
        return false;
    }
    return true;
}
// hàm nhập dữ liệu cho sổ tiết kiệm
void nhap(soTietKiem& X) {
    // Nhập mã sổ (không quá 5 ký tự, chỉ chứa chữ & số)
    while (true) {
        cout << "Nhap vao ma so (toi da 5 ky tu, chi chua chu va so): ";
        cin >> X.ma;
        if (isMa(X.ma)) break;
        cout << "Loi: Ma so khong hop le! Nhap lai.\n";
    }
    cin.ignore(); // Xóa bộ nhớ đệm

    // Nhập loại tiết kiệm
    cout << "Nhap vao loai tiet kiem: ";
    getline(cin, X.loai);

    // Nhập họ tên khách hàng
    cout << "Nhap vao ho ten khach hang: ";
    getline(cin, X.hoTen);

    // Nhập CMND (phải là số, đúng 9 hoặc 12 chữ số)
    while (true) {
        cout << "Nhap vao CMND (9 hoac 12 chu so): ";
        cin >> X.cmnd;

        if (cin.fail()) {
            cin.clear(); // Xóa lỗi nhập
            cin.ignore(1000, '\n'); // Xóa bộ nhớ đệm
            cout << "Loi: CMND phai la so! Nhap lai.\n";
            continue;
        }
        if (iscmnd(X.cmnd)) break;
        cout << "Loi: CMND khong hop le! Nhap lai.\n";
    }

    // Nhập ngày mở sổ (đảm bảo ngày hợp lệ)
    while (true) {
        cout << "Nhap vao ngay mo so:\n";
        nhapDate(X.ngay);
        if (isDate(X.ngay)) break;
        cout << "Loi: Ngay khong hop le! Nhap lai.\n";
    }

    // Nhập số tiền gửi (phải là số dương)
    while (true) {
        cout << "Nhap vao so tien: ";
        cin >> X.soTien;

        if (cin.fail() || X.soTien <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Loi: So tien phai la so duong! Nhap lai.\n";
            continue;
        }
        break;
    }
}

void Xuat(soTietKiem X){
    cout<<"Ma so: "<<X.ma<<endl;
    cout<<"Loai tiet kiem: "<<X.loai<<endl;
    cout<<"Ho ten khach hang: "<<X.hoTen<<endl;
    cout<<"CMND: "<<X.cmnd<<endl;
    cout<<"Ngay mo so: "<<X.ngay.ngay<<"/"<<X.ngay.thang<<"/"<<X.ngay.nam<<endl;
    cout<<"So tien gui: "<<fixed << setprecision(0) << X.soTien << defaultfloat << endl;
}
//hàm tìm kiếm theo CMND
vector<soTietKiem> tim1(soTietKiem X[],int n, int cmnd){
    vector<soTietKiem>v;
    for(int i=0;i<n;i++){
        if(X[i].cmnd == cmnd){
            v.push_back(X[i]);
        }
    }
    return v;
}
// hàm tìm kiếm theo mã sổ 
vector<soTietKiem> tim2(soTietKiem X[],int n, string ma){
    vector<soTietKiem>v;
    for(int i=0;i<n;i++){
        if(X[i].ma == ma){
            v.push_back(X[i]);
        }
    }
    return v;
}
// hàm tìm kiếm các sổ tiết kiệm mở trong một thời gian xác định
vector<soTietKiem> tim3(soTietKiem X[],int n, date ngay){
    vector<soTietKiem>v;
    for(int i=0;i<n;i++){
        if(X[i].ngay.nam == ngay.nam && X[i].ngay.thang == ngay.thang && X[i].ngay.ngay == ngay.ngay){
            v.push_back(X[i]);
        }
    }
    return v;
}
// hàm sắp xếp các sổ tiết kiệm theo số tiền giảm dần
void sapXep1(soTietKiem X[], int n){
    for(int i=0;i<n;i++){
        int max_index = i;
        for(int j=i+1;j<n;j++){
            if(X[j].soTien>X[max_index].soTien){
                max_index = j;
            }
        }
        swap(X[i],X[max_index]);
    }
}
// hàm sắp xếp danh sách theo ngày mở sổ tăng dần 
void sapXep2(soTietKiem X[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (X[j].ngay.nam < X[i].ngay.nam) {
                swap(X[i], X[j]);
            } else if (X[j].ngay.nam == X[i].ngay.nam && X[j].ngay.thang < X[i].ngay.thang) {
                swap(X[i], X[j]);
            } else if (X[j].ngay.nam == X[i].ngay.nam && X[j].ngay.thang == X[i].ngay.thang && X[j].ngay.ngay < X[i].ngay.ngay) {
                swap(X[i], X[j]);
            }
        }
    }
}
void nhaplaisuat (double &a){
    cout << "Moi ban nhap lai suat moi: ";
    cin >> a;
    while (a < 0){
        cout << "Moi ban nhap lai: ";
        cin >> a;
    }
}
void tinhlaisuat (vector<soTietKiem>v, int n, double laixuat){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date today;
    today.thang = 1 + ltm->tm_mon;
    today.nam = 1900 + ltm->tm_year;
    for (int i=0; i<n ; ++i){
        if (v[i].loai == "dai han"){
            int month = today.nam*12 + today.thang - v[i].ngay.nam*12 - v[i].ngay.thang;
            double tienlai = v[i].soTien * pow(1 + laixuat, month/12);
            cout << "Tien lai ma " << v[i].hoTen << " nhan duoc: " << fixed << setprecision(0) << tienlai << defaultfloat << endl;
        }
        else{
            int month = today.nam*12 + today.thang - v[i].ngay.nam*12 - v[i].ngay.thang;
            double tienlai = v[i].soTien * laixuat * month/12;
            cout << "Tien lai ma " << v[i].hoTen << " nhan duoc: " << fixed << setprecision(0) << tienlai << defaultfloat << endl;
        }
    }
    cout << '\n';
}

void ruttien(vector<soTietKiem> &v, int n) {
    cout << "Vui long chon phuong thuc rut tien:\n";
    cout << "1. Rut mot phan.\n";
    cout << "2. Rut toan bo.\n";
    int chon;
    cin >> chon;

    cout << "-------------------------DANH SACH SO TIET KIEM--------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". ";
        Xuat(v[i]);
    }

    cout << "\nMoi ban chon so thu tu cua so tiet kiem: ";
    int chon1;
    cin >> chon1;

    if (chon1 < 1 || chon1 > n) {
        cout << "Loi: So thu tu khong hop le!\n";
        return;
    }

    soTietKiem &stk = v[chon1 - 1]; // Truy cập sổ tiết kiệm được chọn

    // Lấy ngày hiện tại
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date today;
    today.thang = 1 + ltm->tm_mon;
    today.nam = 1900 + ltm->tm_year;

    if (chon == 2) { // Rút toàn bộ tiền
        stk.soTien = 0;
        cout << "\n--- Da rut toan bo tien thanh cong! ---\n";
        return;
    }

    // Kiểm tra rút trước hạn
    double year = (today.nam * 12 + today.thang - stk.ngay.nam * 12 - stk.ngay.thang) / 12.0;
    if (floor(year) != year) {
        cout << "\n--------- Canh bao: Ban dang rut tien truoc han ---------\n";
        cout << "Ban co muon tiep tuc (1: Co, 2: Khong)? ";
        int xacNhan;
        cin >> xacNhan;
        if (xacNhan != 1) {
            cout << "Giao dich bi huy.\n";
            return;
        }
    }

    // Nhập số tiền muốn rút
    cout << "\nNhap so tien can rut: ";
    double money;
    cin >> money;

    while (money > stk.soTien || money <= 0) {
        cout << "So tien khong hop le, vui long nhap lai: ";
        cin >> money;
    }

    stk.soTien -= money;
    cout << "\n--- Da rut tien thanh cong! ---\n";
}





int main(){
    int n;
    cout<<"Nhap vao so luong so tiet kiem: ";
    cin>>n;
    soTietKiem ds[100];
    for(int i=0;i<n;i++){
        cout<<"Nhap vao so tiet kiem thu "<<i+1<<": "<<endl;
        nhap(ds[i]);
    }
    cout<<"Danh sach so tiet kiem: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"So tiet kiem "<<i+1<<": "<<endl;
        Xuat(ds[i]);
    }
    cout<<"Nhap vao CMND cua so tiet kiem can tim: ";
    int cmnd;
    cin>>cmnd;
    vector<soTietKiem>tk1 = tim1(ds,n,cmnd);
    if(tk1.empty()){
        cout<<"Khong co so tiet kiem nao!"<<endl;
    }else{
        cout<<"Nhung so tiet kiem co CMND "<<cmnd<<": "<<endl;
        for(soTietKiem x:tk1){
            Xuat(x);
        }
    }

    cout<<"Nhap vao ma so cua so tiet kiem can tim: ";
    string ma;
    cin.ignore();
    getline(cin,ma);
    vector<soTietKiem>tk2 = tim2(ds,n,ma);
    if(tk2.empty()){
        cout<<"Khong co so tiet kiem nao!"<<endl;
    }else{
        cout<<"Nhung so tiet kiem co ma "<<ma<<": "<<endl;
        for(soTietKiem x:tk2){
            Xuat(x);
        }
    }

    cout<<"Nhap vao ngay mo cua so tiet kiem: ";
    date ngay;
    nhapDate(ngay);
    vector<soTietKiem>tk3 = tim3(ds,n,ngay);
    if(tk3.empty()){
        cout<<"Khong co so tiet kiem nao!"<<endl;
    }else{
        cout<<"Nhung so tiet kiem mo ngay "<<ngay.ngay<<"/"<<ngay.thang<<"/"<<ngay.nam<<": "<<endl;
        for(soTietKiem x:tk3){
            Xuat(x);
        }
    }

    cout<<"Danh sach so tiet kiem theo so tien gui giam dan: "<<endl;
    sapXep1(ds,n);
    for(int i=0;i<n;i++){
        cout<<"STT: "<<i+1<<": ";
        Xuat(ds[i]);
    }

    cout<<"Danh sach so tiet kiem theo ngay mo tang dan: "<<endl;
    sapXep2(ds,n);
    for(int i=0;i<n;i++){
        cout<<"STT: "<<i+1<<": ";
        Xuat(ds[i]);
    }
    double laiSuat;
    nhaplaisuat(laiSuat);
    vector<soTietKiem>v(ds,ds+n);
    tinhlaisuat(v,n,laiSuat);
    ruttien(v,n);

}
