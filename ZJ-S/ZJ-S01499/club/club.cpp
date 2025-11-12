#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int p[4];
};
node a[N];
vector<int> v[10];
int p;
bool cmp(int A,int B){
	int mxA=0;
	int mxB=0;
	for(int i=1;i<=3;i++)if(i!=p)mxA=max(mxA,a[A].p[i]);
	for(int i=1;i<=3;i++)if(i!=p)mxB=max(mxB,a[B].p[i]);
	return a[A].p[p]-mxA<a[B].p[p]-mxB;
}
int n;
int solve(int id){
	int ans=0;
	for(int to:v[id])ans+=a[to].p[id];
	p=id;
	sort(v[id].begin(),v[id].end(),cmp);
	for(int i=0;i<v[id].size()-n/2;i++){
		int mx=0;
		for(int j=1;j<=3;j++)if(j!=id)mx=max(mx,a[v[id][i]].p[j]);
		ans-=a[v[id][i]].p[id]-mx;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//good tanxin,thought out at 2025.11.1 14:54 
	//ACed example at 15:13
	//ACed big example at 15:17
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++)v[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i].p[1]>>a[i].p[2]>>a[i].p[3];
			int id=0;
			int mx=0;
			for(int j=1;j<=3;j++){
				if(a[i].p[j]>mx){
					mx=a[i].p[j];
					id=j;
				}
			}
			v[id].push_back(i);
		}
		int ans=0;
		for(int i=1;i<=3;i++){
			if(v[i].size()>n/2){
				ans+=solve(i);
			}
			else{
				for(int to:v[i])ans+=a[to].p[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}