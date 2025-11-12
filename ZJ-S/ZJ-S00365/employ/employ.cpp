#include<bits/stdc++.h>
using namespace std;
const int N=505;
const long long mod=998244353;
int c[N];
int n,m;
bool vis[N];
int a[N];
long long ans;
string s;
void dfs(int k){
	if(k>n){
//		cout<<"end\n";
		int cnt=0,loser=0;
		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
			if(s[i]=='0'){
				loser++;
			}
			else if(loser<c[a[i]]){
				cnt++;
			}
			else{
				loser++;
			}
		}
//		cout<<endl;
		if(cnt>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		a[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
