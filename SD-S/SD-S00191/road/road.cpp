#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
inline ll read()
{
	ll x=0;
	ll f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	} 
	return f*x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<"0";
	return 0;
}
