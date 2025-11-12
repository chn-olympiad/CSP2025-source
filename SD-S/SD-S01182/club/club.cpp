#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second
#define pb emplace_back

const int N=200010;

int t,n,a[N][4],mx[N],cmx[N],p1[N],p2[N],cun[4],ans;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;cun[1]=cun[2]=cun[3]=0;ans=0;
		for(int i=1;i<=n;i++){
			mx[i]=cmx[i]=p1[i]=p2[i]=0;
			for(int j=1;j<=3;j++)
			cin>>a[i][j];
			for(int j=1;j<=3;j++){
				if(a[i][j]>mx[i]){
					cmx[i]=mx[i];p2[i]=p1[i];
					mx[i]=a[i][j],p1[i]=j;
				}
				else{
					if(a[i][j]>cmx[i]){
						cmx[i]=a[i][j];
						p2[i]=j;
					}
				}
			}
			cun[p1[i]]++;ans+=mx[i];
		}
		int n1=n/2;
		priority_queue<int,vector<int>,greater<int>> q;
		while(!q.empty())q.pop();
		if(cun[1]>n1){
			for(int i=1;i<=n;i++){
				if(p1[i]==1){
					q.push(mx[i]-cmx[i]);
				}
			}
			while(cun[1]>n1){
				int k=q.top();q.pop();
				cun[1]--;ans-=k;
			}
		}
		else if(cun[2]>n1){
			for(int i=1;i<=n;i++){
				if(p1[i]==2){
					q.push(mx[i]-cmx[i]);
				}
			}
			while(cun[2]>n1){
				int k=q.top();q.pop();
				cun[2]--;ans-=k;
			}
		}
		else if(cun[3]>n1){
			for(int i=1;i<=n;i++){
				if(p1[i]==3){
					q.push(mx[i]-cmx[i]);
				}
			}
			while(cun[3]>n1){
				int k=q.top();q.pop();
				cun[3]--;ans-=k;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
