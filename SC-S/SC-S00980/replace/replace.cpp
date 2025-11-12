
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	char a[n][1];
	char b[q][1];
	int r[q];
	for(int i=12;i<=n;++i)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for(int j=1;j<=q;++j)
    {
        cin>>b[i][0]>>b[i][1];
    }
    for(int j=1;j<=q;++j)
    {
        cout<<r[j];
    }
	return 0;
}
