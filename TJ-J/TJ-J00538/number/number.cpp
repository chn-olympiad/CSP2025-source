#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a; 
vector<int> num;
int len=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=0;i<=a.size();i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{
			num.push_back(a[i]-'0');
			//cout<<a[i]-'0'<<endl;
			len++;
		}
	} 
	sort(num.begin(),num.end());
	for(int i=len-1;i>=0;i--)
	{
		cout<<num[i];
	}
	return 0;
 } 
