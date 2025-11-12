#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,m;
struct Node
{
	int a,num;
}zw[200];
bool cmp(Node x,Node y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>zw[i].a;
		zw[i].num=i;
	}
	sort(zw+1,zw+n*m+1,cmp);
	int i=1,j=1;
	int cnt=1;
	int flag=1;
	while(zw[cnt].num!=1)
	{
		cnt++;
		if(i+flag<=n&&i+flag>=1)
		{
			i+=flag;
		}
		else
		{
			j++;
			if(flag==-1)
			{
				flag=1;
			}
			else
			{
				flag=-1;
			}
		}
	}
	cout<<j<<" "<<i<<endl;
	return 0;
}
/*
kaishiyuedu 8:57
kaishixie 9:04
jieshushijian 9:12
okok 11:26 wo you hui lai le
wan le yi jing wang ji ti mu shi sha le
11:31 ce le ji ge yang li dou shi dui de
zheng ti dai ma hao xiang si lu ye mei mao bing
wo liu le
T4 wo you lai le
*/