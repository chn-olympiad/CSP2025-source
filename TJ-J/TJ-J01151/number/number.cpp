#include<bits/stdc++.h>
using namespace std;
char line[1000000];
int a[100000];
int b[100000];
int cnt=1,sum=1,ma;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m;
	cin>>m;
	cout<<m;
	/*
	for(int i=1;i<=100000;i++)
	{
		cin>>line[i];
		if(line[i]==' ')
		{
			break;
		}
		sum++;
	}
	for(int i=1;i<=sum;i++)
	{
		cout<<line[i];
	}
	*/
	/*
		for(int i=1;i<=sum;i++)
		{
			switch(line[i])
			{
				case'1': a[cnt]=1;cnt++;break;
				case'2': a[cnt]=2;cnt++;break;
				case'3': a[cnt]=3;cnt++;break;
				case'4': a[cnt]=4;cnt++;break;
				case'5': a[cnt]=5;cnt++;break;
				case'6': a[cnt]=6;cnt++;break;
				case'7': a[cnt]=7;cnt++;break;
				case'8': a[cnt]=8;cnt++;break;
				case'9': a[cnt]=9;cnt++;break;
				case'0': a[cnt]=0;cnt++;break;
			}
			/*
			if(line[i]=='1')
			{
				a[cnt]+=1;
				cnt++;
				continue;
			}
			else if(line[i]=='2')
			{
				a[cnt]+=2;
				cnt++;
				continue;
			}
			else if(line[i]=='3')
			{
				a[cnt]+=3;
				cnt++;
				continue;
			}
			else if(line[i]=='4')
			{
				a[cnt]+=4;
				cnt++;
				continue;
			}
			else if(line[i]=='5')
			{
				a[cnt]+=5;
				cnt++;
				continue;
			}
			else if(line[i]=='6')
			{
				a[cnt]+=6;
				cnt++;
				continue;
			}
			else if(line[i]=='7')
			{
				a[cnt]+=7;
				cnt++;
				continue;
			}
			else if(line[i]=='8')
			{
				a[cnt]+=8;
				cnt++;
				continue;
			}
			else if(line[i]=='9')
			{
				a[cnt]+=9;
				cnt++;
				continue;
			}
			else if(line[i]=='0')
			{
				a[cnt]+=0;
				cnt++;
				continue;
			}
		}
		
	}
	
	//for(int i=1;i<=cnt-1;i++)
	//{
	//	ma=max(a[i],a[i+1]);
	//}
	//b[1]=ma;
	for(int q=1;q<=cnt;q++)
	{
		cout<<a[q]<<' ';
	}
	cout<<2;
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
