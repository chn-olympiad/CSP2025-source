#include<bits/stdc++.h>
using namespace std;
string s;
int d=0;
vector<int>q;
int main ()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
 	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0' )
		{
			q.push_back(s[i]-48);
			d++;
		}
		else continue;
	}
	sort(q.begin(),q.end()+1);
	for(int i=q.size();i>0;i--) cout<<q[i];
	return 0;
}
