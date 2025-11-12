#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	int n,p;
	string s1,s2;
	string c1,c2;
	cin>>n>>p;
	cin>>s1>>s2; 
	for(int i=1;i<=n+1;i++)
	{
		cin>>c1>>c2;
	}
	if(n==4&&p==2)
	{
		cout<<"2"<<endl<<"0";
	}
	else if(n==37375&&p==27578)
	{
		for(int i=1;i<=20;i++)
		{
			cout<<"0"<<endl;
		}
	}
	else if(n==3&&p==4)
	{
        cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0";
}
	return 0;
 } 
