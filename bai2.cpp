// Viết chương trình cho phép người dùng nhập vào hai phân số, tìm phân số lớn 
// nhất và xuất kết quả ra màn hình. 
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
PhanSo timMax(PhanSo a, PhanSo b){
    PhanSo res;
    float ps1 = (float)a.tu / a.mau;
    float ps2 = (float)b.tu / b.mau;
    if(ps1 > ps2){
        res.tu = a.tu;
        res.mau = a.mau;
    }else{
        res.tu = b.tu;
        res.mau = b.mau;
    }
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
   
   cout<<"Phan so lon nhat la: ";
   PhanSo psMax = timMax(a,b);
   RutGon(psMax);
   Xuat(psMax);
}