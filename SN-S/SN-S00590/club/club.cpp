#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n;
long long a1[N],a2[N],a3[N];
inline bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("club.in", "r",stdin);
	freopen("club.out", "w",stdout);
	scanf("%d",&t);
	while(t--){
		long long ans=0;
		scanf("%d",&n);
		if(n==2){
			for(int i=1;i<=n;i++){
			  scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		    }
		    for(int i=1;i<=n;i++){
		    	for(int j=1;j<=3;j++){
		    		ans+=max(ans,a1[i]+a2[i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		}
		int f1=0,f2=0,f3=0;
		for(int i=1;i<=n;i++){
			if(a2[i]!=0)f2=1;
			else if(a3[i]!=0)f3=1;
			else if(a1[i]!=0)f1=1;
		}
		if(f2!=1&&f3!=1){
			sort(a1+1,a1+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a1[i];
			}
		}else if(f1!=1&&f3!=1){
			sort(a2+1,a2+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a2[i];
			}
		}else if(f1!=1&&f2!=1){
			sort(a3+1,a3+1+n);
			for(int i=1;i<=n/2;i++){
				ans+=a3[i];
			}
		}
		printf("%ld\n",ans);
	}
	return 0;
}
