#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[t]={0};
	int i[t][3]={0};
	int j[t]={0};
	int a[t]={0};
	for(int k=0;k<t;++k)
    {
        cin>>n[k];
        for(int l=0;l<n[k];++l)
        {
            cin>>i[k][0]>>i[k][1]>>i[k][2];
            a[k]+=max(i[k][0],max(i[k][1],i[k][2]));
        }
    }
    for(int k=0;k<t;++k)
    {
        cout<<a[k]<<endl;
    }
	return 0;
}
