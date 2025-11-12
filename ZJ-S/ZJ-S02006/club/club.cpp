#include<bits/stdc++.h>
using namespace std;
int x[3];
struct node{
	int ai[3];
}a[100005];
bool cmp(node n,node m){
	sort(n.ai,n.ai+3);sort(m.ai,m.ai+3);
	if((n.ai[2]-n.ai[1])==(m.ai[2]-m.ai[1])){
		if((n.ai[1]-n.ai[0])==(m.ai[1]-m.ai[0])){
			return (n.ai[2]>m.ai[2]);
		}
		return (n.ai[1]-n.ai[0])>(m.ai[1]-m.ai[0]);
	}
	return (n.ai[2]-n.ai[1])>(m.ai[2]-m.ai[1]);
}
void init(){
	x[0]=0;x[1]=0;x[2]=0;
}
int mxi(node x){
	int *k=x.ai;k[3]=0;
	int maxi=3;
	for(int i=0;i<3;i++){
		if(k[i]>=k[maxi]){
			maxi=i;
		}
	}
	return maxi;
}
int mni(node x){
	int *k=x.ai;k[3]=20005;
	int mini=3;
	for(int i=0;i<3;i++){
		if(k[i]<=k[mini]){
			mini=i;
		}
	}
	return mini;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	for(;t>0;t--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].ai[0],&a[i].ai[1],&a[i].ai[2]);
		}
		sort(a,a+n,cmp);
		long long ans=0;
		for(int i=0;i<n;i++){
			int l=mni(a[i]),r=mxi(a[i]),mid=3-l-r;
			if(x[r]>=n/2){
				if(x[mid]>=n/2){
					x[l]++;
					ans+=a[i].ai[l];
				}
				else{
					x[mid]++;
					ans+=a[i].ai[mid];
				}
			}
			else{
				x[r]++;
				ans+=a[i].ai[r];
			}
		}
		printf("%d\n",ans);
		init();
	}
	return 0;
}
