#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n;
ll ans;
struct node{
	int a,b,c;
	int zd,cd,ch;
}k[N];
int a1,b1,c1;
void f(int a,int b,int c,int i){
	if(a>=b&&a>=c){
		k[i].zd=1;a1++;ans+=a;
		if(b>=c) k[i].cd=2,k[i].ch=a-b;
		else k[i].cd=3,k[i].ch=a-c;
		return ;
	}
	if(b>=a&&b>=c){
		k[i].zd=2;b1++;ans+=b;
		if(a>=c) k[i].cd=1,k[i].ch=b-a;
		else k[i].cd=3,k[i].ch=b-c;
		return ;
	}
	if(c>=a&&c>=b){
		k[i].zd=3;c1++;ans+=c;
		if(a>=b) k[i].cd=1,k[i].ch=c-a;
		else k[i].cd=2,k[i].ch=c-b;
	}
}
int cmp1(node a,node b){
	return (a.zd==1&&b.zd==1)?a.ch<b.ch:(a.zd==1);
}
int cmp2(node a,node b){
	return (a.zd==2&&b.zd==2)?a.ch<b.ch:(a.zd==2);
}
int cmp3(node a,node b){
	return (a.zd==3&&b.zd==3)?a.ch<b.ch:(a.zd==3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;a1=0,b1=0,c1=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&k[i].a,&k[i].b,&k[i].c);
			f(k[i].a,k[i].b,k[i].c,i);
		}
		int x=(n+1)/2;
		if(a1<=x&&b1<=x&&c1<=x) printf("%lld\n",ans);
		else if(a1>x){
			sort(k+1,k+1+n,cmp1);
			for(int i=1;i<=a1-x;i++){
				ans-=k[i].ch;
			}
			printf("%lld\n",ans);
		}
		else if(b1>x){
			sort(k+1,k+1+n,cmp2);
			for(int i=1;i<=b1-x;i++){
				ans-=k[i].ch;
			}
			printf("%lld\n",ans);
		}
		else if(c1>x){
			sort(k+1,k+1+n,cmp3);
			for(int i=1;i<=c1-x;i++){
				ans-=k[i].ch;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
