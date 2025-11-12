#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=1e5+10;
vi v[3];
int n,a[N][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int s[3]={0},ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				s[0]++;
				ans+=a[i][0];
				v[0].pb(a[i][0]-max(a[i][1],a[i][2]));
			}
			else if(a[i][1]>a[i][2]){
				s[1]++;
				ans+=a[i][1];
				v[1].pb(a[i][1]-max(a[i][0],a[i][2]));
			}
			else {
				s[2]++;
				ans+=a[i][2];
				v[2].pb(a[i][2]-max(a[i][1],a[i][0]));
			}
		}
		if(s[0]>n/2){
			sort(v[0].begin(),v[0].end());
			for(int i=0;i<s[0]-n/2;i++)ans-=v[0][i];
		}
		if(s[1]>n/2){
			sort(v[1].begin(),v[1].end());
			for(int i=0;i<s[1]-n/2;i++)ans-=v[1][i];
		}
		if(s[2]>n/2){
			sort(v[2].begin(),v[2].end());
			for(int i=0;i<s[2]-n/2;i++)ans-=v[2][i];
		}
		cout<<ans<<"\n";
		for(int i=0;i<3;i++)v[i].clear();
	}
	return 0;
}
