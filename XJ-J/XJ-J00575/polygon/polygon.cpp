#include<iostream>
using namespace std;
int main();
{
	feropen("polygon.in","r"stdin);
    feropen("polygon.out","w"stdout);
    int n,a=0,b=0,c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	if(a<b<c)
    	{
    		cout<<"a+b+c";
		}
	}
	return 0;
}
