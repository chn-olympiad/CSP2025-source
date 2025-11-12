#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int id,a,b,c,v,w;
	bool operator < (const node &a)const {
		return w>a.w;
	}
} t[100100];
int n,a,b,c,ans,N;
bool p[100100];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	while(N--) {
		memset(p,false,sizeof p);
		a=b=c=ans=0;
		priority_queue<node>q1,q2,w,e;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>t[i].a>>t[i].b>>t[i].c;
			t[i].id=i;
			if(t[i].a>t[i].b&&t[i].a>t[i].c)a++,t[i].v=1;
			else if(t[i].b>t[i].a&&t[i].b>t[i].c)b++,t[i].v=2;
			else c++,t[i].v=3;
		}
		for(int i=1; i<=n; i++) {
			ans+=max(t[i].a,max(t[i].b,t[i].c));
		}
//		cout<<a<<" "<<b<<" "<<c<<" "<<ans<<"\n";//1
		if(a<=n/2&&b<=n/2&&c<=n/2) {
//			cout<<"!!!!";//0
			cout<<ans<<"\n";
			continue;
		}
		if(a>n/2) {
//			cout<<1<<"\n";//1
			for(int i=1; i<=n; i++) {
				if(t[i].v==1)t[i].w=t[i].a-t[i].b,q1.push(t[i]),t[i].w=t[i].a-t[i].c,q2.push(t[i]);
//				cout<<t[i].a<<" "<<t[i].b<<" "<<t[i].c<<" "<<t[i].v<<" "<<t[i].w<<"\n";//1
			}
			while(a-n/2>0) {
				if(!q1.empty()&&p[q1.top().id])q1.pop();
				if(!q2.empty()&&p[q2.top().id])q2.pop();
				if(b>=n/2||q1.empty()||(!q2.empty()&&q1.top().w>q2.top().w)) {
					p[q2.top().id]=true;
					ans-=q2.top().w;
					q2.pop(),c++;
				}
				else {
					p[q1.top().id]=true;
					ans-=q1.top().w;
					q2.pop(),b++;
				}
				a--;
			}
			cout<<ans<<"\n";
		}
		else if(b>n/2) {
//			cout<<2<<"\n";//1
			for(int i=1; i<=n; i++) {
				if(t[i].v==2)t[i].w=t[i].b-t[i].a,q1.push(t[i]),t[i].w=t[i].b-t[i].c,q2.push(t[i]);
//				cout<<t[i].a<<" "<<t[i].b<<" "<<t[i].c<<" "<<t[i].v<<" "<<t[i].w<<"\n";//1
			}
			while(b-n/2>0) {
				if(!q1.empty()&&p[q1.top().id])q1.pop();
				if(!q2.empty()&&p[q2.top().id])q2.pop();
				if(c>=n/2||q1.empty()||(!q2.empty()&&q1.top().w>q2.top().w)) {
					p[q2.top().id]=true;
					ans-=q2.top().w;
					q2.pop(),c++;
				}
				else {
					p[q1.top().id]=true;
					ans-=q1.top().w;
					q2.pop(),a++;
				}
//				cout<<ans<<"\n";//0.5
				b--;
			}
			cout<<ans<<"\n";
		}
		else if(c>n/2) {
//			cout<<3<<"\n";//1
			for(int i=1; i<=n; i++) {
				if(t[i].v==3)t[i].w=t[i].c-t[i].a,q1.push(t[i]),t[i].w=t[i].c-t[i].b,q2.push(t[i]);
//				cout<<t[i].a<<" "<<t[i].b<<" "<<t[i].c<<" "<<t[i].v<<" "<<t[i].w<<"\n";//1
			}
			while(c-n/2>0) {
				if(!q1.empty()&&p[q1.top().id])q1.pop();
				if(!q2.empty()&&p[q2.top().id])q2.pop();
				if(b>=n/2||q1.empty()||(!q2.empty()&&q1.top().w>q2.top().w)) {
					p[q2.top().id]=true;
					ans-=q2.top().w;
					q2.pop(),b++;
				}
				else {
					p[q1.top().id]=true;
					ans-=q1.top().w;
					q2.pop(),a++;
				}
				c--;
			}
			cout<<ans<<"\n";
		}
	}



	return 0;
}
/*
1
4
4 2 1
4 3 2
5 3 4
3 5 1

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
