#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,t,ans,l[4];

struct node{
	int a[4];
	int p[4];
}m[N];

void px(int k){
	int maxx=0,minn=INT_MAX;
	int td,tx;
	for(int j=1;j<=3;j++){
		if(m[k].a[j]>=maxx){
			maxx=m[k].a[j];
			td=j;
		}
		if(m[k].a[j]<=minn){
			minn=m[k].a[j];
			tx=j;
		}
	}
	
	m[k].p[1]=td;
	m[k].p[2]=6-td-tx;
	m[k].p[3]=tx;
}
bool cmp(node x,node y){
	return x.a[x.p[1]]-x.a[x.p[2]]>y.a[y.p[1]]-y.a[y.p[2]];
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		l[1]=l[2]=l[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>m[i].a[j];
			}
			px(i);
//			cout<<m[i].a[m[i].p[1]]<<" "<<m[i].a[m[i].p[2]]<<endl;
		}
		sort(m+1,m+1+n,cmp);
		for(int i=1;i<=n;i++){
			int t=m[i].p[1],t2=m[i].p[2];
//			int t2=m[i].p[2],pt2=m[i-1].p[2];
			if(l[t]<n/2||i==1){
				ans+=m[i].a[t];
				l[t]++;
			}else{
				ans+=m[i].a[t2];
				l[t2]++;
//				if(m[i-1].a[pt]<=m[i-1].a[pt2]+m[i].a[t]){
//					l[]
//				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
  
