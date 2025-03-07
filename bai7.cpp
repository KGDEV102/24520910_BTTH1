#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct date {
    int ngay,thang,nam;
};
struct Time {
    int gio;
    int phut;
};
struct chuyenBay{
    string ma;
    date ngay;
    Time gio;
    string di;
    string den;


};
//viết hàm kiểm tra định dạng nơi đến nơi đi 
bool isDiaDiem(string name) {
    if(name.length()>20) return false;

    // Kiểm tra từng ký tự trong chuỗi
    for (char c : name) {
        if (!isalpha(c) && c != ' ') { // Phải là chữ cái hoặc khoảng trắng
            return false;
        }
    }

    return true;
}
// viết hàm kiểm tra mã chuyến bay
bool isMa(string ma){
    if(ma.length()>5) return false;
    for (char c : ma) {
        if (!isalpha(c) && !isdigit(c)) { // Phải là chữ cái và số 
            return false;
        }
    }
    return true;
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
//hàm nhập vào thời gian 
void nhapTime(Time & t){
    cout<<"Nhap vao gio: ";
    cin>>t.gio;
    cout<<"Nhap vao phut: ";
    cin>>t.phut;
}
// hàm kiểm tra thời gian có hợp lệ hay không
bool isTime(Time t){
    return (t.gio >= 0 && t.gio < 24) && (t.phut >= 0 && t.phut < 60);
}
void Nhap(chuyenBay& X){
    while(true){
        
        cout<<"Nhap vao ma chuyen bay: ";
        cin>>X.ma;
        cin.ignore();
        cout<<"Nhap vao ngay bay: "<<endl;
        nhapDate(X.ngay);
        cout<<"Nhap vao thoi gian bay: "<<endl;
        nhapTime(X.gio);
        cout<<"Nhap vao noi di: ";
        cin.ignore();
        getline(cin,X.di);
        cout<<"Nhap vao noi den: ";
        getline(cin,X.den);
        if(isMa(X.ma) && isDate(X.ngay) && isTime(X.gio) && isDiaDiem(X.di) && isDiaDiem(X.den)){
            break;
        }

        cout << "Thong tin khong hop le, vui long nhap lai!\n";
        

    }
}
//viết hàm xuất chuyến bay
void Xuat(chuyenBay X){
    cout<<"Ma chuyen bay: "<<X.ma<<endl;
    cout<<"Ngay bay: "<<X.ngay.ngay<<"/"<<X.ngay.thang<<"/"<<X.ngay.nam<<endl;
    cout<<"Gio bay: "<<X.gio.gio<<":"<<X.gio.phut<<endl;
    cout<<"Noi di: "<<X.di<<endl;
    cout<<"Noi den: "<<X.den<<endl;

}
//viết hàm tìm kiếm các chuyến bay theo mã 
//viêt hàm chuyển các kí tự về dạng in thường để tiện so sánh 
void chuyen(string& s){
    for(int i=0;i<s.size();i++){
        s[i] = tolower(s[i]);
    }

}
vector<chuyenBay> timKiem1(chuyenBay X[], int n){
  
    vector<chuyenBay> v;
   
    string s;
    getline(cin, s);

    chuyen(s); // Chuyển mã chuyến bay cần tìm về chữ thường

    for (int i = 0; i < n; i++) {
        string temp = X[i].ma; // Lưu tên gốc
        chuyen(temp); // Chuyển tên sang chữ thường

        if (temp == s) { 
            v.push_back(X[i]);
        }
    }
    return v;
}
// hàm tìm kiếm các theo nơi đi
vector<chuyenBay> timKiem2(chuyenBay X[], int n){
  
    vector<chuyenBay> v;
   
    string s;
    getline(cin, s);

    chuyen(s); // Chuyển nơi đi chuyến bay cần tìm về chữ thường

    for (int i = 0; i < n; i++) {
        string temp = X[i].di; // Lưu tên gốc
        chuyen(temp); // Chuyển tên sang chữ thường

        if (temp == s) { 
            v.push_back(X[i]);
        }
    }
    return v;
}
// hàm tìm kiếm chuyến bay theo nơi đến 
vector<chuyenBay> timKiem3(chuyenBay X[], int n){
   
    vector<chuyenBay> v;
   
    string s;
    getline(cin, s);

    chuyen(s); // Chuyển mã chuyến bay cần tìm về chữ thường

    for (int i = 0; i < n; i++) {
        string temp = X[i].den; // Lưu tên gốc
        chuyen(temp); // Chuyển tên sang chữ thường

        if (temp == s) { 
            v.push_back(X[i]);
        }
    }
    return v;
}
// hàm sắp xếp các chuyến bay theo thứ tự ngày và giờ khởi hành
void sapXep(chuyenBay X[], int n) {
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

// hàm trả về các chuyến bay khởi hành từ một nơi cụ thể trong một ngày được chỉ định 
// hàm kiểm tra 2 ngày giống nhau
bool trungDate(date n, date m){
    return (n.ngay == m.ngay && n.thang == m.thang && n.nam == m.nam );
}
vector<chuyenBay> hienThi(chuyenBay X[], int n, string di,date ngay){
   vector<chuyenBay>v;

    for (int i = 0; i < n; i++) {
        string temp = X[i].di; // Lưu tên gốc
        chuyen(temp); // Chuyển tên sang chữ thường

        if (temp == di) { 
           if(trungDate(ngay,X[i].ngay)){
            v.push_back(X[i]);
           }
        }
    }
    return v;

}
// hàm đếm số chuyển bay từ một nơi đi đến một nơi đến cố định
int dem(chuyenBay X[], int n, string di, string den){
    int cnt = 0;
   
    getline(cin,den);
    for(int i=0;i<n;i++){
        if(di == X[i].di){
            if(den == X[i].den){
                ++cnt;
            }
        }
    }
    return cnt;

}
int main(){
    chuyenBay X[100];
    cout<<"Nhap vao so luong chuyen bay: ";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap vao chuyen bay thu "<<i+1<<endl;
        Nhap(X[i]);
    }
    cout<<endl;
    cout<<"Danh sach chuyen bay da sap xep theo ngay va gio khoi hanh: "<<endl;
    sapXep(X,n);
    for(int i=0;i<n;i++){
        cout<<"Chuyen bay thu "<<i+1<<endl;
        Xuat(X[i]);
    }
    cout<<"Nhap vao ma chuyen bay can tim: "<<endl;
    vector<chuyenBay>v1;
    v1 = timKiem1(X,n);
    cout<<"Nhung chuyen bay co ma can tim la: "<<endl;
    for(chuyenBay x:v1){
        Xuat(x);
    }

    cout<<"Nhap vao noi di cua chuyen bay can tim: "<<endl;
    vector<chuyenBay>v2;
    v2 = timKiem2(X,n);
    if(v2.size()==0){
        cout<<"Khong co chuyen bay nao "<<endl;
    }else{
        cout<<"Nhung chuyen bay co noi di can tim la: "<<endl;
        for(chuyenBay x:v2){
            Xuat(x);
        }
    }

    cout<<"Nhap vao noi den cua chuyen bay can tim: "<<endl;
    vector<chuyenBay>v3;
    v3 = timKiem3(X,n);
    if(v3.size()==0){
        cout<<"Khong co chuyen bay nao"<<endl;
    }else{
        cout<<"Nhung chuyen bay co noi den can tim la: "<<endl;
        for(chuyenBay x:v3){
        Xuat(x);
    }
    }
    //Hiển thị danh sách tất cả các chuyến bay khởi hành từ một nơi cụ thể trong một 
    //ngày được chỉ định. 
   
    cout<<"Nhap vao noi di cua chuyen bay: ";
    string di;
    getline(cin,di);
    cout<<"Nhap vao ngay bay: ";
    date ngay;
    nhapDate(ngay);
    
    vector<chuyenBay>ans = hienThi(X,n,di,ngay);
    if(ans.size()==0){
        cout<<"Khong co chuyen bay nao";
    }else{
        cout<<"Chuyen bay di tu "<<di<<" vao ngay "<<ngay.ngay<<"/"<<ngay.thang<<"/"<<ngay.nam<<": "<<endl;
        for(chuyenBay x:ans){
           Xuat(x);
        }
    }
   
    // đếm số lượng chuyến bay từ một nơi đến một nơi nhất định
    cout<<"Nhap vao noi di: ";
    string di1;
    getline(cin,di1);
    
    cout<<"Nhap vao noi den: ";
    string den;
    int res = dem(X,n,di1,den);
    cout<<"So luong chuyen bay di tu "<<di<<" den noi"<<den<<" la: "<<res<<endl;

}