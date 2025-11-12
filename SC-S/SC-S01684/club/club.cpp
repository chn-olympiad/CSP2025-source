#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=1e5+5;
priority_queue<int> qu2,qu3;
int aa,bb,cc;
struct hh{
	short a,b,c,d,e,f,g,u,v;//d f u
}x[N];
bool cmp(hh p,hh q){
	return p.d>q.d;
}
//bool cmp2(hh p,hh q){
//	return p.f>q.f;
//}
//bool cmp3(hh p,hh q){
//	return p.u>q.u;
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(x,0,sizeof(x));
		aa=0,bb=0,cc=0;
		int ans=0;
		int n;
		cin>>n;
		int dd=n/2;
		for(int i=0;i<n;i++){
			short m,n,h;
			cin>>m>>n>>h;
			x[i].a=m;x[i].b=n;x[i].c=h;
			x[i].d=max(m,max(n,h));
			if(x[i].d==m){
				x[i].e=1;
				x[i].f=max(n,h);
				if(x[i].f==n){
					x[i].g=2;
					x[i].u=h;
					x[i].v=3;
				}
				else{
					x[i].g=3;
					x[i].u=n;
					x[i].v=2;
				}
			}
			else if(x[i].d==n){
				x[i].e=2;
				x[i].f=max(m,h);
				if(x[i].f==m){
					x[i].g=1;
					x[i].u=h;
					x[i].v=3;
				}
				else{
					x[i].g=3;
					x[i].u=m;
					x[i].v=1;
				}
			}
			else{
				x[i].e=3;
				x[i].f=max(n,m);
				if(x[i].f==n){
					x[i].g=2;
					x[i].u=m;
					x[i].v=1;
				}
				else{
					x[i].g=1;
					x[i].u=n;
					x[i].v=2;
				}
			}
		}
		sort(x,x+n,cmp);
		for(int i=0;i<n;i++){
			if(x[i].e==1){
				if(aa<dd){
					aa++;
					ans+=x[i].d;
				}
				else if(x[i].g==2){
					bb++;
					ans+=x[i].f;
				}
				else if(x[i].g==3){
					cc++;
					ans+=x[i].f;
				}
			}
			else if(x[i].e==2){
				
				if(bb<dd){
					bb++;
					ans+=x[i].d;
				}
				else if(x[i].g==1){
					aa++;
					ans+=x[i].f;
				}
				else if(x[i].g==3){
					cc++;
					ans+=x[i].f;
				}
			}
			else{
				if(cc<dd){
					cc++;
					ans+=x[i].d;
				}
				else if(x[i].g==2){
					bb++;
					ans+=x[i].f;
				}
				else if(x[i].g==1){
					aa++;
					ans+=x[i].f;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}