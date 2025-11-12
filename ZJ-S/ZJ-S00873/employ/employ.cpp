#include<bits/stdc++.h>
using namespace std;
long long n,m;long long ans,md=998244353;
string s;
long long c[510],t[510],l,f[501][501][501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i-1]=='1'){
			l++;
			t[l]=i-1;
		}
	}
	if(l<m){
		cout<<0;
		return 0;
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=l;i++){
		for(int j=0;j<=n;j++)f[i-1][0][j]=1;
		for(int j=0;j<min(l+1,m);j++){
			int k=j;
			while(c[k]<=t[i]-j){
				f[i][j+1][k]+=f[i-1][j+1][k];
				f[i][j+1][k]%=md;
				k++;
			}
			for(;k<=n;k++){
				f[i][j+1][k]+=f[i-1][j][k-1]+f[i-1][j+1][k]+f[i][j+1][k-1]-f[i-1][j+1][k-1];
				f[i][j+1][k]%=md;
			}
		}
	}
	ans=1ll*f[l][m][n];
	for(long long i=1;i<=n-m;i++){
		ans*=i;
		ans%=md;
	}
	cout<<ans;
	return 0;
}