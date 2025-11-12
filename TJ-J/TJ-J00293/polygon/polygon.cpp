#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
const int MOD=998244353;
int a[N],n,sum[N];
int f[N][N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][0]=i;
	}
	f[0][0]=1;
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=a[i];k++){
			if()
		}
	}
	return 0;
}
