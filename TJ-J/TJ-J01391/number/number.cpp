#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[s.size()];
	cin>>s;
	if(s.size()==1){
		cout<<s[0];
		return 0;
		}
	for(int i=0;i<s.size();i++){
		if(s[i]>=1&&s[i]<=9){
			a[i]=s[i];
		}
		else{
			continue;
		}
	}
	sort(a+1,a+s.size());
	for(int i=0;i<s.size();i++){
		cout<<a[i];
	}
	return 0;
}
