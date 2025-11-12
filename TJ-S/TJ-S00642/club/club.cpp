#include<bits/stdc++.h>
using namespace std;
int a,d[200005][3]={},e[701][701][701];
inline int dfs(int n1,int n2,int n3){
    int he=(n1+n2+n3)-(a>>1),da=0;
    if(he<=0){
        return 0;
    }
    if(n1<701 && n2<701 && n3<701){
        if(e[n1][n2][n3]!=0){
            return e[n1][n2][n3];
        }
        if(n1>0){
            e[n1][n2][n3]=max(e[n1][n2][n3],d[he][0]+dfs(n1-1,n2,n3));
        }
        if(n2>0){
            e[n1][n2][n3]=max(e[n1][n2][n3],d[he][1]+dfs(n1,n2-1,n3));
        }
        if(n3>0){
            e[n1][n2][n3]=max(e[n1][n2][n3],d[he][2]+dfs(n1,n2,n3-1));
        }
        return e[n1][n2][n3];
    }
    if(n1>0){
        da=max(da,d[he][0]+dfs(n1-1,n2,n3));
    }
    if(n2>0){
        da=max(da,d[he][1]+dfs(n1,n2-1,n3));
    }
    if(n3>0){
        da=max(da,d[he][2]+dfs(n1,n2,n3-1));
    }
    return da;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    freopen("club4.in","r",stdin);
    int t;
    cin>>t;
    while(t--){
        memset(e,0,sizeof(e));
        int he=0;
        cin>>a;
        for(int b=1;b<=a;b++){
            cin>>d[b][0]>>d[b][1]>>d[b][2];
        }
        cout<<dfs(a>>1,a>>1,a>>1)<<endl;
    }
	return 0;
}
