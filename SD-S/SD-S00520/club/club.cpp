#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstring>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define ll long long
#define ull usdigned long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N=1e5+5;
ll read(){
	ll x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*w;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int t,n;
struct node{
	ll a,b,c,id,mx,loc,mx2;
}x[N];
struct NODE{
	ll val,id;
	bool operator < (const NODE &kk)const{
		return kk.val<val;
	}
};
int main(){
	file("club");
	t=read();
	while(t--){
		n=read();
		ll ans=0;
		priority_queue<NODE> pq1,pq2,pq3;
		for (int i=1;i<=n;i++){
			x[i].a=read();x[i].b=read();x[i].c=read();
			int maxx=max(max(x[i].a,x[i].b),x[i].c);
			x[i].mx=maxx;
			if(x[i].a==maxx) x[i].id=1;
			else if(x[i].b==maxx) x[i].id=2;
			else x[i].id=3;
			x[i].loc=i;
			if(x[i].a==maxx){
				if(x[i].b>x[i].c) x[i].mx2=x[i].b;
				else x[i].mx2=x[i].c;
			}
			if(x[i].b==maxx){
				if(x[i].a>x[i].c) x[i].mx2=x[i].a;
				else x[i].mx2=x[i].c;
			}
			if(x[i].c==maxx){
				if(x[i].b>x[i].a) x[i].mx2=x[i].b;
				else x[i].mx2=x[i].a;
			}
		}
		for (int i=1;i<=n;i++){
			if(x[i].id==1) pq1.push((NODE){x[i].mx-x[i].mx2,x[i].loc});
			else if(x[i].id==2) pq2.push((NODE){x[i].mx-x[i].mx2,x[i].loc});
			else pq3.push((NODE){x[i].mx-x[i].mx2,x[i].loc});
			ans+=x[i].mx;
		}
		if((int)pq1.size()>n/2){
			while((int)pq1.size()>n/2){
				NODE now=pq1.top();
				pq1.pop();
				if(x[now.id].b>x[now.id].c){
					ans-=now.val;
				}
				else{
					ans-=now.val;
				}
			}
		}
		if((int)pq2.size()>n/2){
			while((int)pq2.size()>n/2){
				NODE now=pq2.top();
				pq2.pop();
				if(x[now.id].a>x[now.id].c){
					ans-=now.val;
				}
				else{
					ans-=now.val;
				}
			}
		}
		if((int)pq3.size()>n/2){
			while((int)pq3.size()>n/2){
				NODE now=pq3.top();
				pq3.pop();
				if(x[now.id].a>x[now.id].b){
					ans-=now.val;
				}
				else{
					ans-=now.val;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
