//刘家豪  SN-S00052 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
bool a(int k)
{
   if(k==1)
   {
   	 return true;
   }
   else
   {
   	 k=k*a(k-1);
   }
}
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m,k,f,b;
	cin >> n,m;
	k=a(m);
	f=a(n);
	b=k/f;
	cout << b;
	return 0;
}
