#include<bits/stdc++.h>
using namespace std;
int a[100005][3],t,n,sum[3],num[3];
long long ans;
struct node{
	int cmaxx;
	int cha;
}b[3][100005];
bool cmp(node x,node y){
	return x.cha<y.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		num[0]=0;
		num[1]=0;
		num[2]=0;
		ans=0;
		sum[0]=0;
		sum[1]=0;
		sum[2]=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
			int fla=max(a[i][0],max(a[i][1],a[i][2]));
			if(fla==a[i][0]){
				num[0]++;
				if(a[i][1]<a[i][2]){
					b[0][num[0]].cmaxx=2;
				}
				else{
					b[0][num[0]].cmaxx=1;
				}
				b[0][num[0]].cha=a[i][0]-a[i][b[0][num[0]].cmaxx];
				sum[0]++;
				ans+=a[i][0];
			}
			else if(fla==a[i][1]){
				num[1]++;
				if(a[i][0]<a[i][2]){
					b[1][num[1]].cmaxx=2;
				}
				else{
					b[1][num[1]].cmaxx=0;
				}
				b[1][num[1]].cha=a[i][1]-a[i][b[1][num[1]].cmaxx];
				sum[1]++;
				ans+=a[i][1];
			}
			else if(fla==a[i][2]){
				num[2]++;
				if(a[i][0]<a[i][1]){
					b[2][num[2]].cmaxx=1;
				}
				else{
					b[2][num[2]].cmaxx=0;
				}
				b[2][num[2]].cha=a[i][2]-a[i][b[2][num[2]].cmaxx];
				sum[2]++;
				ans+=a[i][2];
			}
		}
		int h=n>>1;
		if(sum[0]<=h&&sum[1]<=h&&sum[2]<=h){
			printf("%lld\n",ans);
		}
		else{
			if(sum[0]>h){
				sort(b[0]+1,b[0]+1+num[0],cmp);
				int g=sum[0]-h;
				for(int i=1;i<=g;i++){
					ans-=b[0][i].cha;
				}
			}
			else if(sum[1]>h){
				sort(b[1]+1,b[1]+1+num[1],cmp);
				int g=sum[1]-h;
				for(int i=1;i<=g;i++){
					ans-=b[1][i].cha;
				}
			}
			else{
				sort(b[2]+1,b[2]+1+num[2],cmp);
				int g=sum[2]-h;
				for(int i=1;i<=g;i++){
					ans-=b[2][i].cha;
				}
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
