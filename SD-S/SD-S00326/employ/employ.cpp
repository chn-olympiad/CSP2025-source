#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=510,mod=998244353;
int n,m;
int c[N];
LL fac[N];
string s;
bool ok=1,okc=1;
int a[N];
bool st[N];
LL res;

void cacl(){
	int cnt=0,rem=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]){
			cnt++;
			continue;
		}
		if(s[i]=='1') rem++;
		else cnt++;
	}
	if(rem>=m) res=(res+1)%mod;
}

void dfs(int l){
	if(l>n){
		cacl();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			st[i]=1;
			a[l]=i;
			dfs(l+1);
			st[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]<=0) okc=0;
	}
	
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*(LL)i%mod;
	}
	
	for(int i=1;i<=n;i++)
		if(s[i]!='1'){
			ok=0;
			break;
		}
	if(m==n){
		if(ok&&okc) printf("%lld\n",fac[n]);
		else puts("0");
		return 0;
	}
	
	dfs(1);
	
	printf("%lld\n",res);
	
	return 0;
}
