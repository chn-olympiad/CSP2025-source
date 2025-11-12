#include<bits/stdc++.h>
using namespace std;
string s;
int x,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	s=' '+s;
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=s[i]-'0';
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--)
		cout<<a[i];
	return 0;
}
