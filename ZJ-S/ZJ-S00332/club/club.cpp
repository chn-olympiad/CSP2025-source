#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n,sm=0;
 pair<int,int>a[100010][3],t[3];
 vector<int>ar;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		t[0]={0,0};
		t[1]={0,1};
		t[2]={0,2};
		sm=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0].first>>a[i][1].first>>a[i][2].first;
			a[i][0].second=0;
			a[i][1].second=1;
			a[i][2].second=2;
			sort(a[i],a[i]+3);
			t[a[i][2].second].first++;
			sm+=a[i][2].first;
		}
		sort(t,t+3);
		if(t[2].first>n/2){
			ar.clear();
			for(int i=1;i<=n;i++){
				if(a[i][2].second!=t[2].second)continue;
				ar.push_back(a[i][2].first-a[i][1].first);
			}
			sort(ar.begin(),ar.end());
			for(int i=0,sz=t[2].first-n/2;i<sz;i++)sm-=ar[i];
		}
		cout<<sm<<"\n";
	}
	return 0;
}
