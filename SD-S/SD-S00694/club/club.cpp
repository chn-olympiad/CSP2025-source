#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long li666;
const int maxn666=500005;
int t666;
int n666;
int a666[maxn666][3];
int ix666[maxn666];
int jx666[maxn666];
int kx666[maxn666];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t666);
	while(t666--) {
		scanf("%d", &n666);
		jx666[0]=0;
		jx666[1]=0;
		jx666[2]=0;
		li666 ans666=0;
		for(int i666=1; i666<=n666; i666++) {
			ix666[i666]=0;
			kx666[i666]=2;
			for(int j666=0; j666<3; j666++) {
				scanf("%d", &a666[i666][j666]);
				if(a666[i666][j666]>a666[i666][ix666[i666]]) ix666[i666]=j666;
			}
			for(int j666=0; j666<3; j666++) {
				if((a666[i666][j666]>a666[i666][kx666[i666]])&&(j666!=ix666[i666])) kx666[i666]=j666;
			}
			jx666[ix666[i666]]++;
			kx666[i666]=a666[i666][ix666[i666]]-a666[i666][kx666[i666]];
			ans666+=a666[i666][ix666[i666]];
		}
		int ly666=0;
		for(int j666=1; j666<3; j666++) {
			if(jx666[j666]>jx666[ly666]) ly666=j666;
		}
		sort(kx666+1, kx666+n666+1);
		int lm666=jx666[ly666]-(n666>>1);
		for(int i888666=1; i888666<=lm666; i888666++) ans666-=kx666[i888666];
		printf("%lld\n", ans666);
	} 
	return 0;
}
//T1: A / club
//一道比较水的题目
//要求也不高
//还真就应了 sto_lxl_orz 了
//T1真 ** 就黄色水（s**t, 744）题 
//快！边做 T1边想 T2!!! 
//好了，T1 即将结束 15：57 
//16:00 T1 End
//16:05 T1 CHECKEND TO CLUB.CPP
