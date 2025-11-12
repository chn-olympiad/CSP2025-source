#include<bits/stdc++.h>
using namespace std;
bool w[501]={},e[501];
int a,c,d[501]={};
int dfs(int n,int m){
    if(m==a+1 && a-n>=c){
        return 1;
    }
    int da=0;
    for(int b=1;b<=a;b++){
        if(e[b]==0){
            e[b]=1;
            da+=dfs(n+(!w[m] || n>=d[b]),m+1)%998244353;
            da%=998244353;
            e[b]=0;
        }
    }
    return da;
}
int main(){
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    freopen("employ2.in","r",stdin);
    cin>>a>>c;
    getchar();
    for(int b=1;b<=a;b++){
        w[b]=(getchar()=='1');
    }
    for(int b=1;b<=a;b++){
        cin>>d[b];
    }
    cout<<dfs(0,1);
	return 0;
}
