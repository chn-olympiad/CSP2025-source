#include<bits/stdc++.h>

using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[n];
    for(int i=0;i<n;i++)
    {
		cin>>a[i];
	}
	int y=0;
	int p=0;
	int c=0;
	for(int i=0;i<n;i++)
    {
        if(c<=a[i])
        {
            if(s[i]==1)
            {
                y++;
                
            }
            if(s[i]==0)
            {
                p++;
            }
        }
        
        
    }
	return 0;
 }

