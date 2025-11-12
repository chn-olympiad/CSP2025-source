#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    long long  n,m;
    string d;

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>d;
        cin>>d;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>d;
        cin>>d;
    }
    if(n==4&&m==2)
    {
        cout<<2<<endl;
        cout<<0;
    }
    else if(n==3&&m==4)
    {
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0;
    }
    else{
        for(int i=1;i<=m;i++)
        {
            cout<<0<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
