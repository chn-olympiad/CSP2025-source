#include<bits/stdc++.h>
#define LL long long
#define run(now) cout<<"there"<<now<<endl;
#define N 520
#define mod 998244353
#define LL long long 
using namespace std;
inline LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
LL n,m;
LL s[N],S;
LL c[N],CC;
LL JC[N];
char C[N];
int vis[N];
int whe[N],Ans;
void solve(int now,int l){
	if(n-l<m)return ;
	if(now==n+1){
		Ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			whe[now]=i;
			vis[i]=1;
			int pp;
			if(l>=c[i]||s[now]==0)pp=l+1;
			else pp=l;
			solve(now+1,pp);
			vis[i]=0;
			whe[now]=0;
		}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	JC[0]=1;
	scanf("%s",C+1);
	for(int i=1;i<=n;i++)s[i]=C[i]-'0',S+=s[i],JC[i]=JC[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i]==0)CC++;
	}
	sort(c+1,c+1+n);
	if(m==n){
		if(CC||S!=n)printf("0");
		else printf("%lld\n",JC[n]);
		return 0;
	}
	if(m==1){
		LL ans=0;
		LL now=0,C=1;
		for(int i=1;i<=n;i++){
			if(s[i]==0)continue;
			(ans+=C*(n-(lower_bound(c+1,c+1+n,i)-c)+1)%mod*JC[n-now-1]%mod)%=mod;
			C=C*(lower_bound(c+1,c+1+n,i)-c-1-now)%mod;
			now++;
		}
		printf("%lld",ans);
		return 0;
	}
	solve(1,0);
	cout<<Ans;
	return 0;
}

