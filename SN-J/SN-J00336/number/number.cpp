#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);  
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000005],l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
