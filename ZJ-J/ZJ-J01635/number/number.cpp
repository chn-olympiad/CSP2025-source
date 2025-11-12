#include<bits/stdc++.h>
using namespace std;
string a;
vector<int>v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;++i){
		if(isdigit(a[i])){
			v.push_back((a[i]&15));
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	l=v.size();
	for(int i=0;i<l;++i) cout<<v[i];
	return 0;
}
