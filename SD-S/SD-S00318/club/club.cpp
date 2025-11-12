#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
long long a[N][3],mx,aa[3][N],c[3],p[3];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		p[0]=p[1]=p[2]=0;
		c[0]=c[1]=c[2]=0;
		mx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				mx+=a[i][0];
				p[0]++;
				aa[0][++c[0]]=max(a[i][1]-a[i][0],a[i][2]-a[i][0]);
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				mx+=a[i][1];
				p[1]++;
				aa[1][++c[1]]=max(a[i][0]-a[i][1],a[i][2]-a[i][1]);
			}
			else {
				mx+=a[i][2];
				p[2]++;
				aa[2][++c[2]]=max(a[i][0]-a[i][2],a[i][1]-a[i][2]);
			}
		}
		if(p[0]>n/2){
			sort(aa[0]+1,aa[0]+1+c[0],cmp);
			for(int i=1;i<=p[0]-n/2;i++)
				mx+=aa[0][i];
		}
		else if(p[1]>n/2){
			sort(aa[1]+1,aa[1]+1+c[1],cmp);
			for(int i=1;i<=p[1]-n/2;i++)
				mx+=aa[1][i];
		}
		else if(p[2]>n/2){
			sort(aa[2]+1,aa[2]+1+c[2],cmp);
			for(int i=1;i<=p[2]-n/2;i++)
				mx+=aa[2][i];
		}
		printf("%lld\n",mx);
	}
	return 0;
}
