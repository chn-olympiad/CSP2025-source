#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[510];
//int d[510];
bool vis[510];
bitset<510> difficulty; 
int ans=0;
void dfs(int dep,int s,int sum){//深度，未录取人数，录取人数 
	if(dep>n){
		if(sum>=m){
			ans++;
//			cout<<s<<" "<<sum<<endl;
//			for(int i=1;i<=dep;i++){
//				cout<<d[i]<<" ";
//			}
//			cout<<endl;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(a[i]>s){
				if(difficulty[dep]==1){
					vis[i]=1;
//					d[dep]=i;
					dfs(dep+1,s,sum+1);
					vis[i]=0;
//					d[dep]=0;
				}else{
					vis[i]=1;
//					d[dep]=i;
					dfs(dep+1,s+1,sum);
					vis[i]=0;
//					d[dep]=0;
				}
			}else{
				vis[i]=1;
//				d[dep]=i;
				dfs(dep+1,s+1,sum);
				vis[i]=0;
//				d[dep]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='1'){
			difficulty.set(i);
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
//暴力枚举，O(2^n)
//期望得分 20 pts 
//hyw
//AFO.
