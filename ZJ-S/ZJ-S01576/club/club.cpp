#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,b[3],ans,maxx;
priority_queue<int,vector<int>,greater<int> > pq[3];
struct node{
	int x,id;
}a[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n;
		maxx=n>>1;
		b[0]=b[1]=b[2]=ans=0;
		for(int i=1;i<=n;i++){
			a[0].id=0;
			a[1].id=1;
			a[2].id=2;
			cin>>a[0].x>>a[1].x>>a[2].x;
			sort(a,a+3,[](node ii,node j){return ii.x>j.x;});
			if(b[a[0].id]==maxx){
				int k=pq[a[0].id].top();
				if(k<a[0].x-a[1].x){
					ans=ans-k+a[0].x;
					pq[a[0].id].pop();
					pq[a[0].id].push(a[0].x-a[1].x);
				}
				else{
					ans+=a[1].x;
					b[a[1].id]++;
					pq[a[1].id].push(a[1].x-a[2].x);
				}
			}
			else{
				b[a[0].id]++;
				pq[a[0].id].push(a[0].x-a[1].x);
				ans+=a[0].x;
			}
		}
		cout<<ans<<'\n';
		priority_queue<int,vector<int>,greater<int> > pp[3];
		pq[0].swap(pp[0]);
		pq[1].swap(pp[1]);
		pq[2].swap(pp[2]);
	}
	return 0;
}
