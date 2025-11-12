#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a,b,c,mx[N];
struct node{
	int val,id;
	bool operator <(const node other)const{
		return val>other.val;
	}
};
vector<node>v1,v2,v3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		v1.clear();
		v2.clear();
		v3.clear();
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			mx[i]=max({a,b,c});
			if(a>=b&&b>=c){
				v1.push_back({a-b,i});
			}
			else if(a>=c&&c>=b){
				v1.push_back({a-c,i});
			}
			else if(b>=a&&a>=c){
				v2.push_back({b-a,i});
			}
			else if(b>=c&&c>=a){
				v2.push_back({b-c,i});
			}
			else if(c>=b&&b>=a){
				v3.push_back({c-b,i});
			}
			else {//c>=a&&a>=b
				v3.push_back({c-a,i});
			}
		}
		if(v1.size()>n/2){
			sort(v1.begin(),v1.end());
			for(int i=0;i<n/2;i++){
				ans+=mx[v1[i].id];
			}
			for(int i=n/2;i<v1.size();i++){
				ans+=mx[v1[i].id]-v1[i].val;
			}
			for(int i=0;i<v2.size();i++){
				ans+=mx[v2[i].id];
			}
			for(int i=0;i<v3.size();i++){
				ans+=mx[v3[i].id];
			}
		}
		else if(v2.size()>n/2){
			sort(v2.begin(),v2.end());
			for(int i=0;i<n/2;i++){
				ans+=mx[v2[i].id];
			}
			for(int i=n/2;i<v2.size();i++){
				ans+=mx[v2[i].id]-v2[i].val;
			}
			for(int i=0;i<v1.size();i++){
				ans+=mx[v1[i].id];
			}
			for(int i=0;i<v3.size();i++){
				ans+=mx[v3[i].id];
			}
		}
		else if(v3.size()>n/2){
			sort(v3.begin(),v3.end());
			for(int i=0;i<n/2;i++){
				ans+=mx[v3[i].id];
			}
			for(int i=n/2;i<v3.size();i++){
				ans+=mx[v3[i].id]-v3[i].val;
			}
			for(int i=0;i<v1.size();i++){
				ans+=mx[v1[i].id];
			}
			for(int i=0;i<v2.size();i++){
				ans+=mx[v2[i].id];
			}
		}
		else {
			for(int i=0;i<v1.size();i++){
				ans+=mx[v1[i].id];
			}
			for(int i=0;i<v2.size();i++){
				ans+=mx[v2[i].id];
			}
			for(int i=0;i<v3.size();i++){
				ans+=mx[v3[i].id];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}