#include<bits/stdc++.h>
#define int long long
#define pub push_back
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
int T,n,ans;
struct peo{
	int a[5],mxnum,mxid;
}d[100009];
priority_queue<peo> qu1,qu2,qu3;
bool operator <(peo a,peo b){
	int val1=a.a[1]-a.a[2];
	int val2=b.a[1]-b.a[2];
	return val1>val2;
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>d[i].a[1]>>d[i].a[2]>>d[i].a[3];
			if(d[i].a[1]>=d[i].a[2]&&d[i].a[1]>=d[i].a[3]) d[i].mxid=1;
			if(d[i].a[2]>=d[i].a[1]&&d[i].a[2]>=d[i].a[3]) d[i].mxid=2;
			if(d[i].a[3]>=d[i].a[1]&&d[i].a[3]>=d[i].a[2]) d[i].mxid=3;
			sort(d[i].a+1,d[i].a+1+3,cmp);
			ans+=d[i].a[1];
		}
		while(qu1.size()) qu1.pop();
		while(qu2.size()) qu2.pop();
		while(qu3.size()) qu3.pop();
	//	cout<<"stans:"<<ans<<"\n";
		for(int i=1;i<=n;i++){
			if(d[i].mxid==1) qu1.push(d[i]);
			if(d[i].mxid==2) qu2.push(d[i]);
			if(d[i].mxid==3) qu3.push(d[i]);
		}
		while(qu1.size()>n/2){
			ans-=(qu1.top().a[1]-qu1.top().a[2]);
			qu1.pop();
		}
		while(qu2.size()>n/2){
			ans-=(qu2.top().a[1]-qu2.top().a[2]);
			qu2.pop();
		}
		while(qu3.size()>n/2){
			ans-=(qu3.top().a[1]-qu3.top().a[2]);
			qu3.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
