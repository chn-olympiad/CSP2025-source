#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],mx[N],md[N],ans,len;
vector<int>g[4];
bool cmp(int x,int y){return mx[x]-md[x]<mx[y]-md[y];}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			mx[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			md[i]=a[i][1]+a[i][2]+a[i][3]-mx[i]-min(min(a[i][1],a[i][2]),a[i][3]);
			ans+=mx[i];
		}
		for(int i=1;i<=3;i++)g[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==mx[i]){
					g[j].push_back(i);
					break;
				}
			}
		}
		for(int i=1;i<=3;i++){
			len=g[i].size();
			if(len>n/2){
				sort(g[i].begin(),g[i].end(),cmp);
				for(int j=0;len-j>n/2;j++)ans-=(mx[g[i][j]]-md[g[i][j]]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}