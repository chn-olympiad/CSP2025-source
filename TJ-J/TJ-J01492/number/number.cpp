#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int in=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[in]=(s[i]-48);
			in++;
		}
	}
	sort(a,a+in,greater<int>());
	for(int i=0;i<in;i++){
		cout<<a[i];
	}
}
