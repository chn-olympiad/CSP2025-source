#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;
int a[N];
vector<pair<int,int> > s;
int n,k;
int st[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ll=0;
		for(int j=i;j<=n;j++){
			ll^=a[j];
			if(ll==k){
				s.push_back({j-i+1,j});
				break;
			}
		}
	}
	sort(s.begin(),s.end());
	int ans=0;
	
	for(int i=0;i<s.size();i++){
		int l=s[i].second-s[i].first+1,r=s[i].second;
		bool h;
		for(int j=l;j<=r;j++)if(st[j]){
			h=1;
			break;
		}
		if(h)continue;
		ans++;
		for(int j=l;j<=r;j++)st[j]=1;
	}
	cout<<ans<<endl;
	return 0;
}
