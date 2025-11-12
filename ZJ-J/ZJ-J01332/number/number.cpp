#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std;
vector<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	fast;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		cout<<a[i];
	}
}
