#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n=0;int s[1000000];char c;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	for(int i=0;i<1000000;i++)
	{	c=getchar();
		if((c<'0'||c>'9')&&(c<'a'||c>'z')){break;
		}
		if(c<'0'||c>'9')
			{continue;
			}
		s[n]=c-'0';n++;
	}
	sort(s,s+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<s[i];
	}
	return 0;
}
