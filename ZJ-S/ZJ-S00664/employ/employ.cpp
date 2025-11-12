#include<bits/stdc++.h>
#define N 510
#define mod 998244353
using namespace std;
int n,m,a[N],p[N],id;long long as=1,e;
bool s[N];
void dfs(int cur){
	if(cur==n+1){
		int sum=0,pas=0;
		for(int i=1;i<=n;i++)
			if(s[i]==1&&sum<p[i]) pas++; 
			else if(s[i]==0||sum>=p[i]) sum++;
		if(pas>=m) e++;
	}
	for(int i=0;i<=n;i++)
		if(a[i]){
			a[i]--;
			p[cur]=i;
			dfs(cur+1);
			a[i]++;                                   
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;char c;
	for(int i=1;i<=n;i++)
		cin>>c,s[i]=c-'0';
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		a[t]++;
	}
	int cnt=1,sum=0,pas=0;
	for(int i=0;i<=n;i++){
		bool b=0;
		for(int j=1;j<=a[i];j++){
			as*=j*1ll,as%=mod;
//			cout<<as<<" ";
			if(b) continue;
			if(s[cnt]==1&&sum<i)p[cnt++]=i,id=cnt-1,pas++;
			else if(s[cnt]==0&&sum<=i) sum++,p[cnt++]=i;
			else if(s[cnt]==0&&sum>=i) b=1;
		}
	}
	if(pas==m){
		for(int i=1;i<=n-as;i++)as*=i*1ll,as%=mod;
		int l=1,r=1;
		while(r<=id){
			if(s[r]==1&&(r==1||s[r-1]==1))r++,as*=r-l;
			else if(s[r]==0&&r!=1&&s[r-1]==1) l=r,r++;
			else if(s[r]==0&&(r==1||s[r-1]==0))r++,as*=r-l;
			else if(s[r]==1&&r!=1&&s[r-1]==0) l=r,r++;
			as%=mod;
//			cout<<as<<" ";
		}
		cout<<as%mod;
		return 0;
	}
	dfs(1);
	cout<<as%mod*e%mod;
	return 0;
}