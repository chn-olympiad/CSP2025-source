#include<algorithm>
#include<iostream>
#include<cstdio>
char buf[1<<20],*p1,*p2;
#define gc() (p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin)),*p1++)
template<typename T>
void read(T &v){
	T x=0,f=1;char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc();}
	v=x*f;
}
using namespace std;
struct Data{
	int i1,i2,i3;
}a[100010];
int bl[30];
void dfs(int u,int n,int &ans,int s1,int s2,int s3){
	if(u==n+1){
		int sum=0;
		for(int i=1;i<=n;++i){
			if(bl[i]==1)sum+=a[i].i1;
			if(bl[i]==2)sum+=a[i].i2;
			if(bl[i]==3)sum+=a[i].i3;
		}
		ans=max(ans,sum);
		return;
	}
	if(s1<n/2){
		bl[u]=1;dfs(u+1,n,ans,s1+1,s2,s3);	
	}
	if(s2<n/2){
		bl[u]=2;dfs(u+1,n,ans,s1,s2+1,s3);
	}
	if(s3<n/2){
		bl[u]=3;dfs(u+1,n,ans,s1,s2,s3+1);
	}
}
bool cmpf(Data p1,Data p2){
	return p1.i1>p2.i1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans;read(t);
	for(int T=1;T<=t;++T){
		read(n);ans=0;
		for(int i=1;i<=n;++i){
			read(a[i].i1);read(a[i].i2);read(a[i].i3);
		}
		if(n<=30)dfs(1,n,ans,0,0,0);
		else{
			int f=1;
			for(int i=1;i<=n;++i){
				if(a[i].i2!=0||a[i].i3!=0)f=0;
			}
			sort(a+1,a+n+1,cmpf);
			for(int i=1;i>n/2;--i)ans+=a[i].i1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
