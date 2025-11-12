#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct Node {
	int x,y,z;
};
Node a[N];
int fa,fb;
int ans;
bool cmpa(Node x,Node y) {
	return x.x>y.x;
}


void dfs(int x,int y,int z,int i,int sum) {
	if(x+y+z==n/2) {
		ans=max(ans,sum);
		return ;
	}
	if(x) {
		dfs(x-1,y,z,i+1,sum+a[i].x);
	}
	if(y) {
		dfs(x,y-1,z,i+1,sum+a[i].y );
	}
	if(z) {
		dfs(x,y,z-1,i+1,sum+a[i].z );
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		ans=0;
		int fx=0,fy=0,fz=0,f=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x!=0) fx=1;
			if(a[i].z!=0) fz=1;
			if(a[i].y!=0) fy=1;
		}
		f=fx+fy+fz;
		if(f==1) {
			for(int i=1; i<=n; i++) {
				a[i].x=max(a[i].x,max(a[i].y,a[i].z));
			}
			sort(a+1,a+1+n,cmpa);
			for(int i=1; i<=n/2; i++) {
				ans+=a[i].x;
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(n/2,n/2,n/2,1,0);
		cout<<ans<<endl;
	}

	return 0;
}
