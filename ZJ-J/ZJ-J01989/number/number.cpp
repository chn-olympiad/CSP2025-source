#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9') v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end(),cmp);
	for(long long i=0;i<v.size();i++){
		cout<<v[i];
	}
	return 0;
}
