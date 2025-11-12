#include<bits/stdc++.h>
using namespace std;
int t;
bool cmp(pair<int,int> d,pair<int,int> e){
	return d.first<e.first;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		int n,a[100005][5],x=0,y=0,z=0,s=0,b[100005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
				x++;
				b[i]=1;
			}
			else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))){
				y++;
				b[i]=2;
			}
			else if(a[i][3]==max(a[i][1],max(a[i][2],a[i][3]))){
				z++;
				b[i]=3;
			}
			s+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(x>n/2){
			pair<int,int> c[100005];
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					if(a[i][2]>=a[i][3]){
						c[i].first=a[i][1]-a[i][2];
						c[i].second=2;
					}
					else{
						c[i].first=a[i][1]-a[i][3];
						c[i].second=3;
					}
				}
			}
			sort(c+1,c+1+n,cmp);
			for(int i=1+n-x;i<=n-n/2;i++){
				s-=c[i].first;
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
