#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct date{
    int ngay, thang, nam;
};
struct soTietKiem{
    string ma;
    string loai;
    string hoTen;
    int cmnd;
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
bool iscmnd(int cmnd){
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
void nhap(soTietKiem& X){
    while(true){
        cout<<"Nhap vao ma so: ";
        cin>>X.ma;
        cin.ignore();
        cout<<"Nhap vao loai tiet kiem: ";
        getline(cin,X.loai);
        cout<<"Nhap vao ho ten khach hang: ";
        getline(cin,X.hoTen);
        cout<<"Nhap vao cmnd : ";
        cin>>X.cmnd;
        cin.ignore();
        cout<<"Nhap vao ngay mo so: ";
        nhapDate(X.ngay);
        cout<<"Nhap vao so tien: ";
        cin>>X.soTien;
        if(isMa(X.ma) && iscmnd(X.cmnd) && isDate(X.ngay) && (X.soTien>0)){
            break;
        }
        cout<<"Nhap thong tin sai. Vui long nhap lai!"<<endl;
    }
}
void Xuat(soTietKiem X){
    cout<<"Ma so: "<<X.ma<<endl;
    cout<<"Loai tiet kiem: "<<X.loai<<endl;
    cout<<"Ho ten khach hang: "<<X.hoTen<<endl;
    cout<<"CMND: "<<X.cmnd<<endl;
    cout<<"Ngay mo so: "<<X.ngay.ngay<<"/"<<X.ngay.thang<<"/"<<X.ngay.nam<<endl;
    cout<<"So tien gui: "<<X.soTien<<endl;
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
            } else if (X[j].ngay.nam == X[i].ngay.nam && X[j].ngay.thang == X[i].ngay.thang && X[j].ngay.ngay == X[i].ngay.ngay && X[j].gio.gio < X[i].gio.gio) {
                swap(X[i], X[j]);
            } else if (X[j].ngay.nam == X[i].ngay.nam && X[j].ngay.thang == X[i].ngay.thang && X[j].ngay.ngay == X[i].ngay.ngay && X[j].gio.gio == X[i].gio.gio && X[j].gio.phut < X[i].gio.phut) {
                swap(X[i], X[j]);
            }
        }
    }
}
int main(){

}