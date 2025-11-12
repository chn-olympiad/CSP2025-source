#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum[1000];
bool cmp(int a,int b){
	return a>b;
}
int l;
int sh=0;
int mp[100][100];
int js=0;
int pm=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>sum[i];
	int xiao=sum[1];
	sort(sum+1,sum+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				mp[j][i]=++js;
			}
		}else{
			for(int j=m;j>=1;j--){
				mp[j][i]=++js;
			}
		}
		
	}
	for(int i=1;i<=n*m;i++){
		if(sum[i]==xiao){
			pm=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==pm){
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
