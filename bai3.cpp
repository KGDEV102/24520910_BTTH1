// Viết chương trình cho phép người dùng nhập vào hai phân số. Tính tổng, hiệu, 
// tích, thương giữa chúng và xuất kết quả ra màn hình. 
#include<iostream>
using namespace std;
struct PhanSo{
    int tu;
    int mau;
};
void KhoiTao(PhanSo& P){
    P.tu = 0;
    P.mau = 1;
}
void Nhap(PhanSo& P){
    cout<<"Tu: ";
    cin>>P.tu;
   
   do{
    cout<<"Mau: ";
    cin>>P.mau;
   }while(P.mau==0);
}
void Xuat(PhanSo P){
   if(P.mau<-1){
    cout<<-P.tu<<"/"<<P.mau<<endl;
   }else if(P.mau ==-1){
    cout<<-P.tu<<endl;
   }else if(P.mau ==1){
    cout<<P.tu<<endl;
   }else{
    cout<<P.tu<<"/"<<P.mau<<endl;
   }
}
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
    
}
void RutGon(PhanSo& P){
    int ucln = gcd(P.tu,P.mau);
    P.tu/=ucln;
    P.mau/=ucln;
}
PhanSo tinhTong(PhanSo a, PhanSo b){
    PhanSo res;
    res.tu = a.tu*b.mau + a.mau*b.tu;
    res.mau = a.mau * b.mau;
    return res;
}
PhanSo tinhHieu(PhanSo a, PhanSo b){
    PhanSo res;
    res.tu = a.tu*b.mau - a.mau*b.tu;
    res.mau = a.mau * b.mau;
    return res;
}
PhanSo tinhTich(PhanSo a, PhanSo b){
    PhanSo res;
    res.tu = a.tu * b.tu;
    res.mau = a.mau * b.mau;
    return res;
}
PhanSo tinhThuong(PhanSo a, PhanSo b){
    PhanSo res;
    res.tu = a.tu * b.mau;
    res.mau = a.mau * b.tu;
    return res;
}


int main(){
    PhanSo a;
    KhoiTao(a);
    cout<<"Nhap phan so thu nhat: "<<endl;
    Nhap(a);
    PhanSo b;
    KhoiTao(b);
    cout<<"Nhap phan so thu hai: "<<endl;
    Nhap(b);
    PhanSo tong = tinhTong(a,b);
    RutGon(tong);
    cout<<"Tong hai phan so: ";
    Xuat(tong);

    PhanSo hieu = tinhHieu(a,b);
    RutGon(hieu);
    cout<<"Hieu hai phan so: ";
    Xuat(hieu);

    PhanSo tich = tinhTich(a,b);
    RutGon(tich);
    cout<<"Tich hai phan so: ";
    Xuat(tich);

    PhanSo thuong = tinhThuong(a,b);
    RutGon(thuong);
    cout<<"Thuong hai phan so: ";
    Xuat(thuong);




}