#include <bits/stdc++.h>
using namespace std;
const int mod = 9982443;
int c[505],n,m;
long long ans=0;
int buguo=0;
bool vis[505];
string s;
void dfs(int it){
	if(it>=n){
		if(buguo<=n-m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			if(buguo<c[i]&&s[it]=='1'){
				//cout<<i<<" "<<it<<buguo<<'\n';
				dfs(it+1);
			}
			else{
				//cout<<i<<" "<<it<<buguo<<'\n';
				buguo++;
				dfs(it+1);
				buguo--;
			}
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int l=s.size();
	int n0=0;
	for(int i=0;i<l;i++){
		if(s[i]=='0'){
			n0++;
		} 
	}
	if(n0==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
	}
	else if(n-n0<m){
		ans=0;
	}
	else{
		dfs(0);
	}
	cout<<ans;
	return 0;
}
