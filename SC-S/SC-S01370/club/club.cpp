#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
//const int N =
struct node{
	int z,x;
};
bool cmp(node a,node b){
	return a.x>b.x;
}
node b[4],a[4];
void solve(){
	int n,sum=0;
	cin>>n;
	for(int i=0;i<=3;i++) a[i].x=a[i].z=b[i].x=b[i].z=0;
	priority_queue<int,vector<int>,greater<int> >q[4];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[j].x;
			a[j].z=j;
		}
		sort(a+1,a+4,cmp);
		q[a[1].z].push(a[1].x-a[2].x);
		sum+=a[1].x;
		b[a[1].z].x++;
	}
	b[1].z=1,b[2].z=2,b[3].z=3;
	sort(b+1,b+4,cmp);
	int t=b[1].x-n/2;
	while(t>0){
		t--;
		sum-=q[b[1].z].top();
		q[b[1].z].pop();
	}
	cout<<sum<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	} 
	return 0;
}