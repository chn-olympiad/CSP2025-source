#include<iostream>
#include<string>
using namespace std;
string s;
char a[10000000];
int b[10000000];

int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i];
			j++;
		}
	}
	for(int i=0;i<j;i++)
	{
		int n=a[i]-48;
		b[i]=n;
	}
	for(int i=0;i<j-1;i++)
	{
		if(b[i]<b[i+1])
		{
			swap(b[i],b[i+1]);
		}
	}	
	int zero=0;
	for(int i=0;i<j;i++)
	{
		if(b[i]==0)
		{
			zero++;
		}
	}
	long long ans=0;
	for(int i=0;i<j-zero;i++)
	{
		if(b[i]==0)
		{
			ans=ans*10;
		}
		else
		{
		 for(int z=i+1;z<j-zero;z++)
		 {
		 	b[i]=b[i]*10;
		 }
	    }
		ans+=b[i];
	}
	for(int i=1;i<=zero;i++)
	{
		ans=ans*10;
	}
	cout<<ans;		
	return 0;
}