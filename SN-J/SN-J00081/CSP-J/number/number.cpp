#include<iostream>
#include<string>
using namespace std;

int main()
{
   	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=1;i<=s.length();i++)
    {
    	if(s[i]<s[i+1])
    	  swap(s[i],s[i+1]);
    	
	}
    cout<<s;
	return 0; 
}
