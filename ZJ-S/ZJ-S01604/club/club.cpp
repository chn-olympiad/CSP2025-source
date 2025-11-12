#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+5;
long long t,n,sum[5][maxn],vis[5],cnt[5],res,sumc[maxn];
long long ans;
struct node{
	long long a,b,c,fm,sm,fc,sc,cha;
}x[maxn];
struct student{
	long long f,s;
}r[maxn];
bool cmp(node a,node b){
	if(a.fm==b.fm){
		return a.cha<b.cha;
	}
	return a.fm>b.fm;
}
bool cmp1(student a,student b){
	if(a.f-a.s==b.f-b.s){
		return a.f>b.f;
	}
	return (a.f-a.s)>(b.f-b.s);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>t;
	while(t--){
		cin>>n;
		memset(sum,0,sizeof sum);
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		memset(sumc,0,sizeof sumc);
		res=0;
		ans=0;
		long long flag=0;
		for(long long i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b&&x[i].b>=x[i].c){
				x[i].fm=x[i].a;
				x[i].fc=1;
				x[i].sm=x[i].b;
				x[i].sc=2;
			}
			else if(x[i].a>=x[i].c&&x[i].c>=x[i].b){
				x[i].fm=x[i].a;
				x[i].fc=1;
				x[i].sm=x[i].c;
				x[i].sc=3;
			}
			else if(x[i].b>=x[i].a&&x[i].a>=x[i].c){
				x[i].fm=x[i].b;
				x[i].fc=2;
				x[i].sm=x[i].a;
				x[i].sc=1;
			}
			else if(x[i].b>=x[i].c&&x[i].c>=x[i].a){
				x[i].fm=x[i].b;
				x[i].fc=2;
				x[i].sm=x[i].c;
				x[i].sc=3;
			}
			else if(x[i].c>=x[i].a&&x[i].a>=x[i].b){
				x[i].fm=x[i].c;
				x[i].fc=3;
				x[i].sm=x[i].a;
				x[i].sc=1;
			}
			else if(x[i].c>=x[i].b&&x[i].b>=x[i].a){
				x[i].fm=x[i].c;
				x[i].fc=3;
				x[i].sm=x[i].b;
				x[i].sc=2;
			}
			x[i].cha=x[i].fm-x[i].sm;
		}
		sort(x+1,x+n+1,cmp);
		for(long long i=1;i<=n;i++){
			if(vis[x[i].fc]+1<=n/2){
				vis[x[i].fc]++;
				ans+=x[i].fm;
				sum[x[i].fc][++cnt[x[i].fc]]=x[i].cha;
			}
			else{
				flag=x[i].fc;
				r[++res].f=x[i].fm;
				r[res].s=x[i].sm;
			}
		}
		if(flag){
			long long s=0,ss=0,ms=0;
			sort(r+1,r+res+1,cmp1);
			sort(sum[flag]+1,sum[flag]+cnt[flag]+1);
			for(long long i=1;i<=res;i++){
				s+=r[i].s;
			}
			ms=s;
			for(long long i=1;i<=min(res,cnt[flag]);i++){
				s-=r[i].s;
				s+=r[i].f-sum[flag][i];
				ms=max(ms,s);
			}
			ans+=ms;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
