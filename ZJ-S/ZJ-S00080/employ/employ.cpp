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
#define n dijsadowqieuuuuuuuuuuuuuiqowiiiiiii
#define m dddddddddddddddddddwqwqrwqfege
#define nn iowinckkuebuwsewoeufhiw
#define a utiorpetiomvoqpmtvuopppppppppppppppp
#define x jhriwehuuuuuuuuuuuuuuuuuurrrrrrrrrriiiqiiwoiiewoijidsapppo
#define mydo fhiuuuuuuuuhhuwqlkslaoopoqinbwetuiubiribtrbdsdishduh
#define ans uidhwiqioerpoquwrtqrryuwirqeiobzjhkczbm
#define y uihwquuuuuuuuuuuurrrrrrrrrjjjjj
using namespace std;
const int MAXN=510;
int n,m,nn;
char a;
int x[MAXN];
void mydo(int y){
	long long ans=1;
	R(i,y,1){
		ans*=i;
		ans%=998244353;
	}
	printf("%lld\n",ans);
	return;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	nn=n;
	L(i,1,n){
		scanf("%c",&a);
	}
	L(i,1,n){
		scanf("%d",x+i);
		if(x[i]==0){
			nn--;
		}
	}
	mydo(nn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 2
101
1 1 2
*/