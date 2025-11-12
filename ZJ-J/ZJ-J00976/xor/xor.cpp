#include<bits/stdc++.h>
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],to[maxn],la=0,ans=0;
priority_queue<pii,vector<pii>,greater<pii> >qu;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j<=n;j++){
			x=(x^a[j]);
			if(x==m){
				to[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(to[i]){
			qu.push(make_pair(to[i],i));
		}
	}
	while(!qu.empty()){
		pii now=qu.top();
		qu.pop();
		if(now.sec<=la)continue;
		ans++,la=now.fir;
	}
	cout<<ans;
	return 0;
}