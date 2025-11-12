#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ci=0;
	for(int i=0;i<1000005;i++)
	{
		if(s[i]=='\0')
		{
			break;
		}
		if(s[i]>='1'&&s[i]<='9')
		{
			arr[ci]=s[i]-48;
			ci++;
		}
	} 
	sort(arr,arr+ci);
	for(int i=ci-1;i>=0;i--)
	{
		cout<<arr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
