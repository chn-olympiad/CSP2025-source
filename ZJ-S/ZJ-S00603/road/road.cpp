#include<bits/stdc++.h>
using namespace std;
int n,m,k,ant;
int fa[5000010];
struct node{
	int l,r,len;
}s[5000010];
int zx(int x){
	if(fa[x]!=x) return fa[x]=zx(fa[x]);
	return x; 
}
void hbzx(int x,int y){
	x=zx(x);
	y=zx(y);
	if(x!=y){
		fa[x]=y;
	}
}
bool cmp(node x,node y){
	return x.len<y.len;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		s[++ant]={x,y,z};
	}
	sort(s+1,s+ant+1,cmp);
	int cnt=0;
	long long sum=0;
	for(int i=1;i<=ant;i++){
		int ll=zx(s[i].l);
		int rr=zx(s[i].r);
		if(ll==rr) continue;
		hbzx(ll,rr);
		sum+=s[i].len;
		cnt++;
		if(cnt==n-1) break;
	}
	if(k==0){
		printf("%lld",sum);
		return 0;
	}
	int nnow=n;
	long long ooo=0;
	int maxx=0;
	for(int i=1;i<=k;i++){
		int c,antt=ant;
		long long ans=ooo;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			fa[j]=j;
			int x;
			scanf("%d",&x);
			s[++antt]={j,nnow+1,x};
		}
		for(int j=n+1;j<=nnow+1;j++) fa[j]=j;
		sort(s+1,s+antt+1,cmp);
		int cntt=0,f=0;
		for(int j=1;j<=antt;j++){
			int ll=zx(s[j].l);
			int rr=zx(s[j].r);
			if(ll==rr) continue;
			hbzx(ll,rr);
			ans+=s[j].len;
			if(ans>sum){
				f=1;
				break;
			}
			cntt++;
			if(cntt==nnow) break;
		}
		if(f==1) continue;
		ans+=c;
		if(ans<sum){
			sum=ans;
			ooo+=c;
			maxx=max(maxx,c);
			ant=antt;
			nnow++;
		}
		else if(ans==sum){
			if(c<maxx){
				ooo-=maxx-c;
			}
		}
	}
	cout<<sum;
	return 0;
}
