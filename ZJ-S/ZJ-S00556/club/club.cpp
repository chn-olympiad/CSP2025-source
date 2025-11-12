#include<bits/stdc++.h>
#define ll long long
#define mn 111111
using namespace std;
int t,n,v[5],n2;
ll ans;
struct nod {
	ll x;
	short y;
};
struct node {
	nod b[5];
	ll x;
} a[mn];
bool cmp(nod xx,nod yy) {
	return xx.x>yy.x;
}
bool cmp2(node xx,node yy) {
	return xx.x<yy.x;
}
int main() {
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n,v[1]=v[2]=v[3]=0,n2=n/2,ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) cin>>a[i].b[j].x,a[i].b[j].y=j;
			sort(a[i].b+1,a[i].b+4,cmp);
			a[i].x=a[i].b[1].x-a[i].b[2].x;
			v[a[i].b[1].y]++,ans+=a[i].b[1].x;
		}
		sort(a+1,a+n+1,cmp2);
		int c0=1;
		if(v[1]>n2) {
			//cout<<"1 "<<v[1]<<endl;
			for(int i=1;i<=n && c0<=v[1]-n2;i++) {
				if(a[i].b[1].y==1) ans-=a[i].x,c0++;
			}
		}
		if(v[2]>n2) {
			//cout<<"2 "<<v[2]<<endl;
			for(int i=1;i<=n && c0<=v[2]-n2;i++) {
				if(a[i].b[1].y==2) ans-=a[i].x,c0++;
			}
		}
		if(v[3]>n2) {
			//cout<<"3 "<<v[3]<<endl;
			for(int i=1;i<=n && c0<=v[3]-n2;i++) {
				if(a[i].b[1].y==3) ans-=a[i].x,c0++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin),fclose(stdout);
	return 0; 
}
/*
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