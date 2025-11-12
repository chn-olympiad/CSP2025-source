#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define R register
#define LL long long
using namespace std;
const int N=1e5+10;
int T,n,a[N],b[N],c[N],id[N],cmx[N];
LL ans;
priority_queue<int,vector<int>,greater<int> >qa,qb,qc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		while(qa.size()) qa.pop();
		while(qb.size()) qb.pop();
		while(qc.size()) qc.pop();
		cin>>n;
		ans=0;
		for(R int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			int k=max(a[i],max(b[i],c[i]));
			ans+=k;
			if(k==a[i]) id[i]=1,cmx[i]=a[i]-max(b[i],c[i]);
			else if(k==b[i]) id[i]=2,cmx[i]=b[i]-max(a[i],c[i]);
			else id[i]=3,cmx[i]=c[i]-max(a[i],b[i]);
		}
		for(R int i=1;i<=n;i++){
			if(id[i]==1) qa.push(cmx[i]);
			else if(id[i]==2) qb.push(cmx[i]);
			else qc.push(cmx[i]);
		}
		while(qa.size()>n/2){
			int t=qa.top();
			qa.pop();
			ans-=t;
		}
		while(qb.size()>n/2){
			int t=qb.top();
			qb.pop();
			ans-=t;
		}
		while(qc.size()>n/2){
			int t=qc.top();
			qc.pop();
			ans-=t;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
