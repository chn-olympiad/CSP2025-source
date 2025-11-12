#include<bits/stdc++.h>
using namespace std;
string a[1000005];
string a2[1000005];
int j=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;

    cin>>s;
    cout<<s<<endl;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<'a')
        {
            a[j]=int(s[i]);
            j++;
        }

    }
    sort(a,a+j);

    for(int i=j-1;i>=0;i--)
	{
		cout<<string(a[i]);


	}

    return 0;
}
