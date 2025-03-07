//1. Viết chương trình cho phép người dùng nhập vào một phân số, rút gọn phân số 
// và xuất kết quả ra màn hình.
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
int main(){
    PhanSo x;
    KhoiTao(x);
    Nhap(x);
    Xuat(x);
    RutGon(x);
    Xuat(x);
}