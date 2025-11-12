#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		vector<set<int> >v(3);
		int ans=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b and b>=c){
				v[0].insert(a-b);
				ans+=a;
			}
			else if(a>=c and c>=b){
				v[0].insert(a-c);
				ans+=a;
			}
			else if(b>=c and c>=a){
				v[1].insert(b-c);
				ans+=b;
			}
			else if(b>=a and a>=c){
				v[1].insert(b-a);
				ans+=b;
			}
			else if(c>=a and a>=b){
				v[2].insert(c-a);
				ans+=c;
			}
			else if(c>=b and b>=a){
				v[2].insert(c-b);
				ans+=c;
			}
		}
		if(v[0].size()>n/2){
			int m=v[0].size()-n/2;
			int i=0;
			for(auto j=v[0].begin();i<m;i++,j++){
				ans-=*j;
			}
		}
		if(v[1].size()>n/2){
			int m=v[1].size()-n/2;
			int i=0;
			for(auto j=v[1].begin();i<m;i++,j++){
				ans-=*j;
			}
		}
		if(v[2].size()>n/2){
			int m=v[2].size()-n/2;
			int i=0;
			for(auto j=v[2].begin();i<m;i++,j++){
				ans-=*j;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
