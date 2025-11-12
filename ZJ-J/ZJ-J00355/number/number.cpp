#include <bits/stdc++.h>
using namespace std;
string s,x;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			x+=s[i];
		}
	}
	sort(x.begin(),x.end(),cmp);
	cout<<x;
	return 0;
}

