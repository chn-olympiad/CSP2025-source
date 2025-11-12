#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	string s;int idx=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			idx++;a[idx]=s[i]-'0';
		}
	}
	sort(a,a+idx+1);
	while(idx)
	{
		cout<<a[idx];  
		idx--;  
	}
	ios::sync_with_stdio(0);
	return 0;
}
