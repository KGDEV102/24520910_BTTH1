#include<iostream>
using namespace std;
struct date{
    int ngay,thang,nam;
   
};
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
void Nhap(date& N){
    do{
        cout<<"Nhap vao ngay: ";
        cin>>N.ngay;
        cout<<"Nhap vao thang: ";
        cin>>N.thang;
        cout<<"Nhap vao nam: ";
        cin>>N.nam;
    }while(N.ngay<=0 || N.ngay>ngayOfthang(N.thang,N.nam) || N.thang<=0 || N.thang > 12 || N.nam <=0);
}
void Xuat(date N){
    cout<<N.ngay<<"/"<<N.thang<<"/"<<N.nam;
}
date* nextDay(date N){
    date* Next = new date;
    if(N.ngay == ngayOfthang(N.thang,N.nam)){
        if(N.thang == 12){
           Next->ngay=1;
           Next->thang=01;
           Next->nam = N.nam+1;
        }else{
            Next->ngay = 1;
            Next->thang = N.thang+1;
            Next->nam = N.nam;

        }
    }else{
        Next->ngay = N.ngay+1;
        Next->thang = N.thang;
        Next->nam = N.nam;
    }
    return Next;
}
date* prevDay(date N){
    date* prev = new date;
    if(N.ngay == 1){
        if(N.thang == 1){
            prev->ngay = 31;
            prev->thang = 12;
            prev->nam = N.nam - 1;
        }else{
            prev->ngay = 1;
            prev->thang = N.thang -1;
            prev->nam = N.nam;
        }
    }else{
        prev->ngay = N.ngay -1;
        prev->thang = N.thang;
        prev->nam = N.nam;
    }
    return prev;
}
int ngayOfnam(date N){
    int res = 0;
    if(N.thang == 1){
        res = N.ngay;
    }else{
        for(int i=1;i<N.thang;i++){
            res+=ngayOfthang(i,N.nam);
        }
        res+=N.ngay;
    }
    return res;
}
int main(){
   date N;
   cout<<"Nhap ngay hien tai: "<<endl;
   Nhap(N);
   date* Next = nextDay(N);
   cout<<"Ngay tiep theo la: ";
   Xuat(*Next);
   cout<<endl;
   cout<<"Ngay hom truoc la: ";
   date* prev = prevDay(N);
   Xuat(*prev);
   cout<<endl;
   cout << "Ngay: "; Xuat(N);cout<<" la ngay thu "<<ngayOfnam(N)<<" trong nam";
   
}
