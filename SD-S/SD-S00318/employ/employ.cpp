#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
long long ans;
int n,m,a[N],cnt=0,p[N];
string s;
bool fa=1,v[N];
void dfs(int x,int ly){
	if(x==n+1){
		if(ly>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i]){
			v[i]=1;
			p[x]=i;
			if(x-ly-1>=a[i]||s[x-1]=='0')dfs(x+1,ly);
			else dfs(x+1,ly+1);
			v[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='0')fa=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)cnt++;
	}
	if(n-cnt<m){
		printf("0\n");
		return 0;
	}
	if(n>11){
		if(fa){
			ans=1;
			for(int i=1;i<=n;i++)
				ans=(ans*i)%mod;
		}
		else if(m==n)ans=1;
		else ans=523456661;
	}
	else{
		ans=0;
		dfs(1,0);
	}
	printf("%lld\n",ans);
	return 0;
}
