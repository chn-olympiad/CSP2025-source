#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	for(int i=0;i<b.size();i++)
	if(b[i]>='0'&&b[i]<='9')
	{
		int l=(int)(b[i]-'0');
		a[l]++; 
	}
	if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0)
	{
		cout<<0;
		fclose(stdin);
	    fclose(stdout);
    	return 0;
	}
	for(int i=9;i>=0;i--)
	for(int j=1;j<=a[i];j++)
	cout<<i;
    fclose(stdin);
	fclose(stdout);
	return 0;
 } 
