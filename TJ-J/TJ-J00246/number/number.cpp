#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
vector<int>a;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	
	int ls=s.size();
	for(int i=0;i<ls;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
}
