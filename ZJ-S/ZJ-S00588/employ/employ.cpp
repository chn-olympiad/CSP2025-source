#include <bits/stdc++.h>
#define ri register int
using namespace std;

inline int read(){
	int ret=0,f=1; char c;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	while(isdigit(c)) ret=(ret<<1)+(ret<<3)+(c^48),c=getchar();
	return ret*f;
}

int n,m,c[10010],p[10010],ans,sum,tot,na[10010];
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	n=read(),m=read();
	cin>>s;
	
	bool flag=1;
	for(ri i=0;i<s.size();i++) flag&=s[i]=='1';
	if(flag && n>10){
		long long sum=1;
		for(ri i=1;i<=n;i++) sum=sum*i%(long long)(998244353);
		printf("%lld\n",sum);
		return 0;
	}
	
	for(ri i=0;i<n;i++) c[i]=read();
	na[0]=1-(s[0]-'0');
	for(ri i=1;i<n;i++) na[i]=(1-(s[i]-'0'));
	for(ri i=0;i<n;i++) p[i]=i;
	ans=0;
	do{
		sum=0,tot=0;
		for(ri i=0;i<n;i++){
			if(na[i]) tot++;
			else{
				if(tot>=c[p[i]]) tot++;
			}
		}
		ans+=(n-tot)>=m;
	}while(next_permutation(p,p+n));
	printf("%d\n",ans);

	return 0;
}
