#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100001],t=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--) cout<<a[i];
	return 0;
}