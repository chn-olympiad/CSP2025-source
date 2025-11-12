//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pr pair<long long,long long>
#define forr(i,n) for(long long i=1;(i)<=(n);(i)++)
#define fo(i,n) for(long long i=0;(i)<(n);(i)++)
#define gc getchar
#define pc putchar
#define one first
#define two second
ll num,numm[110],f,cnt;
ll n,a[5010],ff=1,ans,aans,vis[5010];
char c;
ll in(){
	f=1,num=0,c=gc();
	for(;c<'0'||c>'9';c=gc())
		if(c=='-')
			f=-1;
	for(;c>='0'&&c<='9';c=gc())
		num=num*10+c-'0';
	return num*f;
}
void out(ll x){
	f=1,cnt=0;
	if(x){
	if(x<0)
		f=-1,x=-x;
	while(x)
		numm[++cnt]=x%10,x/=10;
	for(ll i=cnt;i>=1;i--)
		pc(numm[i]+'0');
	}
	else if(x==0)
		pc('0');
}
void dfs(ll id,ll ls,ll tot,ll sum,ll ff){
	if(sum>=3&&tot>2*ls&&ff)
		ans=(ans+1)%998244353,ff=0;
	if(id>n||n-id+sum<2)
		return;
	dfs(id+1,ls,tot,sum,ff);
	vis[id]=a[id];
	dfs(id+1,max(a[id],ls),tot+a[id],sum+1,1);
	vis[id]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=in();
	forr(i,n){
		a[i]=in();
		if(a[i]!=1)
			ff=0;
	}
	if(ff)
		for(ll i=3;i<=n;i++){
			aans=1;
			fo(j,i)
				aans=aans*(n-j)%998244353;
			ans=(ans+aans)%998244353;
		}
	else
		dfs(1,0,0,0,1);
	cout<<ans;
	return 0;
}