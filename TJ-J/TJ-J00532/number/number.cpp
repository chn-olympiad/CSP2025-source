#include<bits/stdc++.h>
using namespace std;
long long num9;
long long num8;
long long num7;
long long num6;
long long num5;
long long num4;
long long num3;
long long num2;
long long num1;
long long num0;
int main()
{
	//似乎只需要统计1~9的数量，在输出就行了 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		cin>>a[i];
		if(a[i]=='9')
			num9++;
		else if(a[i]=='8')
			num8++;
		else if(a[i]=='7')
			num7++;
		else if(a[i]=='6')
			num6++;
		else if(a[i]=='5')
			num5++;
		else if(a[i]=='4')
			num4++;
		else if(a[i]=='3')
			num3++;
		else if(a[i]=='2')
			num2++;
		else if(a[i]=='1')
			num1++;	
		else if(a[i]=='0')
			num0++;
	}
	for(int i=0;i<num9;i++)
		cout<<9;
	for(int i=0;i<num8;i++)
		cout<<8;
	for(int i=0;i<num7;i++)
		cout<<7;
	for(int i=0;i<num6;i++)
		cout<<6;
	for(int i=0;i<num5;i++)
		cout<<5;
	for(int i=0;i<num4;i++)
		cout<<4;
	for(int i=0;i<num3;i++)
		cout<<3;
	for(int i=0;i<num2;i++)
		cout<<2;
	for(int i=0;i<num1;i++)
		cout<<1;
	for(int i=0;i<num0;i++)
		cout<<0;	
	return 0;
}
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdin);
/*
哈喽啊，正在看迷惑行为大赏的你（或许你在做迷惑行为大赏）QWQ
首先恭喜你，你掉入陷阱辣 
赶紧去刷题吧孩子
不要像我一样，是个唐* QAQ
上考场啥也不会 
dp学会了吗，背包牢九门都会了吗，就看 
你不是要上清北的吗 
*/

