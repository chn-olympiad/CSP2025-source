//SN-J00770 WANGZIHAN XIANSHIJIAODAFUZHONGCHANBAYOUANXUEXIAO
#include<bits/stdc++.h> 
using namespace std;
string b[1000];
int s;
int a[1000];
int main()
{	freopen("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i];
		for(int j=1;j<=s;j++){
			b[j]=a[j];
		}
		
	}
			for(int j=1;j<=s-1;j++)
			for(int i=2;i<=s;i++)
			{
				if(b[j]<b[i])
				b[i]=b[j];
				b[j]=b[j+1];
				cout<<b[j];
			}
		return 0;
	}
