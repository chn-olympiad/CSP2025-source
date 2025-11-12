#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int x[510];
int n,m;
int k=0;
bool vi[510];
string y;
void dfs(int i,int j){
	if(j>n-m){
		return;
	}
	if(i==n){
		if(j<=n-m){
			k++;
		}
		return;
	}
	for(int c=0;c<n;c++){
		if(!vi[c]){
			vi[c]=1;
			if(x[c]<=j||y[i]=='0'){
				dfs(i+1,j+1);
			}
			else{
				dfs(i+1,j);
			}
			vi[c]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>y;
	int i=0;
	for(int c=0;c<n;c++){
		if(y[c]=='0'){
			i++;
		}
	}
	int j=0;
	for(int c=0;c<n;c++){
		cin>>x[c];
		j+=(x[c]==0);
	}
	if(m>n-max(i,j)){
		cout<<0;
		return 0;
	}
	if(n==m){
		long long u=1;
		for(long long c=2;c<=n;c++){
			u=u*c%mod;
			u%=mod;
		}
		cout<<u;
		return 0;
	}
	dfs(0,0);
	cout<<k;
	return 0;
}