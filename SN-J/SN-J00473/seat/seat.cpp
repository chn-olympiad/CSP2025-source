//SN-J00473 曹博皓 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105][105];
signed main(){
	   freopen("seat.in","r",stdin);
	   freopen("seat.out","w",stdout);
	   cin>>n>>m;
	   for(int i=1;i<=n;i++){
	   		for(int j=1;j<=m;j++){
	   			cin>>a[i][j];
			}
	   }
	   int v=100-a[1][1]+1,cnt=0;
	   for(int i=1;i<=n;i++){
	   		if(i%2!=0){
	   			for(int j=1;j<=m;j++){
	   				cnt++;
	   				if(cnt==v){
	   					cout<<i<<" "<<j;
					}
				}
			}else{
				for(int j=m;j>=1;j--){
	   				cnt++;
	   				if(cnt==v){
	   					cout<<i<<" "<<j;
					}
				}
			}
	   		
	   }
	   return 0;
}

