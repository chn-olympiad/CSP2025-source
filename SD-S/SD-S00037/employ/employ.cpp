#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=998244353;
int c[23],sum=0,ans=0,yi=0;
bool vis[23];
	int n,m;
	string s;
void dfs(int x){
	if(x==1&&sum>=m){
		ans++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&c[i]>yi){
			if(s[i-1]=='0'){
				yi++;
			}
			else{
				sum++;
			}
			vis[i]=1;
			dfs(x-1);
			vis[i]=0;
			if(s[i-1]=='0'){
				yi--;
			}
			else{
				sum--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		
	}
	dfs(n);
	cout<<ans;
	return 0;
} 
