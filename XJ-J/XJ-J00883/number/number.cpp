#include <bits/stdc++.h>
#include <string> 
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=0;
	vector <char> v;
	for(int i=0;i<10001;i++){
		if(s[i]<='9' && s[i]>='0') {
				v.push_back(s[i]);
				n++;
		}
	}
	sort(v.begin(),v.end());
	for(int i=n-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}
