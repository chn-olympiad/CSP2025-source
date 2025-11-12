#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int x[5010];
long long y[5010][5010];
long long o=0;
int n;
void dfs(int i,int k){
	for(int c=i;c<n;c++){
		if(x[c]<k){
			o++;
		}
		else{
			break;
		}
	}
	if(i==n-1){
		return;
	}
	for(int c=i;c<n-1;c++){
		dfs(c+1,k+x[c]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int i=1;
	for(int c=0;c<n;c++){
		cin>>x[c];
		if(x[c]!=1){
			i=0;
		}
	}
	if(i==1){
		y[0][0]=1;
		for(int c=1;c<=n;c++){
			y[c][0]=1;
			for(int d=1;d<=c;d++){
				y[c][d]=y[c-1][d]+y[c-1][d-1];
				y[c][d]%=mod;
			}
		}
		long long i=0;
		for(int c=3;c<=n;c++){
			i=(i+y[n][c])%mod;
		}
		cout<<i;
	}
	else{
		sort(x,x+n);
		dfs(0,0);
		cout<<o;
	}
	return 0;
}