#include<iostream> 
#include<string>
using namespace std;
int main()
{/**/
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int cnt[10]={};
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			cnt[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(cnt[i]>0)
		{
			cout<<i;
			cnt[i]--;
		}
	}
	cout<<endl; 
	return 0;
}
