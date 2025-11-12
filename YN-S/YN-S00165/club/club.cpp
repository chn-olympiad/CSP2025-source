//I love Nagato Yuki forever!!!
//Finish at 2025/11/01 14:46:06
#include<bits/stdc++.h>
using namespace std;
namespace Z3k7223{
	const int N=1e5+10;
	int n;
	void solve(){
		int ans=0;
		vector<int>a,b,c;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			int maxx=max(max(x,y),z);
			ans+=maxx;
			if(x==maxx){
				a.push_back(x-max(y,z));
			}else if(y==maxx){
				b.push_back(y-max(x,z));
			}else{
				c.push_back(z-max(x,y));
			}
		}
		if(a.size()>n/2){
			sort(a.begin(),a.end());
			for(int i=0;i<a.size()-n/2;i++){
				ans-=a[i];
			}
		}
		if(b.size()>n/2){
			sort(b.begin(),b.end());
			for(int i=0;i<b.size()-n/2;i++){
				ans-=b[i];
			}
		}
		if(c.size()>n/2){
			sort(c.begin(),c.end());
			for(int i=0;i<c.size()-n/2;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<'\n';
	}
	void main(){
		int t;
		cin>>t;
		while(t--){
			solve();
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Z3k7223::main();
	return 0;
}
