#include<bits/stdc++.h>
#define pd emplace_back
using namespace std;
const int maxn=1e5+500;
int t,n,a[maxn][4],ans,sum,k,len;
vector<int>v[4];
int get(int x,int k){
	if(k==1)return a[x][k]-max(a[x][2],a[x][3]);
	if(k==2)return a[x][k]-max(a[x][1],a[x][3]);
	return a[x][k]-max(a[x][1],a[x][2]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),ans=0,k=0;
		for(int i=1;i<=3;i++)v[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
			if(a[i][1]>=max(a[i][2],a[i][3]))v[1].pd(i),ans+=a[i][1];
			else if(a[i][2]>=max(a[i][1],a[i][3]))v[2].pd(i),ans+=a[i][2];
			else v[3].pd(i),ans+=a[i][3];
//		for(int i:v[1])printf("%d ",i);
//		printf("\n");
//		for(int i:v[2])printf("%d ",i);
//		printf("\n");
//		for(int i:v[3])printf("%d ",i);
//		printf("\n");
		for(int i=1;i<=3;i++)
			if(v[k].size()<v[i].size())k=i;
		n/=2,len=v[k].size();
		sort(v[k].begin(),v[k].end(),[](int q1,int q2){return get(q1,k)<get(q2,k);});
		for(int i=0;len-i>n;i++)ans-=get(v[k][i],k);
		printf("%d\n",ans);
	}
	return 0;
}




