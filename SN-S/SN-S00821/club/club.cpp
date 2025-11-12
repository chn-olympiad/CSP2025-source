//齐睿渊 SN-S00821 富平县怀德初级中学
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node {
	int x,y,z;
} a[N];
struct node1 {
	int l,num;
} p[N][5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		long long ans=0;
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		bool flo=0;
		for(int i=0; i<n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0&&a[i].z!=0) {
				flo=1;
			}
		}
		int maxnum=n/2;
		if(flo==0) {
			vector<int> qy(n);
			for(int i=0; i<n; i++) {
				if(a[i].y==0&&a[i].z==0) {
					qy[i]=a[i].x;
				}
			}
			int people=0;
			sort(qy.begin(),qy.end());
			for(int i=qy.size()-1; i>=0; i--) {
				if(people<maxnum) {
					ans+=qy[i];
					people++;
				}
			}
			cout<<ans<<endl;
		} else {
			for(int i=0; i<n; i++) {
				if(a[i].x>=a[i].y&&a[i].y>=a[i].z) {
					p[i][1].l=1;
					p[i][1].num=a[i].x;
					p[i][2].l=2;
					p[i][2].num=a[i].y;
					p[i][3].l=3;
					p[i][3].num=a[i].z;
				} else if(a[i].x>=a[i].y&&a[i].z>=a[i].y) {
					if(a[i].x>=a[i].z) {
						p[i][1].l=1;
						p[i][1].num=a[i].x;
						p[i][2].l=3;
						p[i][2].num=a[i].z;
						p[i][3].l=2;
						p[i][3].num=a[i].y;
					} else if(a[i].x<a[i].z) {
						p[i][1].l=3;
						p[i][1].num=a[i].z;
						p[i][2].l=1;
						p[i][2].num=a[i].x;
						p[i][3].l=2;
						p[i][3].num=a[i].y;
					}
				} else if(a[i].y>=a[i].x&&a[i].z>=a[i].x) {
					if(a[i].y>=a[i].z) {
						p[i][1].l=2;
						p[i][1].num=a[i].y;
						p[i][2].l=3;
						p[i][2].num=a[i].z;
						p[i][3].l=1;
						p[i][3].num=a[i].x;
					} else if(a[i].y<a[i].z) {
						p[i][1].l=3;
						p[i][1].num=a[i].z;
						p[i][2].l=2;
						p[i][2].num=a[i].y;
						p[i][3].l=1;
						p[i][3].num=a[i].x;
					}
				} else if(a[i].x>=a[i].z&&a[i].y>=a[i].z) {
					if(a[i].x>=a[i].y) {
						p[i][1].l=1;
						p[i][1].num=a[i].x;
						p[i][2].l=2;
						p[i][2].num=a[i].y;
						p[i][3].l=3;
						p[i][3].num=a[i].z;
					} else if(a[i].x<a[i].y) {
						p[i][1].l=2;
						p[i][1].num=a[i].y;
						p[i][2].l=1;
						p[i][2].num=a[i].x;
						p[i][3].l=3;
						p[i][3].num=a[i].z;
					}
				}

			}
			vector<int> v(n);
			bool flag=1;
			for(int i=0; i<n; i++) {
				v[p[i][1].l]++;
			}
			for(int i=0; i<n; i++) {
				if(v[i]>maxnum) {
					flag=0;
					break;
				}
			}
			if(flag==1) {
				for(int i=0; i<n; i++) {
					ans+=p[i][1].num;
				}
				cout<<ans<<endl;
			} else {
				long long xr=0,yr=0,zr=0;
				vector<int> vx(n),vy(n),vz(n),vis(n);
				for(int i=0; i<n; i++) {
					if(p[i][1].l==1) {
						vx[i]=p[i][1].num;
					} else if(p[i][2].l==1) {
						vx[i]=p[i][2].num;
					} else if(p[i][3].l==1) {
						vx[i]=p[i][3].num;
					}


				}
				sort(vx.begin(),vx.end());
				for(int i=vx.size()-1; i>=0; i--) {
					if(xr<maxnum) {
						ans+=vx[i];
						xr++;
					}

				}
				for(int i=0; i<n; i++) {
					if(p[i][1].l==2) {
						vy[i]=p[i][1].num;
					} else if(p[i][2].l==2) {
						vy[i]=p[i][2].num;
					} else if(p[i][3].l==2) {
						vy[i]=p[i][3].num;
					}


				}
				sort(vy.begin(),vy.end());
				for(int i=vy.size()-1; i>=0; i--) {
					if(yr<maxnum) {
						ans+=vy[i];
						yr++;
					}

				}
				for(int i=0; i<n; i++) {
					if(p[i][1].l==3) {
						vz[i]=p[i][1].num;
					} else if(p[i][2].l==3) {
						vz[i]=p[i][2].num;
					} else if(p[i][3].l==3) {
						vz[i]=p[i][3].num;
					}


				}
				sort(vz.begin(),vz.end());
				for(int i=vz.size()-1; i>=0; i--) {
					if(zr<maxnum) {
						ans+=vz[i];
						zr++;
					}

				}
				cout<<ans<<endl;

			}

		}


	}
	return 0;
}
