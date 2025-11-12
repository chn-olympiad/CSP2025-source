#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int c=0;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') a[++c]=s[i];
	sort(a+1,a+1+c);
	for(int i=c;i>=1;i--) cout<<a[i];
	return 0;
}
