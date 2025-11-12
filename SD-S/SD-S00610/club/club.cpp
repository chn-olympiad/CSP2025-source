#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct node{
	int first,second,third;
}a[N];
bool cmp(node a,node b){return a.first>b.first;}
int ans[N];
int resans=0;
void dfs(int cnt,int co1,int co2,int co3){
	if(cnt==n){
		int tmpa=0;
		for(int i=1;i<=n;i++){
			if(ans[i]==1) tmpa+=a[i].first;
			else if(ans[i]==2) tmpa+=a[i].second;
			else if(ans[i]==3) tmpa+=a[i].third;
		}
		resans=max(resans,tmpa);
		return;
	}
	if(co1>n/2) return;
	if(co2>n/2) return;
	if(co3>n/2) return;
	for(int i=1;i<=3;i++){
		ans[cnt+1]=i;
		dfs(cnt+1,co1+(i==1),co2+(i==2),co3+(i==3));
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		resans=-INT_MAX;
		bool s2=1,s3=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].first,&a[i].second,&a[i].third);
			if(a[i].second) s2=0;
			if(a[i].third) s3=0;
		}
		if(s2&&s3){
			sort(a+1,a+n+1,cmp);
			long long s=0;
			for(int i=1;i<=n/2;i++) s+=a[i].first;
			printf("%lld\n",s);
		}else{
			dfs(0,0,0,0);
			printf("%d\n",resans);
		}
	}
	return 0;
}

