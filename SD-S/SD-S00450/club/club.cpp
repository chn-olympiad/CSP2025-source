#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define re register
using namespace std;
const int N=1e5+10;
inline int read(int &x){
	int k=0,f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		k=(k<<3)+(k<<1)+(c^'0');
		c=getchar();
	}
	x=k*f;
}
struct node{
	int x,y,z;
	int s,gr;
	node(){}
}a[N];
bool cmp(node a,node b){
	if(max(max(a.x,a.y),a.z)==max(max(b.x,b.y),b.z)) return a.s<b.s;
	return max(max(a.x,a.y),a.z)>max(max(b.x,b.y),b.z);
}
int T,n;
int Need[N]={0},tot=0;
int sum_a=0,sum_b=0,sum_c=0;
int ans=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		ans=0,tot=0;
		sum_a=sum_b=sum_c=0;
		for(re int i=1;i<=n;i++){
			read(a[i].x),read(a[i].y),read(a[i].z);
			if(a[i].x>=max(a[i].y,a[i].z)){
				a[i].s=a[i].x-max(a[i].y,a[i].z);
				a[i].gr=1,sum_a++;
				ans+=a[i].x;
			}
			else if(a[i].y>=max(a[i].x,a[i].z)){
				a[i].s=a[i].y-max(a[i].x,a[i].z);
				a[i].gr=2,sum_b++;
				ans+=a[i].y;
			}
			else{
				a[i].s=a[i].z-max(a[i].x,a[i].y);
				a[i].gr=3,sum_c++;
				ans+=a[i].z;
			}
		}
		if(sum_a>n/2){
			for(re int i=1;i<=n;i++){
				if(a[i].gr==1) Need[++tot]=a[i].s;
			}
			sort(Need+1,Need+1+tot);
			for(re int i=1;i<=sum_a-n/2;i++) ans-=Need[i];
		}
		if(sum_b>n/2){
			for(re int i=1;i<=n;i++){
				if(a[i].gr==2) Need[++tot]=a[i].s;
			}
			sort(Need+1,Need+1+tot);
			for(re int i=1;i<=sum_b-n/2;i++) ans-=Need[i];
		}
		if(sum_c>n/2){
			for(re int i=1;i<=n;i++){
				if(a[i].gr==3) Need[++tot]=a[i].s;
			}
			sort(Need+1,Need+1+tot);
			for(re int i=1;i<=sum_c-n/2;i++) ans-=Need[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
