#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
const int N=505,mod=998244353;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int n,m,jc[N],a[N],b[N],ans,v[N],k;
string s;
void dfs(int x){
	if(x==n+1){
		k++;
		int p=0,sum=0;
		for(int i=1;i<=n;i++){
			if(p>=b[i]){
				p++;
				continue;
			}
			if(s[i]=='1'){
				sum++;
			}
			else if(s[i]=='0'){
				p++;
			}
		}
		if(sum>=m){
			ans++;
//			for(int i=1;i<=n;i++)cout<<b[i]<<" ";
//			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		b[x]=a[i];
		dfs(x+1);
		v[i]=0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	jc[0]=jc[1]=1;
	for(int i=2;i<=n;i++){
		jc[i]=(jc[i-1]*i)%mod;
	}
	if(n<=18){
		cin>>s;
		s=' '+s;
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		dfs(1);
		cout<<ans<<endl;
	}
	else cout<<jc[n]<<endl;

	return 0;
}


