#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cur=0,p[15];
bool flag=0,p1[15]; 
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    p1[0]=0;
	p1[1]=0;
	p1[2]=0;
	p1[3]=0;
	p1[4]=0;
	p1[5]=0;
	p1[6]=0;
	p1[7]=0;
	p1[8]=0;
	p1[9]=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            a[++cur]=0;
            p[0]++;
            p1[0]=1;
        }
        else if(s[i]=='1')
        {
            a[++cur]=1;
            p[1]++;
            p1[1]=1;
        }
        else if(s[i]=='2')
        {
            a[++cur]=2;
            p[2]++;
            p1[2]=1;
        }
        else if(s[i]=='3')
        {
            a[++cur]=3;
            p[3]++;
            p1[3]=1;
        }
        else if(s[i]=='4')
        {
            a[++cur]=4;
            p[4]++;
            p1[4]=1;
        }
        else if(s[i]=='5')
        {
            a[++cur]=5;
            p[5]++;
            p1[5]=1;
        }
        else if(s[i]=='6')
        {
            a[++cur]=6; 
            p[6]++;
            p1[6]=1;
        }
        else if(s[i]=='7')
        {
            a[++cur]=7;
            p[7]++;
            p1[7]=1;
        }
        else if(s[i]=='8')
        {
            a[++cur]=8;
            p[8]++;
            p1[8]=1;
        }
        else if(s[i]=='9')
        {
            a[++cur]=9;
            p[9]++;
            p1[9]=1;
        }
    }
	if(p1[9]==1)
 	{
    	for(int i=1;i<=p[9];i++)
		{
			cout<<"9";
		}
	}
	if(p1[8]==1)
    {
    	for(int i=1;i<=p[8];i++)
		{ 
			cout<<"8";
		}
	}
	if(p1[7]==1)
    {
    	for(int i=1;i<=p[7];i++)
		{
			cout<<"7";
		}
	}
	if(p1[6]==1)
    {
   		for(int i=1;i<=p[6];i++)
		{
			cout<<"6";
		}
	}
	if(p1[5]==1)
  	{
   		for(int i=1;i<=p[5];i++)
		{
			cout<<"5";
		}
	}
	if(p1[4]==1)
    {
    	for(int i=1;i<=p[4];i++)
		{
			cout<<"4";
		}
	}
	if(p1[3]==1)
   	{
   		for(int i=1;i<=p[3];i++)
		{
			cout<<"3";
		}
	}
	if(p1[2]==1)
   	{
   		for(int i=1;i<=p[2];i++)
		{
			cout<<"2";
		}
	}
	if(p1[1]==1)
   	{
   		for(int i=1;i<=p[1];i++)
		{
			cout<<"1";
		}
	}
	if(p1[0]==1)
   	{
   		for(int i=1;i<=p[0];i++)
		{
			cout<<"0";
		}
	}
    return 0;
}
