#include<bits/stdc++.h>
using namespace std;
string a;
int x[1000005]={0};
int cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int i,ans=0;	
		for(i=0;i<a.size();i++)
		{

			if((int)a[i]==48||(int)a[i]==49||(int)a[i]==50||(int)a[i]==51||(int)a[i]==52||(int)a[i]==53||(int)a[i]==54||(int)a[i]==55||(int)a[i]==56||(int)a[i]==57) 
			{
				x[i]=a[i]-48;
				ans++;
			}
		}
	sort(x,x+i,cmp);
	for(int aa=0;aa<ans;aa++)
	{
		cout << x[aa];
	}
	return 0;
}


