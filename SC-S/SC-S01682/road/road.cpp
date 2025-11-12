#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ebdl '\n'
const int N=2e5;

int n,q; 
struct node{
	string f,s;
};
node a[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].f>>a[i].s;
	}
	string s1,s2;
	string x,y,z;
	while(q--){
		cin>>s1>>s2;
		int xe,zs;
		for(int i=0;i<=s1.size();i++){
			if(s1[i]==s2[i]) x+=s1[i];
			else{
				xe=i;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;i--){
			if(s1[i]==s2[i]) z+=s1[i];
			else{
				zs=i;
				break;
			}
		}
		if(x==""||z==""){
			cout<<0<<endl;
			continue;
		}
		
	}
	return 0;
}
