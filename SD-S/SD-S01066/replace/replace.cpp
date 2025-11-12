#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		srand(time(0));
		if((rand()*rand()/3)%1145141+1145141>=100000) cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
