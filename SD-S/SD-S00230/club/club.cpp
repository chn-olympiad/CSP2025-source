#include<bits/stdc++.h>
using namespace std;
struct node{
	int max1,max1i,max2,max2i,i;
}a[100010];
int n,t;
long long ans;
struct nb{
	int val,i;
}k[4];
bool cmp(nb a,nb b){
	return a.val>b.val;
}
bool cmp2(node a,node b){
	if((a.max1-a.max2)==(b.max1-b.max2)){
		return a.max1i>b.max1i;
	}
	return (a.max1-a.max2)>(b.max1-b.max2);
}
int b[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&k[1],&k[2],&k[3]);
			k[1].i=1,k[2].i=2,k[3].i=3;
			sort(k+1,k+4,cmp);
			a[i].max1=k[1].val;
			a[i].max2=k[2].val;
			a[i].max1i=k[1].i;
			a[i].max2i=k[2].i;
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(b[a[i].max1i]>=n/2){
				ans+=a[i].max2;
				b[a[i].max2i]++;
			}else{
				ans+=a[i].max1;
				b[a[i].max1i]++;
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
    return 0;
}

