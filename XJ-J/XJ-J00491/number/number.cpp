#include<bits/stdc++.h> 
using namespace std;
char s[1000005];
long long int a[100005];
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	long long int i,j,m=0,n=0,k=0;
	cin>>s;
	for(i=0;i<strlen(s);i++)
	if(s[i]<='9'&&s[i]>='0')
	{
		m++;
	    a[++k]=s[i]-'0';
    }
	sort(a+1,a+1+k,greater<long long int>());
	
	for(i=1;i<=k,m!=0;i++)
	{
		m--;
		n+=a[i]*pow(10,m);
		
	}
	cout<<n;
	return 0;
}
