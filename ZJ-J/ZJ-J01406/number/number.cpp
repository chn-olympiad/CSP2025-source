#include<bits/stdc++.h>
using namespace std;
string r;
int a[1000055],s=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>r;
	for(int i=0;i<r.size();i++)
	{
		if(r[i]>='0' && r[i]<='9')a[++s]=r[i]-'0';
	}
	sort(a+1,a+s+1,cmp);
	for(int i=0;i<r.size();i++)
	{
		cout<<a[i];
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4
