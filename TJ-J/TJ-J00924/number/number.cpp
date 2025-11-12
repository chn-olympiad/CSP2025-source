#include<bits/stdc++.h>
using namespace std;
freopen("number.in",'r',stdin);
freopen("number.out",'w',stdout);

int main()
{
	
	string Str;
	
	int Num,FLAG=0;
	
	cin>>Str;
	Num=0;
	for(int i=0;i<Str.length();i++)
	{
		if(Str[i]>='0' && Str[i]<='9')
		{
			FLAG++;
		}	
	}
	char Chars[FLAG];
	for(int i=0;i<Str.length();i++)
	{	
		if(Str[i]<'a')
		{
			Chars[i]=int(Str[i]);
//			cout<<Chars[i]<<endl;
		}	
	}

//	int Num1=Chars.length();
	sort(Chars,Chars+FLAG);
	
	for(int i=0;i<FLAG;i++)
	{	
		
		cout<<Chars[FLAG-1-i];
			
	}
//	Flag--;
//	while(Num<Flag)
//	{
//		cout<<Chars[Flag];
//		Num++;
//	}
//	cout<<Chars[0]<<endl;
	return 0;
}
