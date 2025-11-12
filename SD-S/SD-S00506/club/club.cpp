#include<bits/stdc++.h>
#define int long long
const int N=1e5+10;
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct aa{
	int s,n;
};
int T,m,n,ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=n/2,ans=0;
		vector<int> a,b,c,d(n+1),dd(n+1);
		vector<int> sign(n+1,0);
		vector<vector<aa>> mp(n+1,vector<aa>(10));
		for(int i=1;i<=n;i++){
			mp[i][1]={read(),1};
			mp[i][2]={read(),2};
			mp[i][3]={read(),3};
			if(mp[i][1].s<mp[i][2].s) swap(mp[i][1],mp[i][2]);
			if(mp[i][1].s<mp[i][3].s) swap(mp[i][1],mp[i][3]);
			if(mp[i][2].s<mp[i][3].s) swap(mp[i][2],mp[i][3]);
			d[i]=mp[i][1].s-mp[i][2].s,dd[i]=mp[i][2].s-mp[i][3].s;
		}
		for(int i=1;i<=n;i++){
			if(mp[i][1].n==1) a.push_back(i);
			else if(mp[i][1].n==2) b.push_back(i);
			else c.push_back(i);
			ans+=mp[i][1].s;
		}
		int m1=a.size(),m2=b.size(),m3=c.size();
		while(m1>m||m2>m||m3>m){
			while(m1>m){
				int minn=1e9,x,y;
				for(int j=0;j<a.size();j++){
					int i=a[j];
					if(i==-1) continue;
					if(sign[i]==0&&minn>d[i]) minn=d[i],x=i,y=j;
					if(sign[i]==1&&minn>dd[i]) minn=dd[i],x=i,y=j;
				}
				a[y]=-1,ans-=minn,m1--;
				if(sign[x]==0){
					sign[x]=1;
					if(mp[x][2].n==2) b.push_back(x);
					else c.push_back(x);
				}
				if(sign[x]==1){
					sign[x]=2;
					if(mp[x][3].n==2) b.push_back(x);
					else c.push_back(x);
				}
			}
			while(m2>m){
				int minn=1e9,x,y;
				for(int j=0;j<b.size();j++){
					int i=b[j];
					if(i==-1) continue;
					if(sign[i]==0&&minn>d[i]) minn=d[i],x=i,y=j;
					if(sign[i]==1&&minn>dd[i]) minn=dd[i],x=i,y=j;
				}
				b[y]=-1,ans-=minn,m2--;
				if(sign[x]==0){
					sign[x]=1;
					if(mp[x][2].n==1) a.push_back(x);
					else c.push_back(x);
				}
				if(sign[x]==1){
					sign[x]=2;
					if(mp[x][3].n==1) a.push_back(x);
					else c.push_back(x);
				}
			}
			while(m3>m){
				int minn=1e9,x,y;
				for(int j=0;j<c.size();j++){
					int i=c[j];
					if(i==-1) continue;
					if(sign[i]==0&&minn>d[i]) minn=d[i],x=i,y=j;
					if(sign[i]==1&&minn>dd[i]) minn=dd[i],x=i,y=j;
				}
				c[y]=-1,ans-=minn,m3--;
				if(sign[x]==0){
					sign[x]=1;
					if(mp[x][2].n==2) b.push_back(x);
					else a.push_back(x);
				}
				if(sign[x]==1){
					sign[x]=2;
					if(mp[x][3].n==2) b.push_back(x);
					else a.push_back(x);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
