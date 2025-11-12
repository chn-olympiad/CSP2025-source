#include<bits/stdc++.h>
using namespace std;
#define N 100001
int t,n,a1,a2,a3,c1[N],c2[N],c3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int winner = 0,p1 = 0,p2 = 0,p3 = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			if(a1 >= a2 && a1 >= a3) winner += a1,c1[++p1] = -(a1-a2<a1-a3?a1-a2:a1-a3);//-min(a1 - a2,a1 - a3);
			else if(a2 >= a1 && a2 >= a3) winner += a2,c2[++p2] = -(a2-a1<a2-a3?a2-a1:a2-a3);//-min(a2 - a1,a2 - a3);
			else if(a3 >= a1 && a3 >= a2) winner += a3,c3[++p3] = -(a3-a1<a3-a2?a3-a1:a3-a2);//-min(a3 - a1,a3 - a2);
		}
		if(p1 > n / 2){
			sort(c1 + 1,c1 + p1 + 1);
			while(p1 > n / 2) winner += c1[p1--];
		}
		else if(p2 > n / 2){
			sort(c2 + 1,c2 + p2 + 1);
			while(p2 > n / 2) winner += c2[p2--];
		}
		else if(p3 > n / 2){
			sort(c3 + 1,c3 + p3 + 1);
			while(p3 > n / 2) winner += c3[p3--];
		}
		printf("%d\n",winner);
	}
	return 0;
}
