#include<bits/stdc++.h>
using namespace std;
const int MN=2e5+5;
int n,vis[MN];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q1,q2,q3;
queue<int> q;
int a[4][MN],v[MN][4];
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	cin>>n;
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
//	cout<<1;
	int ans=0;
	for(int i=1;i<=n;i++){
//		cout<<1;
		cin>>a[1][i]>>a[2][i]>>a[3][i];
		v[i][1]=a[1][i],v[i][2]=a[2][i],v[i][3]=a[3][i];
		q.push(i);
//		cout<<q.front();
	}
//	cout<<1;
	for(int i=1;i<=n;i++)sort(v[i]+1,v[i]+4,cmp);
	while(!q.empty()){
		int i=q.front();
//		cout<<" "<<" ";
		q.pop();
		if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){
			if(q1.size()<n/2)q1.push({a[1][i],i});
			else if(a[1][i]+v[q1.top().second][2]>q1.top().first+v[i][2]){
//				cout<<q1.top().first+v[i][2];
                int k=q1.top().second;q1.pop();
				q1.push({a[1][i],i});
				q.push(k);
			}
			else if(a[2][i]>a[3][i]){
//				cout<<v[q1.top().second][1]<<" ";
				q2.push({a[2][i],i});
			}
			else q3.push({a[3][i],i});
		}
		else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]){
			if(q2.size()<n/2)q2.push({a[2][i],i});
			else if(a[2][i]+v[q2.top().second][2]>q2.top().first+v[i][2]){
//				cout<<q2.top().second<<" "<<i<<endl;
				int k=q2.top().second;q2.pop();
				q2.push({a[2][i],i});
				q.push(k);
//				cout<<q2.top().second;
			}
			else if(a[1][i]>a[3][i]){
				q1.push({a[1][i],i});
			}
			else q3.push({a[3][i],i});
		}
		else if(a[3][i]>=a[2][i]&&a[3][i]>=a[1][i]){
//			cout<<1;
			if(q3.size()<n/2)q3.push({a[3][i],i});
			else if(a[3][i]+v[q3.top().second][2]>q3.top().first+v[i][2]){
				int k=q3.top().second;q3.pop();
				q3.push({a[3][i],i});
				q.push(k);
			}
			else if(a[2][i]>=a[1][i]){
				q2.push({a[2][i],i});
			}
			else q1.push({a[1][i],i});
		}
	}
	while(!q1.empty()){
		ans+=q1.top().first;
//		cout<<q1.top().second<<" ";  
		q1.pop();
	}
//	cout<<endl;
	while(!q2.empty()){
		ans+=q2.top().first;
//		cout<<q2.top().second<<" ";
		q2.pop();
	}
//	cout<<endl;
	while(!q3.empty()){
		ans+=q3.top().first;
//		cout<<q3.top().second<<" ";
		q3.pop();
	}
//	cout<<endl;
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
//	cout<<1;
	while(t--)solve();
	return 0;
} 
