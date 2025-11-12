#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e6,N=3e4;
int n,m,ans1,kk,fa[N],cc[20];
struct stu{
	int u,v,val;
	stu(){
		u=0;v=0;val=0;
	}
}t[MAXN];
int getf(int x){
	if(fa[x]==x)return x;
	else return fa[x]=getf(fa[x]);
}
bool cmp(stu x,stu y){
	return x.val<y.val;
} 
void kkk(){
	sort(t+1,t+m+1,cmp);
	for(int i=1;i<=2*n+kk;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int p=getf(t[i].u),q=getf(t[i].v);
		if(p==q)continue;
		ans1+=t[i].val;
		fa[p]=q;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&kk);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		t[i].u=x;
		t[i].v=y;
		t[i].val=z;
	}
	for(int i=1;i<=kk;i++){
		scanf("%lld",&cc[i]);
		for(int j=1,x;j<=n;j++){
			scanf("%lld",&x);
			t[++m].u=i+n;
			t[m].v=j;
			t[m].val=x;
		}
	}
	kkk();
	printf("%lld\n",ans1);
	return 0;
}