#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int mod=998244353;

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
} 

int n,m;
string s;
int a[N],c[N];
int vis[N];
int ans;
int p[N];

void dfs(int step,int x){
	if(step==n&&n-x>=m){
		ans++;
//		for(int i=0;i<n;i++)
//			cout<<p[i]<<" ";
//		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
//		p[step]=i;
		int tmp=a[i]^1;
		tmp|=(x>=c[i]);
		dfs(step+1,x+tmp);
		vis[i]=0;
	} 
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read(),m=read();
	cin>>s;s=" "+s;
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	for(int i=1;i<=n;i++)
		c[i]=read();
	dfs(0,0);
	cout<<ans<<"\n";
	
	return 0;
}

/*
3 2
101
1 1 2
*/ 
