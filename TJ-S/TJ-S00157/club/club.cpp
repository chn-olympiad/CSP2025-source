#include<bits/stdc++.h>

using namespace std;
int t,n,cnt=0;
struct node{
	int sum,id,st;
}a[300005];
bool cmp(node a,node b){
	return a.sum>b.sum;
}
int pid[100005],pst[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		cnt=0;
		memset(pid,0,sizeof(pid));
		memset(pst,0,sizeof(pst));
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cnt++;
				scanf("%d",&a[cnt].sum);
				a[cnt].id=i,a[cnt].st=j;
			}
		}
		sort(a+1,a+cnt+1,cmp);
		int r=0,k=1,ans=0;
		while (r<n){
			if (!pid[a[k].id]&&pst[a[k].st]<(n/2)){
				ans+=a[k].sum;
				pid[a[k].id]=1;
				pst[a[k].st]++;
				r++;
			}
			k++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
