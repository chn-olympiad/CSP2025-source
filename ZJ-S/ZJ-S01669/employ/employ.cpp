#include<bits/stdc++.h>
using namespace std;
int f[1025][15][15],n,a[15],k;
bool t[15];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		char q;
		cin>>q;
		t[i]=q-'0';
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	f[0][0][0]=1;
	
		for(int j=1;j<=n;j++){
			for(int o=0;o<=n;o++){
			for(int i=0;i<=(1<<n);i++){
				if(!t[j]){
					for(int u=1;u<=(1<<n);u=u<<1){
						if(u&i){
							f[i][j][o]+=f[i-u][j-1][o-1];
						}
					}
				}
				else{
					for(int u=1,y=1;y<=n;y++,u=u<<1){
						if(u&i&&a[y]<o){
							f[i][j][o]+=f[i-u][j-1][o-1];
						}
					}
				}
			}
		}
	}
	for(int i=0;i<=n;i++)cout<<f[1<<n][n][i]<<"\n";
	return 0;
}
/*
3 2
101
1 1 2

*/
