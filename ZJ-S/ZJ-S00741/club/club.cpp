#include<bits/stdc++.h>
#define N 100010
using namespace std;
typedef long long ll;
int n;
int a[N][4],v[4];
ll ans;
void work(int p,ll res){
	if(p>n){ans=max(ans,res);return;}
	for(int i=1;i<=3;i++){
		if(v[i]>=n/2)continue;
		v[i]++;
		res+=a[p][i];
		work(p+1,res);
		v[i]--;
		res-=a[p][i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,pp;
	cin>>T;
	while(T--){
		cin>>n;
		ans=pp=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2 and a[i][j]==0 or j==3 and a[i][j]==0)pp++;
			}
		if(pp==2*n){
			int top=0;
			priority_queue<int> q;
			for(int i=1;i<=n;i++)q.push(a[i][1]);
			while(top<n/2 and q.size()){
				ans+=q.top();q.pop();
				top++;
			}
			cout<<ans;
			return 0;
		}	
		work(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}