#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=100000+10;
int t,n,ans,nx[maxn],ny[maxn],nz[maxn],cx,cy,cz;
struct node{
	int x,y,z,b1,b2,b3,c1,c2;
}a[maxn];
void csh(int i){
	if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
		cx++;nx[cx]=i;ans+=a[i].x;a[i].b1=1;
		if(a[i].y>=a[i].z){
			a[i].b2=2;a[i].b3=3;a[i].c1=a[i].x-a[i].y;a[i].c2=a[i].x-a[i].z;
		}
		else if(a[i].y<=a[i].z){
			a[i].b2=3;a[i].b3=2;a[i].c1=a[i].x-a[i].z;a[i].c2=a[i].x-a[i].y;
		}
	}
	else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
		cy++;ny[cy]=i;ans+=a[i].y;a[i].b1=2;
		if(a[i].x>=a[i].z){
			a[i].b2=1;a[i].b3=3;a[i].c1=a[i].y-a[i].x;a[i].c2=a[i].y-a[i].z;
		}
		else if(a[i].x<=a[i].z){
			a[i].b2=3;a[i].b3=1;a[i].c1=a[i].y-a[i].z;a[i].c2=a[i].y-a[i].x;
		}
	}
	else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
		cz++;ny[cz]=i;ans+=a[i].z;a[i].b1=3;
		if(a[i].x>=a[i].y){
			a[i].b2=2;a[i].b3=3;a[i].c1=a[i].z-a[i].x;a[i].c2=a[i].z-a[i].y;
		}
		else if(a[i].x<=a[i].y){
			a[i].b2=3;a[i].b3=2;a[i].c1=a[i].z-a[i].y;a[i].c2=a[i].z-a[i].x;
		}
	}
}
bool cmp1(node x,node y){
	return x.c1<y.c1;
}
bool cmp2(node x,node y){
	return x.c2<y.c2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cx=0;
		cy=0;
		cz=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			csh(i);
		}
		if(cx<=n/2&&cy<=n/2&&cz<=n/2){
			cout<<ans<<endl;
			continue;
		}
		else{
			if(cx>n/2){
				sort(a+1,a+n+1,cmp1);
				for(int i=1,j=cx;j>n/2;i++){
					if(a[i].b1==1){
						ans-=a[i].c1;
						cx--;
						if(a[i].b2==2) cy++;
						else if(a[i].b2==3) cz++;
						j--;
					}
				}
				if(cx<=n/2&&cy<=n/2&&cz<=n/2){
					cout<<ans<<endl;
					continue;
				}
				else{
					if(cy>n/2){
						sort(a+1,a+n+1,cmp2);
						for(int i=1,j=cy;j>n/2;i++){
							if(a[i].b2==2){
								ans-=(a[i].c1-a[i].c2);
								cy--;
								if(a[i].b2==3) cz++;
								j--;
							}
						}
						cout<<ans<<endl;
						continue;
					}
					else if(cz>n/2){
						sort(a+1,a+n+1,cmp2);
						for(int i=1,j=cz;j>n/2;i++){
							if(a[i].b2==3){
								ans-=(a[i].c1-a[i].c2);
								cz--;
								if(a[i].b2==3) cy++;
								j--;
							}
						}
						cout<<ans<<endl;
						continue;
					}
				}
			}
			else if(cy>n/2){
				sort(a+1,a+n+1,cmp1);
				for(int i=1,j=cy;j>n/2;i++){
					if(a[i].b1==2){
						ans-=a[i].c1;
						cy--;
						if(a[i].b2==1) cx++;
						else if(a[i].b2==3) cz++;
						j--;
					}
				}
				if(cx<=n/2&&cy<=n/2&&cz<=n/2){
					cout<<ans<<endl;
					continue;
				}
				else{
					if(cx>n/2){
						sort(a+1,a+n+1,cmp2);
						for(int i=1,j=cx;j>n/2;i++){
							if(a[i].b2==1){
								ans-=(a[i].c1-a[i].c2);
								cx--;
								if(a[i].b2==3) cz++;
								j--;
							}
						}
						cout<<ans<<endl;
						continue;
					}
					else if(cz>n/2){
						sort(a+1,a+n+1,cmp2);
						for(int i=1,j=cz;j>n/2;i++){
							if(a[i].b2==3){
								ans-=(a[i].c1-a[i].c2);
								cz--;
								if(a[i].b2==3) cx++;
								j--;
							}
						}
						cout<<ans<<endl;
						continue;
					}
				}
			}
			else if(cz>n/2){
				sort(a+1,a+n+1,cmp1);
				for(int i=1,j=cz;j>n/2;i++){
					if(a[i].b1==3){
						ans-=a[i].c1;
						cz--;
						if(a[i].b2==1) cx++;
						else if(a[i].b2==2) cy++;
						j--;
					}
				}
				if(cx<=n/2&&cy<=n/2&&cz<=n/2){
					cout<<ans<<endl;
					continue;
				}
				else{
					if(cx>n/2){
						sort(a+1,a+n+1,cmp2);
						for(int i=1,j=cx;j>n/2;i++){
							if(a[i].b2==1){
								ans-=(a[i].c1-a[i].c2);
								cx--;
								if(a[i].b2==3) cy++;
								j--;
							}
						}
						cout<<ans<<endl;
						continue;
					}
					else if(cy>n/2){
						sort(a+1,a+n+1,cmp2);
						for(int i=1,j=cy;j>n/2;i++){
							if(a[i].b2==2){
								ans-=(a[i].c1-a[i].c2);
								cy--;
								if(a[i].b2==3) cx++;
								j--;
							}
						}
						cout<<ans<<endl;
						continue;
					}
				}
			}
		}
	}
	return 0;
}
//命若繁星，望而不及。赞美【命运】。