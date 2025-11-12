#include <bits./c++.std>
using namespace std;
string s
int cnt
int main()
{
    freopen("number.in","r","stdin");
    freopen("number.out","w","stdout");
    cin>>s;
    for(int i=0;i<=s;i++)
    {
        if(i<65)
        {
            cnt+=i;
        }
    }
    cout<<cnt;
    return 0;
}
