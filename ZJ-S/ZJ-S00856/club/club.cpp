#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int v=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v;
}
int T,n;
struct bu{
	int id,v;
	bool operator<(const bu &x)const{
		return v>x.v;
	}
};
struct node{
	bu a[3];
	bool operator<(const node &x)const{
		return a[0].v-a[1].v<x.a[0].v-x.a[1].v;
	}
}p[100010];
int cnt[3];
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read(); ans=0;
		for(int i=0;i<=2;i++) cnt[i]=0;
		for(int i=1,x,y,z;i<=n;i++){
			x=read(),y=read(),z=read();
			p[i].a[0]={0,x};
			p[i].a[1]={1,y};
			p[i].a[2]={2,z};
			sort(p[i].a,p[i].a+3);
			cnt[p[i].a[0].id]++;
			ans+=p[i].a[0].v;
		}
		sort(p+1,p+n+1);
		for(int i=0;i<=2;i++){
			if(cnt[i]>n/2){
				for(int j=1;j<=n&&cnt[i]>n/2;j++){
					if(p[j].a[0].id!=i) continue;
					ans+=p[j].a[1].v-p[j].a[0].v;
					cnt[i]--;
				}
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}