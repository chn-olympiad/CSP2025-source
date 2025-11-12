#include<bits/stdc++.h>
using namespace std;
long long n,m,k,mp[10005][5],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long mm[m+1][4]={};
	for(int i=1;i<=m;i++){
		cin>>mp[i][1]>>mp[i][2]>>mp[i][3];
	}
	long long mk[k+1][n+1]={};
	bool f[k+1]={};
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>mk[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		int pre=0;
		for(int j=1;j<=k;j++){
			if(f[j]==1){
				if(mp[i][3]>mk[j][i]){
					mp[i][3]=mk[j][i];
				}
			}
			else {
				if(mp[i][3]>mk[j][i]+mk[j][0]){
					f[pre]=0;
					mp[i][3]=mk[j][i]+mk[j][0];
					f[j]=1;
					pre=j;
					f[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans+=mp[i][3];
	}
	cout<<ans-2;
	return 0;
}
