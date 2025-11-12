#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int re(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+10;
int t;
struct per{
	int x,y,z;
}a[N];
int n;
int ans;
priority_queue<pair<int,pair<int,int> > > xx;
priority_queue<pair<int,pair<int,int> > > yy;
priority_queue<pair<int,pair<int,int> > > zz;
inline void clr(){
	while(!xx.empty())xx.pop();
	while(!yy.empty())yy.pop();
	while(!zz.empty())zz.pop();
	ans=0;
}
inline void send(int idx,int go){
	if(go==1){
		ans+=a[idx].x;
		if(a[idx].y>a[idx].z)xx.push(make_pair(a[idx].y-a[idx].x,make_pair(2,idx)));
		else xx.push(make_pair(a[idx].z-a[idx].x,make_pair(3,idx)));
	}
	if(go==2){
		ans+=a[idx].y;
		if(a[idx].x>a[idx].z)yy.push(make_pair(a[idx].x-a[idx].y,make_pair(1,idx)));
		else yy.push(make_pair(a[idx].z-a[idx].y,make_pair(3,idx)));
	}
	if(go==3){
		ans+=a[idx].z;
		if(a[idx].x>a[idx].y)zz.push(make_pair(a[idx].x-a[idx].z,make_pair(1,idx)));
		else zz.push(make_pair(a[idx].y-a[idx].z,make_pair(2,idx)));
	}
}
inline void solve(){
	n=re();
	for(int i=1;i<=n;i++){
		int x=re(),y=re(),z=re();
		a[i]=(per){x,y,z};
		int maxx=max(x,max(y,z));
		if(x==maxx){
			if(xx.size()==n/2){
				int p=-xx.top().first,go=xx.top().second.first,idx=xx.top().second.second;
				if(x-p>y&&x-p>z){
					xx.pop();
					ans-=a[idx].x;
					send(idx,go);
					send(i,1);
				}
				else if(y>z)send(i,2);
				else send(i,3);
			}
			else send(i,1);
		}
		else if(y==maxx){
			if(yy.size()==n/2){
				int p=-yy.top().first,go=yy.top().second.first,idx=yy.top().second.second;
				if(y-p>x&&y-p>z){
					yy.pop();
					ans-=a[idx].y;
					send(idx,go);
					send(i,2);
				}
				else if(x>z)send(i,1);
				else send(i,3);
			}
			else send(i,2);
		}
		else{
			if(zz.size()==n/2){
				int p=-zz.top().first,go=zz.top().second.first,idx=zz.top().second.second;
				if(z-p>x&&z-p>y){
					zz.pop();
					ans-=a[idx].z;
					send(idx,go);
					send(i,3);
				}
				else if(x>y)send(i,1);
				else send(i,2);
			}
			else send(i,3);
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=re();
	while(t--){
		clr();
		solve();
	}
	return 0;
}

