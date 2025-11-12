#include<bits/stdc++.h>
using namespace std;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>v;
	for(int i=0;i<s.size();i++){
		if(s[i]<'0' || s[i]>'9')continue;
		v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end(),cmp);
	if(v[0]==0){
		cout<<0<<"\n";
		return 0;
	}
	for(int to:v)cout<<to;
	cout<<"\n";
	return 0;
}
