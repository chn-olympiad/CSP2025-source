#include<bits/stdc++.h.>
using namespace std;
int n,m,a[100005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			m++;
			a[m]=(s[i]-'0');
		}
	}
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i--)
	cout<<a[i];
	return 0;
}