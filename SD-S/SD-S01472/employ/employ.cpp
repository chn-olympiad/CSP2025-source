//[HRH]'s Code
#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
const long long Q=998244353;
long long n,m,T,op;
long long a[N],mp[N],f[N];
char s[N];
void dfs(int x){
	if(x==n+1){
		long long k=0,p=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||p>=f[i])p++;
			else k++;
		}if(k>=m)op++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(mp[i])continue;
		f[x]=a[i];mp[i]=1;
		dfs(x+1);mp[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(1);printf("%lld",op);
	return 0;
}
/**/

