#include <bits/stdc++.h>
using namespace std;
int t , n , a1[100005] , a2[100005] , a3[100005] , sum;
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i = 1 ; i <= n ; i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			sum += max(a1[i],max(a2[i],a3[i]));
		}
		printf("%d\n",sum);
	}
	return 0;
}
