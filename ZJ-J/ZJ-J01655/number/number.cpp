#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector<int>n;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			n.push_back(a[i]-'0');
		}
	}
	sort(n.begin(),n.end());
	for(int i=n.size()-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}
