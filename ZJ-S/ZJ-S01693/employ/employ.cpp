#include<bits/stdc++.h>
using namespace std;
#define int long long

int ans=0;
int n,m;
string s;
vector<int>a;
vector<int>f;
void dfs(int j,int r,int z){
	if(j==n){
		if(r>=m){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(!f[i]){
			f[i]=1;
			if(s[j]=='0'){
				dfs(j+1,r,z+1);
			}
			if(s[j]=='1'){
				if(a[i]>z){
					dfs(j+1,r+1,z);
				}
				else{
					dfs(j+1,r,z+1);
				}
			}
			f[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	f=vector<int>(n,0);
	cin>>s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	dfs(0,0,0);
	cout<<ans%998244353;
	return 0;
}
