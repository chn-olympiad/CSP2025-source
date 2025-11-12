#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][5],b[N][5];
int sum[5],ans;
struct mzy{
	int num,id;
}t[N];
bool mycmp(mzy x,mzy y) {return x.num>y.num;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(sum,0,sizeof(sum));
		ans=0;scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			b[i][1]=1;b[i][2]=2;b[i][3]=3;
			if(a[i][1]<a[i][2]){
				swap(a[i][1],a[i][2]);
				swap(b[i][1],b[i][2]);
			} 
			if(a[i][1]<a[i][3]){
				swap(a[i][1],a[i][3]);
				swap(b[i][1],b[i][3]);
			} 
			if(a[i][2]<a[i][3]){
				swap(a[i][2],a[i][3]);
				swap(b[i][2],b[i][3]);
			} 
			t[i].id=i;
			t[i].num=a[i][1]-a[i][2];
		}
		sort(t+1,t+1+n,mycmp);
		for(int i=1;i<=n;i++){
			if(sum[b[t[i].id][1]]<n/2) {
				sum[b[t[i].id][1]]++;
				ans+=a[t[i].id][1];
			}
			else {
				sum[b[t[i].id][2]]++;
				ans+=a[t[i].id][2];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
