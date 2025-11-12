#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,m,ans;
int a[N];
void dfs(int i,int sum,int maxx,bool q){
	if(i>n+1)return;
	if(sum!=0&&sum>maxx*2&&q)ans++;
	dfs(i+1,sum+a[i],max(maxx,a[i]),1);
	dfs(i+1,sum,maxx,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	dfs(1,0,INT_MIN,1);
	printf("%d",ans);
	return 0;
}
