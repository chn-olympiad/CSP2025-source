#include<bits/stdc++.h>
/*fjx 20120225 rp++*/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAX=1e7+5;
const ll N=0;
int n;
int b[100005];
struct node{
	int f,s,t,v,l;
}a[100005];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int cnt=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			a[i].v=a[i].f+a[i].s+a[i].t;
		}
		sort(a+1,a+1+n,cmp);
		if(n==2){
			int maxx=-1;
			maxx=max(a[1].f+a[2].s,maxx);
			maxx=max(a[1].f+a[2].t,maxx);
			maxx=max(a[1].t+a[2].s,maxx);
			maxx=max(a[1].t+a[2].f,maxx);
			maxx=max(a[1].s+a[2].f,maxx);
			maxx=max(a[1].s+a[2].t,maxx);
			cout<<maxx<<"\n";
		}else{
			int maxxx=0;
			int maxx=INT_MIN;
			for(int i=1;i<n;i+=2){
				maxx=max(a[i].f+a[i+1].s,maxx);
				maxx=max(a[i].f+a[i+1].t,maxx);
				maxx=max(a[i].t+a[i+1].s,maxx);
				maxx=max(a[i].t+a[i+1].f,maxx);
				maxx=max(a[i].s+a[i+1].f,maxx);
				maxx=max(a[i].s+a[i+1].t,maxx);
				maxxx+=maxx;
			}
			cout<<maxxx<<"\n";
		}
	}
	return 0; 
}
