//input: số lượng phần tử 2 mảng A, B. Nhập vào các phần tử của 2 mảng A, B
//output: Số lần xuất hiện của mảng A trong mảng B, và vị trí đầu tiên ở mỗi lần xuất hiện đó 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a[1000],b[1000];
    int n1,n2;
    cout<<"Nhap vao so luong phan tu hai mang: ";
    cin>>n1>>n2;
    cout<<"Nhap vao mang A: ";
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    cout<<"Nhap vao mang B: ";
    for(int i=0;i<n2;i++){
        cin>>b[i];
    }
    int cnt =0;
    vector<int>vitri;
    for(int i=0;i<=n2-n1;i++){ // chỉ cần duyệt đến phần tử thứ n2 - n1 vì đến phần tử đó duyệt qua i+j là các phần tử tương ứng chỉ sôsẽ không bị tràn số 
        bool check = true;
        for(int j=0;j<n1;j++){
            if(a[j]!=b[i+j]){ // ở mỗi chỉ số i của mảng b sẽ duyệt qua các phần tử liên tiếp của nó là i+j 
                check=false;
                break;            //để so sánh vs các phần tử tương ứng ở mảng a 

            }
            //Nếu các phần tử tương ứng ở mảng b không bằng thì sẽ kết thúc để qua chỉ số khác
        }
        
        if(check){
            ++cnt;
            vitri.push_back(i);
        }
    }
    if(cnt==0){
        cout<<"Mang A khong xuat hien trong mang B"<<endl;
    }else{
        cout<<"Mang A xuat hien "<<cnt<<" lan tai cac chi so bat dau la: "<<endl;
        for(int x:vitri){
            cout<<x<<endl;
        }
    }
    
}
