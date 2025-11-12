#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct IO{
	static const int siz=(1<<20);
	char buf[siz],*p1,*p2;
	char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,siz,stdin),p1==p2)?EOF:*p1++;}
	IO &operator >>(int &x){
		x=0;char c=gc();
		while(!isdigit(c))	c=gc();
		while(isdigit(c))	x=(x<<1)+(x<<3)+(c^'0'),c=gc();
		return *this;
	}
}fin;
int T,n,a[N][3],f[N],t[N],ans;
vector<int> c;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	fin>>T;
	while(T--){
		fin>>n,ans=t[0]=t[1]=t[2]=0;
		for(int i=1;i<=n;i++){
			fin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=max(a[i][1],a[i][2]))	f[i]=0,t[0]++,ans+=a[i][0];
			else if(a[i][1]>=max(a[i][0],a[i][2]))	f[i]=1,t[1]++,ans+=a[i][1];
			else	f[i]=2,t[2]++,ans+=a[i][2];
		}
		if(t[1]<=n/2&&t[2]<=n/2&&t[0]<=n/2){cout<<ans<<'\n';continue;}
		int tmp,num;
		if(t[0]>n/2)	tmp=0;
		if(t[1]>n/2)	tmp=1;
		if(t[2]>n/2)	tmp=2;
		c.clear(),num=t[tmp]-n/2;
		for(int i=1;i<=n;i++){
			if(f[i]!=tmp)	continue;
			int k=0;
			for(int j=0;j<3;j++){
				if(j==tmp)	continue;
				k=max(k,a[i][j]);
			}
			c.push_back(a[i][tmp]-k);
		}
		sort(c.begin(),c.end());
		for(int i=0;i<num;i++)	ans-=c[i];
		cout<<ans<<'\n';
	}
	return 0;
}
