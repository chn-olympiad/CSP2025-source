#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int N=1e5+10;
struct node{
	int x,y,z;
	int data;
}a[N];
bool cmp1(node a,node b){return a.x-max(a.y,a.z)<b.x-max(b.y,b.z);}
bool cmp2(node a,node b){return a.y-max(a.x,a.z)<b.y-max(b.x,b.z);}
bool cmp3(node a,node b){return a.z-max(a.x,a.y)<b.z-max(b.x,b.y);}
int cnt[4],b[N],n,t;
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].data=i;
		for(int i=1;i<=n;i++){
			if(a[i].x>=max(a[i].y,a[i].z)){
				ans+=a[i].x;
				cnt[1]++;b[i]=1;
			}
			else if(a[i].y>=max(a[i].x,a[i].z)){
				ans+=a[i].y;
				cnt[2]++;b[i]=2;
			}
			else {
				ans+=a[i].z;
				cnt[3]++;b[i]=3;
			}
		}
	//	printf("%d %d %d\n",cnt[1],cnt[2],cnt[3]);
		if(cnt[1]>n/2){
			sort(a+1,a+n+1,cmp1);
			int i=0;
			while(cnt[1]>n/2){
				i++;
				if(b[a[i].data]!=1)continue;
				cnt[1]--;
				ans-=a[i].x-max(a[i].y,a[i].z);
			}
		}
		else if(cnt[2]>n/2){
			sort(a+1,a+n+1,cmp2);
			int i=0;
			while(cnt[2]>n/2){
				i++;
				if(b[a[i].data]!=2)continue;
				cnt[2]--;
				ans-=a[i].y-max(a[i].x,a[i].z);
			}
		}
		else if(cnt[3]>n/2){
			sort(a+1,a+n+1,cmp3);
			int i=0;
			while(cnt[3]>n/2){
				i++;
				if(b[a[i].data]!=3)continue;
				cnt[3]--;
				ans-=a[i].z-max(a[i].x,a[i].y);
			//	printf("%d %d %d %d\n",a[i].data,a[i].x,a[i].y,a[i].z);		
			}
		}
//		printf("\n");
//		for(int i=1;i<=n;i++){
//			printf("%d %d %d %d\n",a[i].data,a[i].x,a[i].y,a[i].z);
//		}
		printf("%lld\n",ans);
	}
	return 0;
}
