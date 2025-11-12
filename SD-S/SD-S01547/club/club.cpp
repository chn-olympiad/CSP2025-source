#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005][4],T,ans,c[4],mx,ch[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ans=0;c[1]=0;c[2]=0;c[3]=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				c[1]++;
				ch[i]=1;
				ans+=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				c[2]++;
				ch[i]=2;
				ans+=a[i][2];
			}
			else{
				c[3]++;
				ch[i]=3;
				ans+=a[i][3];
			}
		}
		if(c[1]*2<=n&&c[2]*2<=n&&c[3]*2<=n){
			cout<<ans<<'\n';
			continue;
		}
		if(c[1]*2>n)mx=1;
		if(c[2]*2>n)mx=2;
		if(c[3]*2>n)mx=3;
		vector<int>v;
		for(int i=1;i<=n;i++){
			if(ch[i]!=mx)continue;
			if(mx==1)v.push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			if(mx==2)v.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			if(mx==3)v.push_back(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<c[mx]-n/2;i++)ans-=v[i];
		cout<<ans<<'\n';
	}	
	return 0;
}/*
1
2
10 9 8
4 0 0
*/

