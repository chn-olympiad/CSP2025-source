#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=20;
int n,m,c[N];
bool s[N];
ll ans;
ll read(){
	char c=getchar();
	ll s=0,p=1;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
void dfs(int x,int fai,int suc){
	if(x==(n+1)){
		if(suc>=m) ans++;
		return;
	}
	if(fai>=c[x]||!s[x]) dfs(x+1,fai+1,suc);
	else dfs(x+1,fai,suc+1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c=getchar();
		if(c=='1') s[i]=1;
		else s[i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	do{
		dfs(1,0,0);
	}while(next_permutation(c+1,c+1+n)&&next_permutation(s+1,s+1+n));
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
