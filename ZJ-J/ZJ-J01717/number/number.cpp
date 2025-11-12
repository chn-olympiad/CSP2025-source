#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	int len=s.size();
	int cnt=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[cnt++]=s[i]-48;
	}
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--)
		cout<<a[i];
	return 0;
}
