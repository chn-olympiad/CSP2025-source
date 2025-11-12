#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int N=1e5+5;
int n;
struct node{
	pii val[5];
	int f_s,v;
}a[N];
bool pan(node x,node y){
	return x.f_s<y.f_s;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<node>nd[5];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].val[j].first;
				a[i].val[j].second=j;
			}
			sort(a[i].val+1,a[i].val+4);
			a[i].v=a[i].val[3].first;
			a[i].f_s=a[i].v-a[i].val[2].first;
			nd[a[i].val[3].second].push_back(a[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;i++)ans+=(ll)a[i].v;
		for(int i=1;i<=3;i++)
			if(nd[i].size()>n/2){
				sort(nd[i].begin(),nd[i].end(),pan);
				for(int j=0;j<nd[i].size()-n/2;j++)
					ans-=(ll)nd[i][j].f_s;
				break;
			}
		cout<<ans<<'\n';
	}
	return 0;
}
