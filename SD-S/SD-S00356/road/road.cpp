#include<bits/stdc++.h>
using namespace std;
struct node {
	int date,next,w;
} ar[2400005];
int head[10015],n,m,k,pos,cnt[11],arr[15];
long long ans[10015],sum1[10015];
int qu[110005],fr,la,from[10015],asr[10005],from1[10015],fl[10015];
void bfs() {
	fr=1;
	la=1;
	qu[1]=1;
	for(int i=1;i<=k;i++){
		la++;
		qu[la]=10000+i;
	}
	for(; fr<=la; fr++) {
		for(int i=head[qu[fr]]; i; i=ar[i].next) {
			if(ar[i].date==1)
				continue;
			if(ans[ar[i].date]) {
				if(ans[qu[fr]]+ar[i].w<ans[ar[i].date]) {
					if(fl[ar[i].date]==1)
						sum1[ar[i].date]+=ans[qu[fr]]+ar[i].w-ans[ar[i].date];
					ans[ar[i].date]=ans[qu[fr]]+ar[i].w;
					from[ar[i].date]=qu[fr];
				}
				continue;
			}
			ans[ar[i].date]=ans[qu[fr]]+ar[i].w;
			from[ar[i].date]=qu[fr];
			la++;
			qu[la]=ar[i].date;
		}
		fl[qu[fr]]=1;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		int a,b;
		long long c;
		scanf("%d%d%lld",&a,&b,&c);
		pos++;
		ar[pos].next=head[a];
		ar[pos].date=b;
		ar[pos].w=c;
		head[a]=pos;
		pos++;
		ar[pos].next=head[b];
		ar[pos].date=a;
		ar[pos].w=c;
		head[b]=pos;
	}
	for(int i=1; i<=k; i++) {
		int a,c;
		scanf("%d%d",&a,&c);
		long long sum=0;
		ans[10000+i]=a+c;
		pos++;
		ar[pos].w=c+a;
		for(int j=2;j<=n;j++){
			int b;
			scanf("%d",&b);
			pos++;
			ar[pos].next=head[10000+i];
			ar[pos].date=j;
			ar[pos].w=b;
			head[10000+i]=pos;
		}
	}
	bfs();
	long long ans2=0;
	for(int i=1; i<=n; i++) {
		ans2+=ans[i]-ans[from[i]]+sum1[from[i]];
		if(from[i]>10000) {
			cnt[from[i]-10000]=1;
		}
	}
	for(int i=1; i<=k; i++) {
		if(cnt[i])
			ans2+=ans[i+10000];
	}
	printf("%lld",ans2);
	return 0;
}
