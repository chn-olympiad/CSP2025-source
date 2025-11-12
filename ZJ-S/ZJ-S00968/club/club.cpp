#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+27;

struct Num {
	int val,tp;
};

struct Node {
	Num d[3];
	int dd[3];
} a[MAXN];

int n;
priority_queue<pair<int,int>> p12,p13,p23,p21,p31,p32;
int vis[MAXN];

bool cmp(Num x,Num y) {
	return x.val>y.val;
}

bool cp(Node x,Node y) {
	return x.d[0].val>y.d[0].val;
}

int main() {

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin>>T;
	while(T--) {

		int t[4]= {0,0,0,0};
		long long ans=0;

		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].dd[0]>>a[i].dd[1]>>a[i].dd[2];
			a[i].d[0].val=a[i].dd[0];
			a[i].d[0].tp=1;
			a[i].d[1].val=a[i].dd[1];
			a[i].d[1].tp=2;
			a[i].d[2].val=a[i].dd[2];
			a[i].d[2].tp=3;
			sort(a[i].d,a[i].d+3,cmp);
		}
		sort(a+1,a+n+1,cp);

		for(int i=1; i<=n; i++) {
			if(t[a[i].d[0].tp]<n/2) {
				ans+=a[i].d[0].val;
				t[a[i].d[0].tp]++;
				if(a[i].d[0].tp==1) {
					if(a[i].dd[1]>a[i].dd[0]) p21.push({a[i].dd[0]-a[i].dd[1],i});
					else p12.push({a[i].dd[1]-a[i].dd[0],i});
					if(a[i].dd[2]>a[i].dd[0]) p31.push({a[i].dd[0]-a[i].dd[2],i});
					else p13.push({a[i].dd[2]-a[i].dd[0],i});
				}

				else if(a[i].d[0].tp==2) {
					if(a[i].dd[1]>a[i].dd[0]) p21.push({a[i].dd[0]-a[i].dd[1],i});
					else p12.push({a[i].dd[1]-a[i].dd[0],i});
					if(a[i].dd[2]>a[i].dd[1]) p32.push({a[i].dd[1]-a[i].dd[2],i});
					else p23.push({a[i].dd[2]-a[i].dd[1],i});
				}

				else {
					if(a[i].dd[2]>a[i].dd[0]) p31.push({a[i].dd[0]-a[i].dd[2],i});
					else p13.push({a[i].dd[2]-a[i].dd[0],i});
					if(a[i].dd[2]>a[i].dd[1]) p32.push({a[i].dd[1]-a[i].dd[2],i});
					else p23.push({a[i].dd[2]-a[i].dd[1],i});
				}

			} else {
				int temp12=a[i].dd[0]-a[i].dd[1];
				int temp21=a[i].dd[1]-a[i].dd[0];
				int temp13=a[i].dd[0]-a[i].dd[2];
				int temp31=a[i].dd[2]-a[i].dd[0];
				int temp23=a[i].dd[1]-a[i].dd[2];
				int temp32=a[i].dd[2]-a[i].dd[1];
				if(a[i].d[0].tp==1) {
					if(temp12>0) {
						if(-temp12<p12.top().first) {
							ans+=p12.top().first;
							ans+=temp12;
							t[2]++;

							if(a[i].dd[1]>a[i].dd[0]) p21.push({a[i].dd[0]-a[i].dd[1],i});
							else p12.push({a[i].dd[1]-a[i].dd[0],i});
							if(a[i].dd[2]>a[i].dd[0]) p31.push({a[i].dd[0]-a[i].dd[2],i});
							else p13.push({a[i].dd[2]-a[i].dd[0],i});

							continue;
						}
					}
					if(temp13>0) {
						if(-temp13<p13.top().first) {
							p13.pop();
							ans+=p13.top().first;
							ans+=temp13;
							t[3]++;
							if(a[i].dd[1]>a[i].dd[0]) p21.push({a[i].dd[0]-a[i].dd[1],i});
							else p12.push({a[i].dd[1]-a[i].dd[0],i});
							if(a[i].dd[2]>a[i].dd[0]) p31.push({a[i].dd[0]-a[i].dd[2],i});
							else p13.push({a[i].dd[2]-a[i].dd[0],i});
							continue;
						}
					}
				} else if(a[i].d[0].tp==2) {
					if(temp21>0) {
						if(-temp21<p21.top().first) {
							p21.pop();
							ans+=p21.top().first;
							ans+=temp21;
							t[1]++;
							if(a[i].dd[1]>a[i].dd[0]) p21.push({a[i].dd[0]-a[i].dd[1],i});
							else p12.push({a[i].dd[1]-a[i].dd[0],i});
							if(a[i].dd[2]>a[i].dd[1]) p32.push({a[i].dd[1]-a[i].dd[2],i});
							else p23.push({a[i].dd[2]-a[i].dd[1],i});
							continue;
						}
					}
					if(temp23>0) {
						if(-temp23<p23.top().first) {
							p23.pop();
							ans+=p23.top().first;
							ans+=temp23;
							t[3]++;
							if(a[i].dd[1]>a[i].dd[0]) p21.push({a[i].dd[0]-a[i].dd[1],i});
							else p12.push({a[i].dd[1]-a[i].dd[0],i});
							if(a[i].dd[2]>a[i].dd[1]) p32.push({a[i].dd[1]-a[i].dd[2],i});
							else p23.push({a[i].dd[2]-a[i].dd[1],i});
							continue;
						}
					}
				} else {
					if(temp31>0) {
						if(-temp31<p31.top().first) {
							p31.pop();
							ans+=p31.top().first;
							ans+=temp31;
							t[1]++;
							if(a[i].dd[2]>a[i].dd[0]) p31.push({a[i].dd[0]-a[i].dd[2],i});
							else p13.push({a[i].dd[2]-a[i].dd[0],i});
							if(a[i].dd[2]>a[i].dd[1]) p32.push({a[i].dd[1]-a[i].dd[2],i});
							else p23.push({a[i].dd[2]-a[i].dd[1],i});
							continue;
						}
					}
					if(temp32>0) {
						if(-temp32<p32.top().first) {
							p32.pop();
							ans+=p32.top().first;
							ans+=temp13;
							t[2]++;
							if(a[i].dd[2]>a[i].dd[0]) p31.push({a[i].dd[0]-a[i].dd[2],i});
							else p13.push({a[i].dd[2]-a[i].dd[0],i});
							if(a[i].dd[2]>a[i].dd[1]) p32.push({a[i].dd[1]-a[i].dd[2],i});
							else p23.push({a[i].dd[2]-a[i].dd[1],i});
							continue;
						}
					}
				}

			}
		}
		cout<<ans<<endl;
	}
	return 0;
}