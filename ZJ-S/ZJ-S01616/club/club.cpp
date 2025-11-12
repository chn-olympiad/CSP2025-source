#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
int n,ans,t;
struct ZS{
	int x,y,z;
}da[maxn];
struct ZYX{//pro help
	int id,res;
	bool operator<(const ZYX&B)const{
		return res>B.res;
	}
};
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();ans=0;
		int MAX=n/2;
		priority_queue <ZYX> a,b,c;
		for(int i=1;i<=n;i++){
			int x=read(),y=read(),z=read();
			da[i]=(ZS){x,y,z};
			int Sum=max(max(x,y),z);
			if(Sum==x) a.push((ZYX){i,x-max(y,z)});
			else if(Sum==y) b.push((ZYX){i,y-max(x,z)});
			else if(Sum==z) c.push((ZYX){i,z-max(x,y)});
			ans+=Sum;
		}
		while(a.size()>MAX){
			ZYX id=a.top();a.pop();
			ans-=id.res;
		}
		while(b.size()>MAX){
			ZYX id=b.top();b.pop();
			ans-=id.res;
		}
		while(c.size()>MAX){
			ZYX id=c.top();c.pop();
			ans-=id.res;
		}
		printf("%lld\n",ans);
	}
	return 0;
}