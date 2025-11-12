#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long x=0,g=1;
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') g=-1,c=getchar();
	while(c>='0' && c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	return x*g;
}
long long n,T;
long long s1,s2,s3,s[4][100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		cin>>n;ans=0;s1=s2=s3=0;
		memset(s,0,sizeof(s));
		for(long long i=1;i<=n;i++){
			long long a=read(),b=read(),c=read(),maxn;
			maxn=max(a,max(b,c));
			ans+=maxn;
			if(maxn==a)
				s[1][++s1]=a-max(b,c);
			else if(maxn==b)
				s[2][++s2]=b-max(a,c);
			else if(maxn==c)
				s[3][++s3]=c-max(a,b);
		}
		if(s1>n/2){
			sort(s[1]+1,s[1]+s1+1);
			for(long long i=1;i<=s1-n/2;i++) ans-=s[1][i];
		}else if(s2>n/2){
			sort(s[2]+1,s[2]+s2+1);
			for(long long i=1;i<=s2-n/2;i++) ans-=s[2][i];
		}else if(s3>n/2){
			sort(s[3]+1,s[3]+s3+1);
			for(long long i=1;i<=s3-n/2;i++) ans-=s[3][i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}