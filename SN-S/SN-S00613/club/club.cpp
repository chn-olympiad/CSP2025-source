#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
long long ans,mx;
int b[4],r,i,l1,vis[N],n,t,f=1;
map<int,int>mp,st;
queue<int>q1,q2,q3;
inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}return ans*f;
}
struct c{
	int x,y,z,w;
	void re(){
		x=read();
		if((i%3==1||i%3==2)&&x!=0)f=0;
		y=i/3+1;
		z=(i-1)%3+1;	
	}bool operator<(const struct c &rhs){
		return x<rhs.x;
	}
}a[N];
void solve(){
	f=1;
	n=read();
	n*=3;
	ans=0;
	for(i=1;i<=n;++i){
		a[i].re();	
	}sort(a+1,a+1+n);
	if(f){
		for(int i=1;i<=n/2;++i){
			ans+=a[i].x;
		}cout<<ans<<'\n';
	}
	for(int i=1;i<=n;++i){
		if(mp[a[i].y]){
			if(st[a[i].z]<n/2){
				--st[a[i].w];
				ans+=a[i].x-mp[a[i].y];
				++st[a[i].z];
				mp[a[i].y]=a[i].x;
				a[i].w=a[i].z;
			}
		}else if(st[a[i].z]<n/2){
			ans+=a[i].x;
			++st[a[i].z];
			mp[a[i].y]=a[i].x;
			a[i].w=a[i].z;
		}
	}cout<<ans<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)solve();
	return 0;
}

