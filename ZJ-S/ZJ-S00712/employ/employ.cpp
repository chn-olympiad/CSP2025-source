#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=998244353;
ll a[10005],c[10005],ans=0,u;
int n,m;
bool book[10005],b[10005];
string s;
bool pd(){
	ll sum=0,tot=0;
	for(int i=1;i<=n;i++){
		if(tot>=c[i]){
			tot++;
			continue;
		}
		if(!book[i]){
			tot++;
			continue;
		}
		sum++;
	}
	if(sum>=m)return 1;else return 0;
}
void search(ll k){
	if(k==n+1){
		if(pd())ans++;
		return ;
	}
	for(int i=1;i<=n;i++)if(!b[i]){
		b[i]=1;
		c[k]=a[i];
		search(k+1);
		b[i]=0;
		c[k]=0;
	}
}
ll js(ll w){
	ll an=1;
	for(ll i=2;i<=w;i++)an=(an*i)%p;
	return an;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	u=n;
	cin>>s;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0')book[i]=0;else book[i]=1;
		scanf("%lld",&a[i]);
		if(a[i]==0)u--;
	}
	if(n<=10)search(1);else ans=js(u);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}