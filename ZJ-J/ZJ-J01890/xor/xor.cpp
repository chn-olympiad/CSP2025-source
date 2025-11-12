#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,R[N],maxx=-1,K[25],now,sum[N][25],num,z,da,la;
vector<int> a[N];
void chai(int x,int b){
	while(x!=0){
		a[b].push_back(x%2);
		x/=2;
		
	}
	da=a[b].size();
	if(da>maxx){
		maxx=a[b].size();
	}
	return;
}
struct Node{
	int l,r;
};
vector<Node> ans;
bool can(int le,int ri){
	for(int i=0;i<maxx;i++){
		if(K[i]!=(sum[ri][i]-sum[le-1][i])%2){
			return 0;
		}
	}
	return 1;
}
bool cmp(Node x,Node y){
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&R[i]);
		chai(R[i],i);
	}
	if(k==0||k==1){
		num=0;
		for(int i=1;i<=n;i++){
			if(R[i]==k){
				num++;
			}
		}
		printf("%d",num);
		return 0;
	}
	else{
		for(int i=0;i<=n;i++){
			da=a[i].size();
			while(da<maxx){
				a[i].push_back(0);
				da=a[i].size();
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<maxx;j++){
				sum[i][j]=sum[i-1][j]+a[i][j];
			}
		}
		now=0;
		while(k!=0){
			K[now++]=k%2;
			k/=2;
		}
		if(now<maxx){
			for(int i=1;i<=maxx-now+1;i++){
				K[now++]=0;
			}
		}
		la=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j>la;j--){
				if(can(j,i)){
					ans.push_back({j,i});
					la=i;
					break;
				}
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		z=0;
		for(int i=0;i<ans.size();i++){
			if(ans[i].l>z){
				num++;
				z=ans[i].r;
			}
		}
		printf("%d",num);
	}
	return 0;
}
