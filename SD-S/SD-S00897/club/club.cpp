#include<bits/stdc++.h>
using namespace std;
struct club {
	int x,y,z,derta;
} a[100005];
bool cmp(club b,club c) {
	return b.derta>c.derta;
}
int m[5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		memset(m,0,sizeof(m));
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y) {
				if(a[i].x>a[i].z) {
					a[i].derta=a[i].x-max(a[i].y,a[i].z);
				} else {
					a[i].derta=a[i].z-max(a[i].y,a[i].x);
				}
			} else {
				if(a[i].y>a[i].z) {
					a[i].derta=a[i].y-max(a[i].x,a[i].z);
				} else {
					a[i].derta=a[i].z-max(a[i].y,a[i].x);
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(int i=1; i<=n; i++) {
			if(a[i].x>a[i].y) {
				if(a[i].x>a[i].z) {
					if(m[1]*2!=n) {
						ans+=a[i].x;
						m[1]++;
					} else {
						if(a[i].y>a[i].z) {
							if(m[2]*2!=n) {
								ans+=a[i].y;
								m[2]++;
							} else {
								ans+=a[i].z;
								m[3]++;
							}
						}
						else{
							if(m[3]*2!=n) {
								ans+=a[i].z;
								m[3]++;
							} else {
								ans+=a[i].y;
								m[2]++;
							}
						}
					}
				} else {
					if(m[3]*2!=n) {
						ans+=a[i].z;
						m[3]++;
					} else {
						if(a[i].y>a[i].x) {
							if(m[2]*2!=n) {
								ans+=a[i].y;
								m[2]++;
							} else {
								ans+=a[i].x;
								m[1]++;
							}
						}
						else{
							if(m[1]*2!=n) {
								ans+=a[i].x;
								m[1]++;
							} else {
								ans+=a[i].y;
								m[2]++;
							}
						}
					}
				}
			} else {
				if(a[i].y>a[i].z) {
					if(m[2]*2!=n) {
						ans+=a[i].y;
						m[2]++;
					} else {
						if(a[i].x>a[i].z) {
							if(m[1]*2!=n) {
								ans+=a[i].x;
								m[1]++;
							} else {
								ans+=a[i].z;
								m[3]++;
							}
						}
						else{
							if(m[3]*2!=n) {
								ans+=a[i].z;
								m[3]++;
							} else {
								ans+=a[i].x;
								m[1]++;
							}
						}
					}
				} else {
					if(m[3]*2!=n) {
						ans+=a[i].z;
						m[3]++;
					} else {
						if(a[i].y>a[i].x) {
							if(m[2]*2!=n) {
								ans+=a[i].y;
								m[2]++;
							} else {
								ans+=a[i].x;
								m[1]++;
							}
						}
						else{
							if(m[1]*2!=n) {
								ans+=a[i].x;
								m[1]++;
							} else {
								ans+=a[i].y;
								m[2]++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
