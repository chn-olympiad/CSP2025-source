#include <bits/stdc++.h>
using namespace std;
int N[15][15];
int ks[105];
int n,m,ans,tot,y;
bool cmp1(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++){
    	cin>>ks[i];
	}
    ans=ks[1];
    sort(ks+1,ks+(n*m)+1,cmp1);
    for(int j=1;j<=m;j++){//枚举列 
    	if(j%2==1) y=1;//特殊的i 
    	else y=n;
    	for(int k=1;k<=n;k++){
		//枚举行 
    		tot++;
    		N[j][y]=ks[tot];
//    		cout<<j<<' '<<y<<' '<<N[j][y]<<endl;
    		if(N[j][y]==ans){
    		    cout<<j<<' '<<y;
    		    return 0;
			}
    		if(j%2==1)y++;// 判断列的奇偶性 放最后+或- 
    		else y--;
		} 
	}
    return 0;
}
