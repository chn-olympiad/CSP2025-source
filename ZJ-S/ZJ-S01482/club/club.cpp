#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,a[N],b[N],c[N],ans,cnt1,cnt2,cnt3;
struct node{
	int a,b,c,i;
}d[N],d1[N],d2[N];//状压全排列
inline cmp1(node a,node b){
	if (a.a==b.a) return a.b>b.b;
	return a.a>b.a;
}
inline cmp2(node a,node b){
	if (a.b==b.b) return a.a>b.a;
	return a.b>b.b;
}
void solve2(){
	ans=0;
	if (!d[1].b){
		sort(d+1,d+1+n,cmp1);
		for (register int i=1;i<=n/2;i++) ans+=d[i].a;
		printf("%d\n",ans);
	}
	else{//ab各一半
		for (register int i=1;i<=n;i++) d1[i]=d[i],d2[i]=d[i];
		sort(d+1,d+1+n,cmp1);
		for (register int i=1;i<=n/2;i++) ans+=d[i].a,d[i].i=0;
		for (register int i=n/2;i<=n;i++) ans+=d[i].b;
		int y=d[n/2].a;
		sort(d+1,d+1+n,cmp2);
		for (register int i=1;i<=n/2;i++)
			if (!d[i].i) ans=max(ans,ans-d[i].a+d[i].b);
			else ans=max(ans,ans-d[n/2].a+d[i].b);//
		printf("%d\n",ans);
	}
	return;
}
inline void dfs(int x,int cnt){
	if (x>n){
		ans=max(ans,cnt);
		return;
	}
	if (cnt1<n/2){
		cnt1++;
		dfs(x+1,cnt+d[x].a);
		cnt1--;
	}
	if (cnt2<n/2){
		cnt2++;
		dfs(x+1,cnt+d[x].b);
		cnt2--;
	}
	if (cnt3<n/2){
		cnt3++;
		dfs(x+1,cnt+d[x].c);
		cnt3--;
	}
	return;
}
inline void solve1(){
	ans=0,cnt1=0,cnt2=0,cnt3=0;
	dfs(0,0);
	printf("%d\n",ans);
}
inline void solve(){//c=0;//#3
	scanf("%d",&n);
	for (register int i=1;i<=n;i++){
		d[i].i=i;
		scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
	}
	if (n<=30) solve1();
	else solve2();
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--) solve();
	return 0;
}