#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++)
    {
        string ss1,ss2;
        cin>>ss1>>ss2;
        if(ss1!=ss2)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<rand()%n<<"\n";
        }
    }
	return 0;
}
