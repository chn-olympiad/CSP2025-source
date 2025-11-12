#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,a[N+5][5],num[5],a1[N+5],a2[N+5],a3[N+5],n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long cnt=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt+=a[i][1];
				num[1]++;
				a1[++cnt1]=a[i][1]-max(a[i][2],a[i][3]);
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt+=a[i][2];
				num[2]++;
				a2[++cnt2]=a[i][2]-max(a[i][1],a[i][3]);
			}else{
				cnt+=a[i][3];
				num[3]++;
				a3[++cnt3]=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		if(num[1]>n/2){
			sort(a1+1,a1+cnt1+1);
			for(int i=1;i<=num[1]-n/2;i++){
				cnt-=a1[i];
			}
		}else if(num[2]>n/2){
			sort(a2+1,a2+cnt2+1);
			for(int i=1;i<=num[2]-n/2;i++){
				cnt-=a2[i];
			}
		}else if(num[3]>n/2){
			sort(a3+1,a3+cnt3+1);
			for(int i=1;i<=num[3]-n/2;i++){
				cnt-=a3[i];
			}
		}
		printf("%d\n",cnt);
		num[1]=0;
		num[2]=0;
		num[3]=0;
	}
	return 0;
}
