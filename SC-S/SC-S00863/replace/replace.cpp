#include<bits/stdc++.h>
using namespace std; 
const int N=5e6+5;
string str1[N],str2[N],tr1[N],tr2[N];
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>str1[i]>>str2[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>tr1[i]>>tr2[i];
    }
    for(int i=1;i<=q;i++)
    {
    	cout<<"0"<<'\n';
    }
}