#include<bits/stdc++.h>
using namespace std;
string s;
long long len,x;
int f[20];
void youhua(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main(){
	youhua();
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x=int(s[i]-48);
			f[x]++;
		}
	 } 
	for(int i=9;i>=0;i--)
		for(int j=1;j<=f[i];j++)
			cout<<i;
	return 0;
}
//全部都过了
//rp++ 
