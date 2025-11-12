#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int p,val;
};
struct node1{
	node c[4];	
}a[100005];
bool cmp(node x,node y){
	return x.val>y.val;
}
bool cmp1(node1 x,node1 y){
	return x.c[1].val-x.c[2].val<y.c[1].val-y.c[2].val;
}
vector<int>sst[4];
node1 gl[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=3;i++)sst[i].clear();
		scanf("%d",&n);
		node tmp[4];
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&tmp[1].val,&tmp[2].val,&tmp[3].val);
			tmp[1].p=1;
			tmp[2].p=2;
			tmp[3].p=3;
			sort(tmp+1,tmp+1+3,cmp);
			for(int j=1;j<=3;j++)a[i].c[j]=tmp[j];
			ans+=tmp[1].val;
			sst[tmp[1].p].push_back(i);
		}
		for(int i=1;i<=3;i++){
			if(sst[i].size()>(n>>1)){
				int sz=sst[i].size();
				for(int j=0;j<sz;j++)gl[j]=a[sst[i][j]];
				sort(gl,gl+sz,cmp1);
				for(int j=0;sz-j>(n>>1);j++){
					ans-=gl[j].c[1].val-gl[j].c[2].val;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

