#include<bits/stdc++.h>
using namespace std;
long long a=0,b=0,c=0,d=0,e[10005]={0},f=0,hh=0,ee[10005]={0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>e[i];
    }
    c=e[1];
    sort(e+1,e+a*b+1);

    for(int i=a*b;i>=1;i--){
        ee[a*b+1-i]=e[i];

    }

    for(int i=1;i<=a*b;i++){
        if(ee[i]==c){
            f=i/a;
            if(i%a>0){
                f++;
            }
			if(f%2==0){
                if(i%a!=0){
                    d=a+1-i%a;
                }else{
                    d=1;
                }

			}
			else{
                if(i%a!=0){
                   d=i%a;
                }else{
                    d=a;
                }

			}

        }
    }
    cout<<f<<' '<<d;
    return 0;

}
