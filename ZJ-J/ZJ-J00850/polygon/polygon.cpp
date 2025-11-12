#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=11451,mod=998244353;
int lst[MAXN],f[5][MAXN],f2[5][MAXN],ans,n,all;
//又是这样，byd的动态规划，每次思路正确代码写出来依托，没救了
signed main(){
	freopen("polygon2.in","r+",stdin);
//	freopen("polygon4P.ans","w+",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
		all+=lst[i];
	}
	if(n==3){
		if(lst[1]+lst[2]>lst[3]&&abs(lst[1]-lst[2])<lst[3]&&lst[2]+lst[3]>lst[1]&&abs(lst[2]-lst[3])<lst[1]&&lst[1]+lst[3]>lst[2]&&abs(lst[1]-lst[3])<lst[2]){
			cout<<1;return 0;
		}
		cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5001;j++){
			f[4][min(j+lst[i],5001ll)]+=f[3][j];
			if(j>lst[i]){
				f2[4][min(j+lst[i],5001ll)]+=f[3][j];
			}
			f[4][min(j+lst[i],5001ll)]%=mod;
		}
		int save=0;
		for(int j=1;j<=5001;j++){
			if(j<=lst[i]){
				f[3][min(j+lst[i],5002ll)]+=f[3][j];
				f[2][abs(j-lst[i])]+=f[3][j];
				f[4][1]+=f[2][j];
				f[4][1]-=f[3][j];
			}
			if(j>=lst[i]){
				f[3][min(j+lst[i],5002ll)]+=f[2][j];
				f[2][abs(j-lst[i])]+=f[2][j];
			}
			f[4][min(j+lst[i],5001ll)]%=mod;
		}
		for(int j=1;j<=5001;j++){
			f[3][min(j+lst[i],5002ll)]+=f[1][j];
			f[2][min(abs(j-lst[i]),5001ll)]+=f[1][j];
		}
		f[1][lst[i]]++;
	}
	for(int i=1;i<=min(5001ll,all);i++){
		ans%=mod;
	}
	cout<<ans;
}
