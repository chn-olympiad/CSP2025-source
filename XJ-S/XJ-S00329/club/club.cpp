#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++){
			cnt+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		printf("%d",cnt);
	}
	return 0;
} 
