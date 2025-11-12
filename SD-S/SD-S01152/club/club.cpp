#include<bits/stdc++.h>
using namespace std;
namespace file_read{
	char ib[1<<25],*ip1=ib,*ip2=ib;
	inline char gc(){
		return (((ip1==ip2&&(ip2=(ip1=ib)+fread(ib,1,1<<24,stdin))),ip1==ip2?EOF:*ip1++));
	}
	inline int read(){//no long long!!!
		int x=0;char c=gc();
		while(c<'0'||c>'9')c=gc();
		while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=gc();
		return x;
	}
}
using namespace file_read;
int a[100005][5],c[100005],v[100005],p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int n=read(),k=3;
		for(int i=1;i<=k;++i)c[i]=0;
		int he=0;
		for(int i=1;i<=n;++i){
			int mx=-1,wz=0;
			for(int j=1;j<=k;++j){
				a[i][j]=read();
				if(mx<a[i][j])mx=a[i][j],wz=j;
			}
			v[i]=wz;++c[wz];he+=mx;
		}
		int d=0;
		for(int i=1;i<=k;++i)if(c[i]>n/2)d=i;
		if(d){
			int t=0;
			for(int i=1;i<=n;++i)if(v[i]==d){
				int mx=-1;
				for(int j=1;j<=k;++j)if(j!=d)mx=max(mx,a[i][j]);
				p[++t]=a[i][d]-mx;
			}
			sort(p+1,p+t+1);
			int z=t-(n/2);
			for(int i=1;i<=z;++i)he-=p[i];
		}
		//1e5*2e4=2e9<INT_MAX
		printf("%d\n",he);
	}
	return 0;
}
