#include <bits/stdc++.h>
using namespace std;
//freopen("employ.in","r",stdin);
//freopen("employ.out","w",stdout);
int main()
{
	int n,m,p,min,max,w;//w能录用的人数； 
	char c[505],s[505];//c标号为i的人耐心上限；s试题的难度 ;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=0)
		{
		i+=1;
		n--;

		}
		else{
		
			w+=i;
			n--;
		}
		if(w>=m)
		{
			p++;
		}
	}
	cout<<p%998||p%244&&p%353;
		return 0;
}
