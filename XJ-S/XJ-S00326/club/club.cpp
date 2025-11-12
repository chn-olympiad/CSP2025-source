#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
template<typename type>
inline void read(type &x){
	x=0;
	static bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){
		flag=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	flag?x=-x:0;
}
struct node{
	int a,b;
}f[N];
int T;
int n;
int x[N],y[N],z[N];
int d[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		ll ans1=0,ans2=0,ans3=0;
		read(n);
		for(int i=1;i<=n;i++){
			read(x[i]),read(y[i]),read(z[i]);
			if(x[i]<=y[i]&&x[i]<=z[i]) x[i]=0;
			else if(y[i]<=x[i]&&y[i]<=z[i]) y[i]=0;
			else if(z[i]<=x[i]&&z[i]<=y[i]) z[i]=0;
		}
		for(int i=1;i<=n;i++){
			f[i].a=x[i],d[i]=max(y[i],z[i])-f[i].a;	
		}	
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;i++) ans1+=f[i].a;
		for(int i=1;i<=(n>>1);i++) ans1+=d[i];			
		for(int i=1;i<=n;i++){
			f[i].a=y[i],d[i]=max(x[i],z[i])-f[i].a;			
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;i++) ans2+=f[i].a;
		for(int i=1;i<=(n>>1);i++) ans2+=d[i];				
		for(int i=1;i<=n;i++){
			f[i].a=z[i],d[i]=max(x[i],y[i])-f[i].a;			
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;i++) ans3+=f[i].a;
		for(int i=1;i<=(n>>1);i++) ans3+=d[i];		
		printf("%lld\n",max(ans1,max(ans2,ans3)));		
	}
	return 0; //wan dan le
}
