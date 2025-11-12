#include<bits/stdc++.h>
#include<map>
using namespace std;
#define ll long long
const int MAXN=500+5;
const int inf=2147483647;
//
int n,m,len,x,ans=1,mod=998244353,w;
int a[MAXN],sn[MAXN],q[MAXN];
string s,s2;
bool one;
map<string,int>mp;
//
void dfs2();
void dfs(int sp){
	if(sp>n){
		dfs2();
	}
	for(int i=1;i<=n;++i){
		if(sn[i]==1)continue;
		sn[i]=1;
		q[++w]=a[i];
		dfs(sp+1);
		sn[i]=0;
		q[w]=0;
		w--;
	}
	return ;
}
void dfs2(){
	int c=0,b=0;
	bool fx=1;
	s2="";
	for(int i=1;i<=n;++i){
		s2+=q[i]+'0';
	}
	if(mp[s2]==1){
		ans++;
		ans=(ans)%mod;
		return ;
	}else if(mp[s2]==-1){
		return ;
	}
	for(int i=1;i<=n;++i){
		if(s[i-1]-'0'==1&&fx==1){
			c++;
			if(c>=m&&fx==1){
				mp[s2]=1;
				ans++;
				ans=(ans)%mod;
				return ;
			}
		}else if(fx==1){
			b++;
			if(b>n-m){
				fx=0;
			}
			while(b>=q[i+1]){
				b++;
				i++;
				if(b>n-m)fx=0;
			}
		}
	}
	
	if(c>=m&&fx==1){
		mp[s2]=1;
		ans++;
		ans=(ans)%mod;
	}else{
		mp[s2]=-1;
	}
}
//
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	len=s.size();
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<len;++i){
		if(s[i]-'0'==0)one=1;
	}
	if(one==0){
		for(int i=1;i<=n;++i){
			ans=(ans*i)%mod;
		}
		printf("%d",ans);
	}else {
		ans=0;
		dfs(1);
		printf("%d",ans%mod);
	}
/*
3 2
101
1 1 2

5 2
10101
1 1 0 2 1
*/
	return 0;
}