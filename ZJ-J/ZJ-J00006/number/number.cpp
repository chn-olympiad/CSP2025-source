#include<bits/stdc++.h>
using namespace std;
string st;
int b[110];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	int len=st.size();
	for(int i=0;i<len;i++)
	  if(st[i]>='0'&&st[i]<='9') b[st[i]]++;
	for(char i='9';i>='0';i--)
	{
		int t=b[i];
		while(t--) printf("%c",i);
	}
	return 0;
}