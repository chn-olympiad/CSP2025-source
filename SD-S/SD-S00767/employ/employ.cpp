#include<bits/stdc++.h>
#define int long long

const int N=114514;
const int mod=998244353;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*f;
}
int n,m,si[N],c[N],a[N],ans=0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	std::string s;
	std::cin>>s;
	for(int i=1;i<=n;++i){
		si[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;++i){
		c[i]=read();
	}
	for(int i=1;i<=n;++i)a[i]=i;
	do{
		int lose=0;
		for(int i=1;i<=n;++i){
			if(si[i]==0||lose>=c[a[i]]){lose++;}
		}	
		if(n-lose>=m)ans=(ans+1)%mod;
	}while(std::next_permutation(a+1,a+1+n));
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
