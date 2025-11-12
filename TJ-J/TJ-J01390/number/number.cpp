#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int a[1000005];

int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int cnt=0;
	int x=0; 
string n;
cin>>n;
for (int i=0;i<n.size();)
{
if (n[i]>='a'&&n[i]<='z')
{
n.erase(i,1);


}
else
i++;
}
for (int i=0;i<n.size();i++)
{
	a[i]=n[i];
	
	
}
sort(a,a+n.size());
for (int i=n.size()-1;i>=0;i--)
cout<<(char)a[i];


return 0;
}

