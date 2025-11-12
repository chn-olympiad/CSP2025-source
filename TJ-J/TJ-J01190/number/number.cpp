#include <iostream>
#include <cmath>
using namespace std;
int s;
int main()
{
	freopen("number.in","r",strin);
    freopen("number.out","w",strout);
    cin>>s;
    if(s>=0||s<=9) 
	{
		cout<<s;
		return 0;
	}
	else if(s%10==0||s%11==0)
	{
		cout<<s;
		return 0;
	}
    return 0;
}
