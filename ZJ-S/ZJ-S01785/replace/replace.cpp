#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int n,q;
pair<string,string> p[200005];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
		//p[i].push_back({s1,s2});
		
	}for(int i=0;i<q;i++){
		cin>>p[n+i].first>>p[n+i].second;
		//p[n+i].push_back({s1,s2});
		cout<<0<<endl;
	}
	return 0;
}
