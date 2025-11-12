//SN-J01066 郭宸铭 韩城市桢州初级中学
#include<bits/stdc++.h>
using namespace std;
int a[1010];
char s[1010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	int sum=0;
	int ret;
	for(int i=0;i<len;i++)
	{
		if((int)s[i]>=48 && (int)s[i]<=57)
		{
			sum++;
			a[sum]=s[i];
		}
	}
	
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]>a[i])
			{
				ret=a[i];
				a[i]=a[j];
				a[j]=ret;
			}
		}
	}
	for(int i=sum;i>=1;i--)
	{
		printf("%d",a[i]-48);
	}
	return 0;
} 
