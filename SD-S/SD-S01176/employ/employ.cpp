#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+63;
const int M=2e6+63;
const int MOD=998244353;
int n,m;
string s;
int c[N];
int b[N];
int t[N];
ll ans;
bool vis[N],flag;
void dfs(int x,int step,int k){
	if(k>=c[x]||b[step]==0){
		k++;
	}
	if(k+m>n){
		return;
	}
	if(step==n){
		if(k+m<=n){
			ans=(ans+1)%MOD;
		}
		return;
	}
	vis[x]=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,step+1,k);
		}
	}
	vis[x]=false;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		b[i]=s[i-1]-'0';
		if(b[i]==0){
			flag=false;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		t[c[i]]++;
	}
	if(flag){
		int x=0;
		for(int i=1;i<=n;i++){
			if(t[i]){
				x+=t[i];
			}
			else{
				break;
			}
		}
		if(x+m>n){
			ans=0;
		}
		else{
			for(int i=1;i<=n;i++){
				ans=ans*i%MOD;
			}
		}
	}
	else if(n<=15){
		b[0]=1;
		c[0]=1e9;
		dfs(0,0,0);
	}
	printf("%lld",ans);
	return 0;
}
