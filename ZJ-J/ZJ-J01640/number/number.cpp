#include<bits/stdc++.h>
using namespace std;
string st;
char c;
int a[30];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
//	cin>>st;
//	for(int i=0;i<st.size();i++)
//	  if(st[i]>='0'&&st[i]<='9')
//		a[st[i]-48]++;
	while(cin>>c)
	  if(c>='0'&&c<='9')
		a[c-48]++;
	for(int i=9;i>=0;i--)
	  while(a[i]--)
		cout<<i;
	return 0;
}
