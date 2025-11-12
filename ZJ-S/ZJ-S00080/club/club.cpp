#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);(i)<=(k);i++)
#define R(i,j,k) for(int i=(j);(i)>=(k);i--)
#define a1 jasfbuiwqbfjasufhgcaiiiiii
#define a2 auifhhhhhfjewooifjasdojfijfsdhfhh
#define a3 joijvihiicccc
#define DA kfojasfijjjjjjjjjjjj
#define T hjfashiuahhhhhhhhhhuhuhu
#define n asfafsffffffffffffffffffffff
#define mybol1 fwqfffffffffffffwwwwwwwwwwwwwwrrrrrrr
#define mybol2 fwqfffffffwwdqwwwwwwwwwwrrrrrrr
#define mybol3 fwqffffffffwwwwwwwwwrtrrwerwefdsffffrrrrrrr
#define ans iufuhuihuihuuhuihihuihuihuihuihuihihiuhiu
#define mxn fgwegfdppaaaaaaaaaaaaaaaaa
#define A qwsqsadsaxczcdfewfdsvsdvv
#define B hasdhhhhhhhhwhwhdjpqpoiueuqeyuio
#define C byuiovewfyquobvfywieqobyuisdajdkjffff

using namespace std;
const int MAXN=1e5+10;
struct DA {
	int a1;
	int a2;
	int a3;
} x1[MAXN],x2[MAXN],x3[MAXN];
int T,n;
long long ans;
bool mybol1(DA x,DA y) {
	if(x.a1>y.a1)return true;
	return false;
}
bool mybol2(DA x,DA y) {
	if(x.a2>y.a2)return true;
	return false;
}
bool mybol3(DA x,DA y) {
	if(x.a3>y.a3)return true;
	return false;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		ans=0;
		scanf("%d",&n);
		int mxn=n/2;
		int A=0,B=0,C=0;
		int aa1,aa2,aa3;
		L(i,1,n) {
			scanf("%d%d%d",&aa1,&aa2,&aa3);
			if(aa1>=aa2&&aa1>=aa3) {
				A++;
				x1[A].a1=aa1;
				x1[A].a2=aa2;
				x1[A].a3=aa3;
			}
			if(aa2>aa1&&aa2>=aa3) {
				B++;
				x2[B].a1=aa1;
				x2[B].a2=aa2;
				x2[B].a3=aa3;
			}
			if(aa3>aa1&&aa3>aa2) {
				C++;
				x3[C].a1=aa1;
				x3[C].a2=aa2;
				x3[C].a3=aa3;
			}
		}
		if(A<=mxn&&B<=mxn&&C<=mxn) {
			L(i,1,A)ans+=x1[i].a1;
			L(i,1,B)ans+=x2[i].a2;
			L(i,1,C)ans+=x3[i].a3;
			printf("%lld\n",ans);
			continue;
		}
		sort(x1+1,x1+A+1,mybol1);
		sort(x2+1,x2+B+1,mybol2);
		sort(x3+1,x3+C+1,mybol3);
		if(A>n/2) {
			int z=A-n/2;
			A-=n/2;
			R(i,z,1) {
				if(x1[i].a2>=x1[i].a3) {
					B++;
					x2[B].a1=x1[i].a1;
					x2[B].a2=x1[i].a2;
					x2[B].a3=x1[i].a3;
				} else {
					C++;
					x3[C].a1=x1[i].a1;
					x3[C].a2=x1[i].a2;
					x3[C].a3=x1[i].a3;
				}
			}

		}
		if(B>n/2) {
			int z=B-n/2;
			B-=n/2;
			R(i,z,1) {
				if(x2[i].a1>=x2[i].a3) {
					A++;
					x1[A].a1=x2[i].a1;
					x1[A].a2=x2[i].a2;
					x1[A].a3=x2[i].a3;
				} else {
					C++;
					x3[C].a1=x2[i].a1;
					x3[C].a2=x2[i].a2;
					x3[C].a3=x2[i].a3;
				}
			}

		}
		if(C>n/2) {
			int z=C-n/2;
			C-=n/2;
			R(i,z,1) {
				if(x3[i].a1>=x3[i].a2) {
					A++;
					x1[A].a1=x3[i].a1;
					x1[A].a2=x3[i].a2;
					x1[A].a3=x3[i].a3;
				} else {
					B++;
					x2[B].a1=x3[i].a1;
					x2[B].a2=x3[i].a2;
					x2[B].a3=x3[i].a3;
				}
			}

		}
		L(i,1,A)ans+=x1[i].a1;
		L(i,1,B)ans+=x2[i].a2;
		L(i,1,C)ans+=x3[i].a3;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
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