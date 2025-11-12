#include <bits/stdc++.h>
using namespace std;
vector<signed> vt;
vector<signed> s;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	signed n,k;
	cin>>n>>k;
	vt.resize(n+1);
	s.resize(n+1);
	for(signed i=1;i<vt.size();i++){
		cin>>vt[i];
		s[i]=(s[i-1]^vt[i]);
	}
	signed sum=0,flag=0;
	for(signed i=1;i<s.size();i++){
		for(signed j=flag;j<i;j++){
			if((s[i]^s[j])==k){
				sum++;
				flag=i;
				break;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}