#include<bits/stdc++.h>
using namespace std;
int d[120]={},e;
inline bool cmp(int a,int b){
    return a>b;
}
inline int er(int l,int r){
    int z=(l+r)>>1,w=1;
    while(d[z]!=e){
        if(d[z]<e){
            r=z;
        }else if(d[z]>e){
            l=z;
        }
        z=(l+r)>>1;
    }
    return z;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,c,w;
    cin>>a>>c;
    for(int b=1;b<=a*c;b++){
        cin>>d[b];
    }
    e=d[1];
    sort(d+1,d+a*c+1,cmp);
    w=er(1,a*c);
    if(((w-1)/a+1)&1){
        cout<<(w-1)/a+1<<" "<<(w-1)%a+1;
    }else{
        cout<<(w-1)/a+1<<" "<<a-(w-1)%a;
    }
	return 0;
}

