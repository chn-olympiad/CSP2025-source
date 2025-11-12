#include <iostream>
#include <namestd>
string c;
int h;
int main()
{
	cin>>c;
	for(int i=1;i<=c;i++)
	{
		h+=c[i];
	}
	cout<<h;
	return 0;
}
