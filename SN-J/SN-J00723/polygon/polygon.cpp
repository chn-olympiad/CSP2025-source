#include<bits/stdc++.h>
using namespace std;
int main{
    //reopen("polygon.in","r"stdin);
    //reopen("polygon.out","w"stdout);
	int c,r;
	cin>>c>>r;
	for(int i=0;i<=c+r;i++){
		int a;
		cin>>a;
		if(a<=100)
		{
			cout<<c<<" "<<r<<endl;
		}
		else
		{
			cout <<a<<endl;
		}
		for(int f=0;f<=r;f++)
		{
			if(f>0)
			{
				cout<<f<<endl;
			}
		}
	}
	cout<<
return 0
}
