#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int T;
int n,x[N+5],y[N+5],z[N+5];
long long s[N+5],sum[N+5];
long long maxx=-1;
struct node {
	int num,id;
}t[N+5];
bool cmp(node a,node b){
	return a.num>b.num; 
}
bool cmp2(int a,int b){
	return a>b;
}
void dfs(int p,int cnt1,int cnt2,int cnt3,long long ans){
	if (p==n+1){
		maxx=max(maxx,ans);
		return ;
	}
	if (ans+(sum[n]-sum[p-1])<=maxx){
		return ;
	}
	if (cnt1<n/2){
		dfs(p+1,cnt1+1,cnt2,cnt3,ans+x[p]);
	}
	if (cnt2<n/2){
		dfs(p+1,cnt1,cnt2+1,cnt3,ans+y[p]);
	}
	if (cnt3<n/2){
		dfs(p+1,cnt1,cnt2,cnt3+1,ans+z[p]);
	}
}
void solve2(){
	maxx=-1;
	for (int i=1;i<=n;i++){
		s[i]=max(max(x[i],y[i]),z[i]);
		sum[i]=sum[i-1]+s[i];
	}
	dfs(1,0,0,0,0);
	printf("%lld\n",maxx);
}
int solve1(){
	scanf("%d",&n);
	bool flag1=1,flag2=1;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		if (!(y[i]==0 && z[i]==0)){
			flag1=0;
		}
		if (!(z[i]==0)){
			flag2=0;
		}
	}
	if (flag1==1){
		sort(x+1,x+n+1,cmp2);
		long long ans=0;
		for (int i=1;i<=ceil(n*1.0/2-0.5);i++){
			ans+=x[i];
		}
		printf("%lld\n",ans);
		return 1;
	}
	if (flag2==1){
		for (int i=1;i<=n;i++){
			t[i].num=abs(x[i]-y[i]);
			t[i].id=i;
		}
		sort(t+1,t+n+1,cmp);
		int cnt1=0,cnt2=0;
		long long ans1=0,ans2=0;
		for (int i=1;i<=n;i++){
			if (cnt1==n/2){
				ans2+=y[i];
				cnt2++; 
				continue;
			}
			if (cnt2==n/2){
				ans1+=x[i];
				cnt1++;
				continue;
			}
			int pos=t[i].id;
			if (x[pos]>y[pos]){
				ans1+=x[pos];
				cnt1++;
			}
			else {
				ans2+=y[pos];
				cnt2++;
			}
		}
		printf("%lld\n",ans1+ans2);
		return 1;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		if (solve1()==0){
			solve2();
		}
	}
	fclose(stdin);
	fclose(stdout); 
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
