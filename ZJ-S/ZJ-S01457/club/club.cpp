#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct person{
	int first,second,third;
}a[N];
int delta1[N],delta2[N],delta3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,ans=0,cnt1=0,cnt2=0,cnt3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].first,&a[i].second,&a[i].third);
		}
		for(int i=1;i<=n;i++){
			if(a[i].first>=a[i].second&&a[i].first>=a[i].third){
				delta1[++cnt1]=a[i].first-max(a[i].second,a[i].third);
				ans+=a[i].first;
			}
			else if(a[i].second>=a[i].first&&a[i].second>=a[i].third){
				delta2[++cnt2]=a[i].second-max(a[i].first,a[i].third);
				ans+=a[i].second;
			}
			else{
				delta3[++cnt3]=a[i].third-max(a[i].first,a[i].second);
				ans+=a[i].third;
			}
		}
		if(cnt1>n/2){
			sort(delta1+1,delta1+cnt1+1);
			int num=cnt1-n/2;
			for(int i=1;i<=num;i++){
				ans-=delta1[i];
			}
		}
		if(cnt2>n/2){
			sort(delta2+1,delta2+cnt2+1);
			int num=cnt2-n/2;
			for(int i=1;i<=num;i++){
				ans-=delta2[i];
			}
		}
		if(cnt3>n/2){
			sort(delta3+1,delta3+cnt3+1);
			int num=cnt3-n/2;
			for(int i=1;i<=num;i++){
				ans-=delta3[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}