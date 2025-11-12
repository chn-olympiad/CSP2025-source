#include<bits/stdc++.h>

using namespace std;
const int N=500;
const int M=998244353;
int n,m,c[N],ans,rp,RP,t[N],a[N],f=1,sum;
string s;
bool cmp(int xx,int yy){
	return xx>yy;
}
void pd(){
	rp=RP=0;
	for(int i=1;i<=n;i++){
		if(rp>=c[a[i]])rp++;
		else if(s[i]=='0')rp++;
		else RP++;
	}
	if(RP>=m){
		ans++;
		ans%=M;
	}
}
void dfs(int d){
	if(d>n){
		pd();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(t[i])continue;
		t[i]=1;
		a[d]=i;
		dfs(d+1);
		t[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)sum++;
		s[n-i+1]=s[n-i];
		if(s[n-i]=='0')f=0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
