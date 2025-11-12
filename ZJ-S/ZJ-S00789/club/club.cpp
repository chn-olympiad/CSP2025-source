#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100100],b[100100],c[100100];
int al,bl,cl;
long long ans;
struct bla{
	int x;
	int y;
	int z;
	int maxx;
	int minn;
	int mid;
}k[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		al=0;
		bl=0;
		cl=0;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&k[i].x);
			scanf("%d",&k[i].y);
			scanf("%d",&k[i].z);
			k[i].maxx=max(k[i].x,max(k[i].y,k[i].z));
			k[i].minn=min(k[i].x,min(k[i].y,k[i].z));
			k[i].mid=k[i].x+k[i].y+k[i].z-k[i].maxx-k[i].minn;
			if(k[i].maxx==k[i].x){
				al++;
				a[al]=k[i].maxx-k[i].mid;
			}
			else if(k[i].maxx==k[i].y){
				bl++;
				b[bl]=k[i].maxx-k[i].mid;
			}
			else if(k[i].maxx==k[i].z){
				cl++;
				c[cl]=k[i].maxx-k[i].mid;
			}
			ans+=k[i].maxx;
		}
		if(al>n/2){
			sort(a+1,a+1+al);
			for(int i=1;i<=al-n/2;i++){
				ans-=a[i];
			}
		}else if(bl>n/2){
			sort(b+1,b+1+bl);
			for(int i=1;i<=bl-n/2;i++){
				ans-=b[i];
			}
		}else if(cl>n/2){
			sort(c+1,c+1+cl);
			for(int i=1;i<=cl-n/2;i++){
				ans-=c[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
