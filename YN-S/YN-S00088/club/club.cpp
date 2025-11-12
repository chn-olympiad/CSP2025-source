#include<bits/stdc++.h>
using namespace std;
int t,n,cnt;
int ma1,ma2,ma3;
int a1[100005],a2[100005],a3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		cnt = 0;
		scanf("%d",&n);
		int flagg = 1;
		for(int i = 1;i <= n;i++){
			scanf("%d %d %d",&a1[i],&a2[i],&a3[i]);
			if(a3[i] == 0){
				flagg = 0;
			}
		}
		if(!flagg){
			for(int i = 1;i <= n;i++){
				cnt += max(a1[i],a2[i]);
			}
			printf("%d\n",cnt);
			break;
		}
		ma1 = n / 2;
		ma2 = n / 2;
		ma3 = n / 2;
		for(int i = 1;i <= n;i++){
			if(max(max(a1[i],a2[i]),a3[i]) == a1[i]){
				if (ma1 != 0){
					cnt += max(max(a1[i],a2[i]),a3[i]);
					ma1 --;
				}
				else{
					cnt += max(a2[i],a3[i]);
				}
			}
			else if(max(max(a1[i],a2[i]),a3[i]) == a2[i]){
				if (ma2 != 0){
					cnt += max(max(a1[i],a2[i]),a3[i]);
					ma2 --;
				}
				else{
					cnt += max(a1[i],a3[i]);
				}
			}
			else if(max(max(a1[i],a2[i]),a3[i]) == a3[i]){
				if (ma3 != 0){
					cnt += max(max(a1[i],a2[i]),a3[i]);
					ma3 --;
				}
				else{
					cnt += max(a2[i],a1[i]);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
