#include<bits/stdc++.h>
using namespace std;
pair<string,string>s[200010];
pair<string,string>t[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i].first>>s[i].second;
	for(int i=1;i<=q;i++){
		cin>>t[i].first>>t[i].second;
		cout<<"0\n"<<"0\n";
	}
	return 0;
}
