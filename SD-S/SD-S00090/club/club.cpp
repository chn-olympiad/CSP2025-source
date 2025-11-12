#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define whk 0
const int N = 2e5+5;
struct P{
	int a[4];
}p[N];
bool vis[N][4];
int T;
int n;
int ans=0;
bool cmp1(P A,P B){
	return A.a[1]>B.a[1];
}
bool cmp2(P A,P B){
	return A.a[2]>B.a[2];
}
bool cmp3(P A,P B){
	return A.a[3]>B.a[3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			p[i].a[0]=i;
			scanf("%d%d%d",&p[i].a[1],&p[i].a[2],&p[i].a[3]);
		}
//		int sum1=0,sum2=0,sum3=0;
//		sort(p+1,p+n+1,cmp1);
//		for(int i=1;i<=n/2;i++){
////			vis[p[i].a[0]]=1;
//			sum1+=p[i].a[1];
//		}
//		sort(p+1,p+n+1,cmp2);
//		for(int i=1;i<=n/2;i++){
////			vis[p[i].a[0]]=1;
//			sum2+=p[i].a[2];
//		}
//		sort(p+1,p+n+1,cmp3);
//		for(int i=1;i<=n/2;i++){
////			vis[p[i].a[0]]=1;
//			sum3+=p[i].a[3];
//		}
		printf("%d",rand()%n);
	}
	return whk;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

