#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000010];
int l;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))
			c[++l]=s[i];
	sort(c+1,c+1+l,cmp);
	if(c[1]=='0')
		cout<<0;
	else
		for(int i=1;i<=l;i++)
			cout<<c[i];
	return 0;
}
