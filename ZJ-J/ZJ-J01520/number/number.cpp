#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>vec;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')vec.push_back('0'-s[i]);
	sort(vec.begin(),vec.end());
	for(int i:vec)cout<<-i;
	cout<<"\n";
	return 0;
}
//CSP RP++
