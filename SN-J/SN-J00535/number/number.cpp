#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin);
#define FO(x) freopen(x".out","w",stdout);
string s;
vector<int> a;
int main(){
	FI("number");
	FO("number");
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a.push_back((s[i]-'0')*-1);
		}
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		cout<<a[i]*-1;
	} 
	return 0;
}
