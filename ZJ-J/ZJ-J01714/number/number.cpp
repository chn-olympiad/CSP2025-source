#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

int a[20];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]>='0'&&str[i]<='9')a[str[i]-'0']++;
    }
    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<a[i]; j++)
        {
            cout<<i;
        }
    }
    cout<<'\n';
    return 0;
}

