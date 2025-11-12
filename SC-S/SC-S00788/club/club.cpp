#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int x,y,z,mx=0,md,mn=0,idx;
}a[N];
void mxdn(int i){
	int xm;
	xm=max(max(a[i].x,a[i].y),a[i].z);
	if(xm==a[i].x) a[i].mx=1;
	else if(xm==a[i].y) a[i].mx=2;
	else a[i].mx=3;
	int nm;
	nm=min(min(a[i].x,a[i].y),a[i].z);
	if(nm==a[i].x) a[i].mn=1;
	else if(nm==a[i].y) a[i].mn=2;
	else a[i].mn=3;
	if(a[i].mx==1){
		if(a[i].mn==2){
			a[i].md=3;
		}
		else if(a[i].mn==3){
			a[i].md=2;
		}
	}
	else if(a[i].mx==2){
		if(a[i].mn==3){
			a[i].md=1;
		}
		else if(a[i].mn==1){
			a[i].md=3;
		}
	}
	else if(a[i].mx==3){
		if(a[i].mn==2){
			a[i].md=1;
		}
		else if(a[i].mn==1){
			a[i].md=2;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].idx=i;
			mxdn(i);
			int q=0,w=0,e=0;
			if(a[i].mx==1){
				q++;
				if(q>n/2){
					q--;
					if(a[i].md==2){
						w++;
						if(w>n/2){
							w--;
							e++;
							ans+=a[i].mn;
						}
					}
					else if(a[i].md==3){
						e++;
						if(e>n/2){
							e--;
							w++;
							ans+=a[i].mn;
						}
					}
				}
				else{
					ans+=a[i].x;
				}
			}
			else if(a[i].mx==2){
				w++;
				if(w>n/2){
					w--;
					if(a[i].md==1){
						q++;
						if(q>n/2){
							q--;
							e++;
							ans+=a[i].mn;
						}
					}
					else if(a[i].md==3){
						e++;
						if(e>n/2){
							e--;
							q++;
							ans+=a[i].mn;
						}
					}
				}
				else{
					ans+=a[i].y;
				}
			}
			else if(a[i].mx==3){
				e++;
				if(e>n/2){
					e--;
					if(a[i].md==1){
						q++;
						if(q>n/2){
							q--;
							w++;
							ans+=a[i].mn;
						}
					}
					else if(a[i].md==2){
						w++;
						if(w>n/2){
							w--;
							q++;
							ans+=a[i].mn;
						}
					}
				}
			}
			else{
				ans+=a[i].z;
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
