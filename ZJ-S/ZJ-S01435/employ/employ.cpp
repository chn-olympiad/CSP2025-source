#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,nx[510],c[510],f[510],ans,A[510],sum,x,s0,w[20],cnt;
char s[510];
const int mo=998244353;
int AA(int x){
	int sum=1,i;
	for(i=1;i<=x;i++){
		sum*=i;
		sum%=mo;
	}
	return sum;
}
void dfs(int id,int sum,int fqsb){
	int i;
	if(sum+n-id+1<m)return ;
	if(sum==m){
		ans+=A[n-id+1];
		ans%=mo;
		return ;
	}
	for(i=1;i<=n;i++)
		if(!f[i]){
			f[i]=1;
			if(c[i]<=fqsb||s[id]=='0')dfs(id+1,sum,fqsb+1);
			else dfs(id+1,sum+1,fqsb);
			f[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>s[i],sum+=(s[i]=='1');
	for(i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	A[0]=1;
	for(i=1;i<=n;i++)A[i]=AA(i);
	if(m==1){
		for(i=1;i<=n;i++)
			if(s[i]=='1')break;
		x=i;
		for(i=1;i<=n;i++)
			if(c[i]>=x-1)break;
		cout<<(n-i+1)*A[n-1]%mo;
		return 0;
	}
	else if(m==n){
		if(sum==n)cout<<A[n];
		else cout<<0;
		return 0;
	}
	else if(sum<m)return cout<<0,0;
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
