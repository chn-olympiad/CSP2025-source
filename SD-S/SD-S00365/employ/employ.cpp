#include<iostream>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m;
int s[501];
int c[501];
int b[501];
bool vis[501];
int ans=0;
void dfs(int x){
	if(x>n){
		int ct=0;
		int ppl=0;
		for(int i=1;i<=n;i++){
			if(s[i]==1) ppl++;
			else{
				ct++;
				for(int j=i+1;j<=n;j++){
					if(ct>=c[j]){
						s[j]=114514;
						ct++;
					}
				}
			}
		}
		if(ppl>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		b[x]=c[i];
		dfs(x+1);
		vis[i]=0;
	}
}
bool f=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string t;
	cin>>t;
	for(int i=1;i<=n;i++){
		if(t[i-1]!='1') f=0;
		s[i]=(int)(t[i-1]-'0');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f){
		int cnt=1;
		int g=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=0) g++;
		}
		for(int i=1;i<=g+1;i++){
			cnt*=i;
			cnt%=MOD;
		}
		cout<<cnt<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
