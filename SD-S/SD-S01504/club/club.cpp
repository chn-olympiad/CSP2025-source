#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int t;
struct P{
	int a[4];
	int cha,max,cmax;
}p[N];
int n,cnt[4];
long long ans;
void prework(int now){
	p[now].max=1,p[now].cmax=2;
	if(p[now].a[1]<p[now].a[2])swap(p[now].max,p[now].cmax);
	if(p[now].a[3]>p[now].a[p[now].max])p[now].cmax=p[now].max,p[now].max=3;
	else if(p[now].a[3]>p[now].a[p[now].cmax])p[now].cmax=3;
	p[now].cha=p[now].a[p[now].max]-p[now].a[p[now].cmax];
}
bool pd(P a,P b){
	return a.cha>b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<=n;i++)
			p[i].cha=p[i].cmax=p[i].max=0;
		cnt[1]=cnt[2]=cnt[3]=0,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a[1],&p[i].a[2],&p[i].a[3]);
			prework(i);
		}	
		sort(p+1,p+1+n,pd);
		for(int i=1;i<=n;i++){
			if(cnt[p[i].max]<(n>>1))ans+=p[i].a[p[i].max],cnt[p[i].max]++;
			else ans+=p[i].a[p[i].cmax],cnt[p[i].cmax]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0 
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
