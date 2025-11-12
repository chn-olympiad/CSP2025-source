#include<bits/stdc++.h>
using namespace std;
string s;
char an[1000005];
bool cmy(char l,char c)
{
	return l>c;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
    for(int i=0;i<s.size();i++) an[i]=s[i];
	sort(an,an+n,cmy);
    for(int i=0;i<n;i++) if(an[i]>='0'&&an[i]<='9') cout<<an[i];
     return 0;
}