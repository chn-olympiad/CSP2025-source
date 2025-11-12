//石丰源 SN_S00556 安康市长兴综合高级中学 
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define maxn int(1e5+10)
#define ll long long
typedef pair<int,int> pii;
inline int read(){
	char c=getchar(); int t=1,k=0;
	while('0'>c||c>'9'){if(c=='-') t=-1; c=getchar();}
	while('0'<=c&&c<='9'){k=k*10+(c^48); c=getchar();}
	return t*k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		int n=read(),t1[maxn],t2[maxn],t3[maxn],num1=0,num2=0,num3=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			int a=read(),b=read(),c=read();
			int maxx=max(a,max(b,c));
			ans+=maxx;
			if(maxx==a) t1[++num1]=min(maxx-b,maxx-c);
			else if(maxx==b) t2[++num2]=min(maxx-a,maxx-c);
			else t3[++num3]=min(maxx-a,maxx-b);
		}
		if(num1>n/2){
			sort(t1+1,t1+num1+1);
			for(int i=1;i<=num1-n/2;i++) ans-=t1[i];
		}
		else if(num2>n/2){
			sort(t2+1,t2+num2+1);
			for(int i=1;i<=num2-n/2;i++) ans-=t2[i];
		}
		else if(num3>n/2){
			sort(t3+1,t3+num3+1);
			for(int i=1;i<=num3-n/2;i++) ans-=t3[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
