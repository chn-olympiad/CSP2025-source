#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N]={0},t=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cout<<s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(1+a,1+a+t);
	for(int i=t;i>=1;i--) cout<<a[i];
	return 0;
}
