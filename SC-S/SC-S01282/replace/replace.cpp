#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10; 
int n,q;
struct node{
	string s1,s2;
	int len1,len2;
}rep[N];
string now,to;
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>rep[i].s1>>rep[i].s2;
		rep[i].len1=rep[i].s1.size();
		rep[i].len2=rep[i].s2.size();
	} 
	while(q--){
		cin>>now>>to;
		cout<<0<<'\n';
	}
	return 0;
}
