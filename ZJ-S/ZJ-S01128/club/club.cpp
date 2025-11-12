#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,Limit,Max1,Max2,Max3;
struct node{int a1,a2,a3,cha;}a[N],A1[N],A2[N],A3[N];
inline int read(){
	int c=getchar(),now=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))now=now*10-'0'+c,c=getchar();
	return now;
}
inline bool cmp(node x,node y){return x.cha<y.cha;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		long long ans=0;
		int tot1=0,tot2=0,tot3=0;
		n=read(),Limit=n>>1;
		for(int i=1;i<=n;i++){
			Max1=a[i].a1=read(),
			Max2=a[i].a2=read(),
			Max3=a[i].a3=read();
			if(Max1<Max2)swap(Max1,Max2);
			if(Max1<Max3)swap(Max1,Max3);
			if(Max2<Max3)swap(Max2,Max3);
			a[i].cha=Max1-Max2;
			if(Max1==a[i].a1)A1[++tot1]=a[i];
			else if(Max1==a[i].a2)A2[++tot2]=a[i];
			else A3[++tot3]=a[i];
			ans+=Max1;
		}
		if(tot1>Limit){
			sort(A1+1,A1+tot1+1,cmp);
			int need=tot1-Limit;
			for(int i=1;i<=need;i++)
				ans-=A1[i].cha;
		}
		else if(tot2>Limit){
			sort(A2+1,A2+tot2+1,cmp);
			int need=tot2-Limit;
			for(int i=1;i<=need;i++)
				ans-=A2[i].cha;
		}
		else if(tot3>Limit){
			sort(A3+1,A3+tot3+1,cmp);
			int need=tot3-Limit;
			for(int i=1;i<=need;i++)
				ans-=A3[i].cha;
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}
