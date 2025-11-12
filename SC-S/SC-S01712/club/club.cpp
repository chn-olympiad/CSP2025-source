#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,id;
};
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,ans=0;cin>>n;
		int d[n+5],x=0,y=0,z=0;
		node a[n+5],b[n+5],c[n+5];
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>b[i].a>>c[i].a;
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int e=1,f=1,g=1;
		while(e<n){
		//	cout<<a[e].a<<'\n';
			while(d[a[e].id]==-1) e++;
			while(d[b[f].id]==-1) f++;
			while(d[c[g].id]==-1) g++;
			if(a[e].a>b[f].a&&a[e].a>c[g].a){
				ans+=a[e].a;
				e++;
				d[a[e].id]=-1;
			}
			if(b[f].a>a[e].a&&b[f].a>c[g].a){
				ans+=b[f].a;
				f++;
				d[b[f].id]=-1;
			}
			else{
				ans+=c[g].a;
				g++;
				d[c[g].id]=-1;
			}

		}
		cout<<ans;
	}
}
