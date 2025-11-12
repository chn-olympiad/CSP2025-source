#include<iostream>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r;
    cin>>n>>m;
    int a[n+1][m+1];
    int b[n*m],cj;
    cin>>cj;
    b[1]=cj;
    for(int i = 2;i<=n*m;i++){
        cin>>b[i];

    }
    for(int i = 1;i<=n*m;i++){
        for(int j = i;j<=n*m;j++){
            if(b[j]>b[i]){
                int t=b[j];
                b[j]=b[i];
                b[i]=t;
            }

        }

        if(b[i] == cj){
            r=i/n;
            if(i%n!=0){
                r++;
            }
            if(r%2==0){
                c = n-(i%n)+1;
            }else{
                c = i%n;
                if(c==0){
                    c=n;
                }
            }
            cout<<r<<" "<<c;
            return 0;
        }
    }

}
