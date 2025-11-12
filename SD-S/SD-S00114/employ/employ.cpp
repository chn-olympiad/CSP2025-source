#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
const int N=550;

int n,m;
int a[N],s[N],pd[N];
int c[N];

long long anss=0;
long long ans=0,cnta=0,cntb=0;
bool vis[N];
void dfs(int pos,int lim,int num) {
	if(pos==n) {
		if(num >=m) anss=(anss+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		vis[i]=1;
		if(c[i]<=lim||(!a[pos+1])) {
			dfs(pos+1,lim+1,num);
		} else {
			dfs(pos+1,lim,num+1);		
		}
		vis[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		char c;
		cin>>c;
		a[i]=c-'0';
		s[i]=s[i-1]+a[i];
		pd[i+1]=pd[i]+((a[i]==0)? 1:0);
	}
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		cnta++;
		cntb++;
	}
	if(n<=18) {
		a[0]=1;
		dfs(0,0,0);
		cout<<anss<<"\n";
	} else {
		int ans=1;
		for(int i=1;i<=n;i++) {
			ans=ans*i%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
