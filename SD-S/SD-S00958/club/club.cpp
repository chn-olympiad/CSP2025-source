#include <bits/stdc++.h>
using namespace std;
int t,n;
int a1,a2,a3;
int c1[100005],c2[100005],c3[100005];
int cnt1,cnt2,cnt3;
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t>0){
		t--;
		cnt1=0,cnt2=0,cnt3=0,ans=0;
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		memset(c3,0,sizeof(c3));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			if(a1>=a2&&a1>=a3){
				ans+=a1;
				c1[++cnt1]=min(a1-a2,a1-a3);
			}
			else if(a2>=a1&&a2>=a3){
				ans+=a2;
				c2[++cnt2]=min(a2-a1,a2-a3);
			}
			else if(a3>=a1&&a3>=a2){
				ans+=a3;
				c3[++cnt3]=min(a3-a1,a3-a2);
			}
		}
		if(cnt1>n/2){
			sort(c1+1,c1+1+cnt1);
			int z=cnt1-n/2;
			for(int i=1;i<=z;i++)ans-=c1[i];
		}
		else if(cnt2>n/2){
			sort(c2+1,c2+1+cnt2);
			int z=cnt2-n/2;
			for(int i=1;i<=z;i++)ans-=c2[i];
		}
		else if(cnt3>n/2){
			sort(c3+1,c3+1+cnt3);
			int z=cnt3-n/2;
			for(int i=1;i<=z;i++)ans-=c3[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
