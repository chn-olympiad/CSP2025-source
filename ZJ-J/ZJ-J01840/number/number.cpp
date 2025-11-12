#include <bits/stdc++.h>
using namespace std;
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Ios();
	string s;
	cin>>s;
	string t="";
	for(int i=0;s[i];i++)
	if(s[i]>='0'&&s[i]<='9') t+=s[i];
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	cout<<t<<"\n";
	return 0;
}
//8:37 pretset passed(4)