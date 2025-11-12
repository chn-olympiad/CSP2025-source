#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
using namespace std;
const int mo=998244353;
int n,a[5010],b[25000010],ans,w;
priority_queue<pr,vector<pr>,greater<pr> >q;
pr u;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	q.push(make_pair(0,0));
	b[0]=1;
	for(int i=1;i<=n;++i){
		while(q.top().first!=i){
			u=q.top(),w=u.second;
			q.pop();
			if(-w>a[i])
				ans=(ans+b[-w])%mo;
			if(!b[-(w-a[i])])
				q.push(make_pair(i,w-a[i]));
			b[-(w-a[i])]=(b[-(w-a[i])]+b[-w])%mo;
			q.push(make_pair(i,w));
		}
	}
	cout<<ans;
}