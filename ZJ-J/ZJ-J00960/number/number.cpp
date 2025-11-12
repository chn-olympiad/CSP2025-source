#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int main()
{
	fstream file=fstream("number.in",ios::in);
	fstream file2=fstream("number.out",ios::out);
	char n[1000005];
	file>>n;
	int i=0,num=0;
	while(n[i]!='\0')
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			x[num]=int(n[i]-'0');
			num++;
		}
		i++;
	}
	sort(x,x+num);
	bool flag=false;
	for(;num>=0;num--)
	{
		if(x[num]==0&&!flag)
		{
			continue;
		}
		if(x[num]!=0)
		{
			flag=true;
		}
		file2<<x[num];
	}
	if(!flag)
	{
		file2<<"0";
	}
	return 0;
}