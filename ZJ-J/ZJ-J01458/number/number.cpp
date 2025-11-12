#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],j=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]-'0'>=0&&a[i]-'0'<=9)
		{
			j++;
			b[j]=a[i]-'0';
		}
	}
	sort(b+1,b+j+1);
	for(int i=j;i>=1;i--)
	cout<<b[i];
}
//#Shang4Shan3Ruo6Shui4
