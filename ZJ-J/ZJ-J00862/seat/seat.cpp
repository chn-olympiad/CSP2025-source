#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100005],R=0,ri=0,cnt=0;
bool cmp(int x,int y){
	return x > y;
}
signed main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			ri=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==ri){
					printf("%lld %lld\n",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==ri){
					printf("%lld %lld\n",i,j);
					return 0;
				}
			}
		}
	}
	
    return 0;
}
