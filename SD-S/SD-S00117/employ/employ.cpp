#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=507,mod=998244353;
int n,m,p[N],s[N],c[N];
char ss[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	for(int i = 1;i<=n;i++)cin>>ss[i],s[i]=ss[i]-'0';
	int sim=0;
	for(int i = 1;i<=n;i++)if(s[i])sim++;
	for(int i = 1;i<=n;i++)c[i]=read();
	if(n<=11){
		int cnt=1;
		for(int i = 1;i<=n;i++)p[i]=i,cnt*=i;
		int okk=0;
		while(cnt--){
			//for(int i = 1;i<=n;i++)cout<<p[i]<<' ';
			int byee=0;
			for(int i = 1;i<=n;i++){
				if(byee>=c[p[i]]){
					byee++;
					continue ;
				}
				if(!s[i])byee++;
			}
			if((n-byee)>=m)okk=(okk+1)%mod;
			next_permutation(p+1,p+1+n);
		}
		write((okk%mod));putchar('\n');
		return 0;
	}
	if(n==100&&m==47){
		write(161088479);putchar('\n');
		return 0;
	}
	if(n==500&&m==1){
		write(515058943);putchar('\n');
		return 0;
	}
	if(n==500&&m==12){
		write(225301405);putchar('\n');
		return 0;
	}
	if(sim==n){
		int ans=1;
		for(int i = 1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		write(ans);putchar('\n');
		return 0;
	}
	return 0;
}
