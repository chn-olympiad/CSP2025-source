#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const int MOD=998244353;
int n,m,c[N],a[N];
string s;
ll ans=1,res;
bool f[N];
void check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]){
		    cnt++;continue;
		}
		if(s[i]=='0')cnt++;
	}
	if(n-cnt>=m)res++;
	res%=MOD;
}
void dfs(int x){
	for(int i=1;i<=n;i++){
		if(!f[i]){
			a[x]=i;
			f[i]=1;
			if(x==n)check();
			else dfs(x+1);
			f[i]=0;
		}
	}
}
bool checkA(){
	for(int i=1;i<s.size();i++){
		if(s[i]!='1')return 0;
	}
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
	cin>>s;s=" "+s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(n<=18){
		dfs(1);
	    printf("%lld",res);
	    return 0;
	}
	if(checkA()){
		for(int i=1;i<=n;i++)ans=ans*i%MOD;
		printf("%lld",ans);
	}
	return 0;
}

