#include<bits/stdc++.h>
using namespace std;
const int N=510;
const long long mod=998244353ll;
int n,m,a[N],ret;
string s;
bool ud[N];
void dfs(int x,int num){
	if(num+n-x+1<m)return;
	if(x>n){
		if(num>=m)ret++,ret%=mod;
		return;
	}for(int i=1;i<=n;i++){
		if(ud[i])continue;
		if(s[i]=='0'){
			ud[i]=1;
			dfs(x+1,num);
			ud[i]=0;
		}else{
			ud[i]=1;
			if(x-1-num>=a[i])dfs(x+1,num+1);
			else dfs(x+1,num);
			ud[i]=0;
		}
	}
}int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	s=' '+s;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)if(s[i]=='1')cnt++;
	if(cnt<m){
		cout<<0;
		return 0;
	}if(n<=18){
		dfs(1,0);
		cout<<ret;
		return 0;
	}long long ans=1ll;
	cnt=n;
	for(int i=1;i<=n;i++)if(!a[i]&&i<m)cnt--;
	if(cnt<m){
		cout<<0;
		return 0;
	}for(long long i=1ll;i<=1ll*n;i++)ans*=i,ans%=mod;
	cout<<ans;
	return 0;
}
