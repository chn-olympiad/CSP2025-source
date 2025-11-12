#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
ll n,m,eft[N],p[N],pp[N],ans=0;
string s;
char c;
bool vis[N];
void dfs(int x){
	if(x==n+1){
		int mg=0,yg=0;
		for(int i=1;i<=n;i++){
			int idx=pp[i];
//			cout<<idx<<" ";
        	if(mg>=p[idx]){
				mg++;
				continue;
			}
			if(eft[i]==0){
				mg++;
			}else{
				yg++;
//				cout<<yg<<endl;
			}
		}
		if(yg>=m) ans++;
//		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true) continue;
		vis[i]=true;
		pp[x]=i;
		dfs(x+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		eft[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	dfs(1);
	ans%=998244353;
	cout<<ans<<endl;
	return 0;
} 
