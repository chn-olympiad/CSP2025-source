#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100005],n=0;
	cin >> s;
	//for (int i=1;i<=len(s);i++)
	//{
	//	if(s[i]==1 || s[i]==2 || s[i]==3 || s[i]==4 || s[i]==5 || s[i]==6 || s[i]==7 || s[i]==8 || s[i]==9 || s[i]==0)
    //    {
    //    	n++;
    //   	a[n]=s[i];
	// 	  }
	//}
	sort(a+1,a+n+1);
	int b[n];
	for (int i=n;i>=1;i--)
	{
		b[n-i]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		cout << b[i];
	}
	return 0;
} 
