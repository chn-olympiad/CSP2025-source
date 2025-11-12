#include<bits/stdc++.h>
using namespace std;
int n,m;
const int md=998244353;
char s[1000001];
int a[1000001];
long long ans;
bool b[100001];
void Sub1(){
	 ans=1;
	for(int i=1;i<=n;i++)ans*=i,ans%=md;	
}
void dfs(int k,int le,int nw){
	if(k>n){
		ans+=(nw>=m);
		return;
	}
	if(n-le+k<m)return;
	vector<int>p;
	for(int i=1;i<=n;i++){
		if(a[i]<=le&&!b[i])b[i]=1,p.push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(s[k]=='1')dfs(k+1,le,nw+1);
			else dfs(k+1,le+1,nw);
			b[i]=0;
		}
	}
	for(int i=0;i<p.size();i++)b[p[i]]=0;
}
void Sub2(){
	dfs(1,0,0);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	bool flag1=1;
	for(int i=1;i<=n;i++)if(s[i]=='0')flag1=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(flag1)Sub1();
	else Sub2();
	printf("%lld\n",ans);
}

