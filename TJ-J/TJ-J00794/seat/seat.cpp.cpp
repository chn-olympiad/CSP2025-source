#include<bits/stdc++.h>
using namespace std;

int m,n,ai;
int s[150];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>ai;
    s[1]=ai;
    for(int i=2;i<=n*m;i++){
        cin>>s[i];
    }
    sort(s+1,s+n*m+1,cmp);
    int num=0;
    for(int i=1;i<=n*m;i++){
        if(s[i]==ai){
            num=i;
            break;
        }
    }
    int hang,lie;
    lie=ceil(num*1.0/n);
    if(lie%2!=0){
        if(num%n==0){
            hang=n;
        }
        else{
            hang=num%n;
        }
    }
    else if(num%n==0){
        hang=1;
    }
    else{
        hang=n+1-(num%n);
    }
    cout<<lie<<" "<<hang;
    return 0;
}
