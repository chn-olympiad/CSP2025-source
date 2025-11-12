#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=998244353;
int c[100001],vis[100001],ans,n,m;
vector<int>v;
string s;
void dfs(int l,int id){
	if(v.size()==n){
		int cnt=0,cnt1=0;
		for(int i = 0;i<v.size();i++){
			if(s[i]=='1'){
				if(cnt1>=v[i]){
					cnt1++;
					continue;
				}
				cnt++;
			}
			else{
				cnt1++;
			}
//			cout<<v[i]<<' ';
		}
		if(cnt>=m){
			ans = (ans+1)%M;
		}
//		cout<<endl;
	}
	for(int i = l;i<=n;i++){
		if(vis[i]==0){
			vis[i] = 1;
			v.push_back(c[i]);
			dfs(l,id+1);
			v.pop_back();
			vis[i] = 0;
		}
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
