#include<bits/stdc++.h>
using namespace std;
int n[1000001];
int sum;

int cheng(int a,int b)//算乘方
{
	if(b>=1)
	{
		for(int i=1;i<=b;i++)
		{
			a*=a;
		}
		return a;
	}else
	{
		return 1;
	}
}

int max(int a,int b)//比较最大值
{
    if(a>=b)
    {
        return a;
    }else
    {
        return b;
    }
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int a=s.length();//字符串长度
    for(int i=0;i<=a;i++)
    {
        if((s[i]>='0') && (s[i]<='9'))
        {
            n[i]=s[i];//求数字
        }
    }

    sort(n,n+1);

 	for(int i=a;i>=0;i--)
 	{
 		if(n[i]==0)
 		{
 			continue;
		 }
 		cout<<n[i];
	 }

    return 0;
}
