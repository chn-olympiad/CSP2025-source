//SN-J00338 张巍骞 曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	vector<int> a; 
	for(int i = 0; i< s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			int q= s[i]-'0';
			a.push_back(q);
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i = 0; i<a.size(); i++){
		cout<<a[i];
	}
	return 0;
}
