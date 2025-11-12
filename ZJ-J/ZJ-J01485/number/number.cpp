#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],pos;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++pos]=s[i]-48;
		}
	}
	sort(a+1,a+pos+1,greater<int>());
	for(int i=1;i<=pos;i++){
		cout<<a[i];
	}
	return 0;
}
