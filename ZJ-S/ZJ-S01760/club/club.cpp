#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+5;
struct abc{int n1,n2,n3;}a[MAXN*3];
int t,n,nm[3],ans,flag;
void dfs(int p,int sum){
	if (p>n){
		ans=max(ans,sum);
		return;
	}
	if (nm[0]<n/2){
		nm[0]++;
		dfs(p+1,sum+a[p].n1);
		nm[0]--;
	}
	if (nm[1]<n/2){
		nm[1]++;
		dfs(p+1,sum+a[p].n2);
		nm[1]--;
	}
	if (nm[2]<n/2){
		nm[2]++;
		dfs(p+1,sum+a[p].n3);
		nm[2]--;
	}
}
bool cmp(abc n4,abc n5){
	return n4.n1-n4.n2>n5.n1-n5.n2;
}
void solve(){
	scanf("%d",&n);
	ans=0;
	flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].n1,&a[i].n2,&a[i].n3);
		if (a[i].n3!=0) flag=0;
	}
	if (flag==1){
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++)ans+=a[i].n1;
		for(int i=n/2+1;i<=n;i++)ans+=a[i].n2;
	}else dfs(1,0);
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
