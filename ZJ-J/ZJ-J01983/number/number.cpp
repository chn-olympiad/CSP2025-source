#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
bool f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[int(s[i]-'0')]++;
	for(int i=9;i>=1;i--)
		for(int j=1;j<=cnt[i];j++){
			f=1;
			cout<<i;
		}
	if(f)
		for(int j=1;j<=cnt[0];j++)
			cout<<0;
	else
		cout<<0;
	return 0;
}