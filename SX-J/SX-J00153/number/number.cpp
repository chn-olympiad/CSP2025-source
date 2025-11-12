#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000086],lk;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')	arr[++lk]=s[i]-'0';
	sort(arr+1,arr+lk+1);
	while(!arr[lk]&&lk>1)	lk--;
	for(int i=lk;i>=1;i--)	cout<<arr[i];
	return 0;
}