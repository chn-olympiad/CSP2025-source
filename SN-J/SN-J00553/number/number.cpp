#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a_0=0,a_1=0,a_2=0,a_3=0,a_4=0,a_5=0,a_6=0,a_7=0,a_8=0,a_9=0;
    cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')   
		{
		    switch(s[i])
			{
				case '0': a_0++;  break;
		        case '1': a_1++;  break;
		        case '2': a_2++;  break;
		        case '3': a_3++;  break;
		        case '4': a_4++;  break;
	    	    case '5': a_5++;  break;
		        case '6': a_6++;  break;
		        case '7': a_7++;  break;
		        case '8': a_8++;  break;
		        case '9': a_9++;  break;
		    }
        }
	}
    for(int i=0;i<a_9;i++) cout<<9;
    for(int i=0;i<a_8;i++) cout<<8;
    for(int i=0;i<a_7;i++) cout<<7;
    for(int i=0;i<a_6;i++) cout<<6;
    for(int i=0;i<a_5;i++) cout<<5;
    for(int i=0;i<a_4;i++) cout<<4;
    for(int i=0;i<a_3;i++) cout<<3;
    for(int i=0;i<a_2;i++) cout<<2;
    for(int i=0;i<a_1;i++) cout<<1;
    for(int i=0;i<a_0;i++) cout<<0;
	return 0;
}
