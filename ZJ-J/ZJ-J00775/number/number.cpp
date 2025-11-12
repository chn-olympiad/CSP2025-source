/*
StarLight_Yuran_ovo
ha ro ni ha 2 do 1 wo da shi te
ad astra per aspera
JROI 2023~无限
Starlight OI 2024~无限
RP++
648647291436
*/
#include<bits/stdc++.h>
using namespace std;
string s;
int a[114];
string t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[int(s[i]-'0')]++;
		}
	}
	for(char i=0;i<=9;i++)
	{
		while(a[i]>0)
		{
			a[i]--;
			t=char(i+'0')+t;
		}
	}
	if(t[0]=='0')
	{
		cout<<0;
	}
	else
	{
		cout<<t;
	}
	return 0;
}
