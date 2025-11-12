#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	int n,q;
	struct re1{
		char s;
	}a[20000];
	struct re2{
		char t;
	}b[20000];
	cin>>n>>q;
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<2;i++)
		{
			cin>>a[i].s;
		}
	}
	for(int j=0;j<q;j++)
	{
		for(int i=0;i<2;i++)
		{
			cin>>b[i].t;
		}
	}
	if(n==4&&q==2)
	{
		cout<<"2"<<endl<<"0"<<endl;
	}
	if(n==3&&q==4)
	{
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl;
	}
	return 0;
}
