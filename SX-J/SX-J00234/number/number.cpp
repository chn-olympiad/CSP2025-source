#include<bits/stdc++.h>
using namespace std;
string s,a;
int b[1050];
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int z=0,cnt=0;
    cin>>s;
    for(int i=0;i<=s.size();++i)
    {
    	if(s[i]>='0' && s[i]<='9')
    	{
            b[z]=s[i]-'0';
            z++;
            cnt++;
		}
	}
	z--;
    sort(b,b+cnt);
	for(int i=cnt-1;i>=0;--i)
	{
		cout<<b[i];
	}
	return 0;
}