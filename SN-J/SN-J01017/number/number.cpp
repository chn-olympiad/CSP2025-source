#include<bits/stdc++.h>
using namespace std;
string s;
string a[1000005];
int main(){
	freopen("number.in" ,"r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i = 0;i<s.size();i++){
		if (s[i]<='9' && s[i]>='0'){
			a[i]=s[i];
		}
	}
	sort(a,a+s.size());
	for (int i = s.size()+1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
