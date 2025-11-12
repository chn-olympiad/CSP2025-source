#include<bits/stdc++.h>
using namespace std;
const int MAXN=20000+5;
const int inf=2147483647;
//
int T0,n,ex;
int a1[MAXN],b1[MAXN],c1[MAXN];
bool S,T;
struct node{
	int First;
	int Second;
	int Third;
}a[MAXN];
//
bool cmp1(node x,node y){
	return x.First>y.First;
	if(x.First==y.First)return x.Second>y.Second;
}
//
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T0);
	for(int Ti=1;Ti<=T0;++Ti){
		int sx=0,sy=0,sz=0;
		S=0;T=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a[i].First=x;
			a[i].Second=y;
			a[i].Third=z;
			if(a[i].Second)S=1;
			if(a[i].Third)T=1;
		}
		if(S==0&&T==0){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;++i){
				sx+=a[i].First;
			}
			printf("%d\n",sx);
		}else if(T==0){
			for(int i=1;i<=n;++i){
				if(a[i].First<a[i].Second){
					ex=a[i].First;a[i].First=a[i].Second;a[i].Second=ex;
				}
			}
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;++i){
				sx+=a[i].First;
				sy+=a[i+n/2].First;
			}
			printf("%d",(long long)sx+sy);
		}
	}
	return 0;
}