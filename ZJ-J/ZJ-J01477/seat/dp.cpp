#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","w",stdout);
	cout<<10<<" "<<9<<endl;
	for(int i=1;i<=9;i++)
	  for(int j=1;j<=9;j++)
	    cout<<(i-1)*9+j<<" ";
	return 0;
}
