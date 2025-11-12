#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,y,z;
};
node a[100010];

int f[100010];

struct ch{
	int x,id;
};

bool cmp(ch a,ch b){
	return a.x>b.x;
}

void calc(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	int ans=0;
	for(int i=1;i<=n;i++) f[i]=1;
	ch b[100010];
	for(int i=1;i<=n;i++) b[i]={a[i].y-a[i].x,i};
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n/2;i++) f[b[i].id]=2;
	ch c[100010];
	for(int i=1;i<=n;i++){
		int x;
		if(f[i]==1) x=a[i].x;
		else x=a[i].y;
		c[i]={a[i].z-x,i};
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		if(c[i].x<=0) break;
		f[c[i].id]=3;
	}
	for(int i=1;i<=n;i++){
		int x;
		if(f[i]==1) x=a[i].x;
		else if(f[i]==2) x=a[i].y;
		else x=a[i].z;
		ans+=x;
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) calc();
	return 0;
}
