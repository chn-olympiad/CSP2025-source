#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int club[5];
int a[100005];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int sat1,sat2,sat3;
			scanf("%d%d%d",&sat1,&sat2,&sat3);
			a[i]=sat1;
		}
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--){
			ans+=a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}