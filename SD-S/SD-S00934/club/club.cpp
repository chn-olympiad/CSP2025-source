#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
using ll=long long;
const int N=2e5+5;
int T,n,a[N],b[N],c[N];
priority_queue<int>q[3];
void solve(){
	for(int i=0;i<=2;i++)while(q[i].size())q[i].pop();
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	ll res=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=b[i]&&a[i]>=c[i]){
			res+=a[i];
			q[0].push(max(b[i]-a[i],c[i]-a[i]));
			while((int)q[0].size()>n/2)res+=q[0].top(),q[0].pop();
		}
		else if(b[i]>=a[i]&&b[i]>=c[i]){
			res+=b[i];
			q[1].push(max(a[i]-b[i],c[i]-b[i]));
			while((int)q[1].size()>n/2)res+=q[1].top(),q[1].pop();
		}
		else if(c[i]>=a[i]&&c[i]>=b[i]){
			res+=c[i];
			q[2].push(max(b[i]-c[i],a[i]-c[i]));
			while((int)q[2].size()>n/2)res+=q[2].top(),q[2].pop();
		}
	}
	cout<<res<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;while(T--)solve();
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

我无力吐槽这个键盘了 

*/

