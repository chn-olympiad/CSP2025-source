#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int T,n,ans,sum[5];
struct node{
	int w,x;
}a[5];
int cmp(node x,node y){
	return x.w<y.w;
}
priority_queue<int> q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(sum,0,sizeof(sum));
		ans=0;
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[j].w);
				a[j].x=j;
			}
			sort(a+1,a+4,cmp);
			q[a[3].x].push(a[2].w-a[3].w);
			ans+=a[3].w;
			sum[a[3].x]++;
		}
		for(int i=1;i<=3;i++){
			while(sum[i]>(n/2)){
				ans+=q[i].top();
				q[i].pop();
				sum[i]--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

