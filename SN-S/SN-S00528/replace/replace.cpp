#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,q;

vector<int> kmp[N];//next

string a[N],b[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
    cin.tie(0)->sync_with_stdio(0);

    cin>>n>>q;

    for(int t=1;t<=n;++t)
    {
        cin>>a[t]>>b[t];

        a[t]=" "+a[t];
        b[t]=" "+b[t];
        
        kmp[t].resize(a[t].size()+1);

        for(int i=2,j=0;i<a[t].size();++i)
        {
            while(j && a[t][i] != a[t][j+1]) j=kmp[t][j];

            if(a[t][i] == a[t][j+1]) ++j;

            kmp[t][i]=j;
        }
    }

    for(int t=1;t<=q;++t)
    {
    	string x,y;
    	cin>>x>>y;
    	
    	if(x.size() != y.size())
    	{
    		cout<<0<<endl;
    		continue;
		}
			
		int ans=0;
    	
    	x=" "+x,y=" "+y;
    	for(int k=1;k<=n;++k)
    	{
    		for(int i=1,j=0;i<x.size();++i)
    		{
    			while(j && x[i] != a[k][j+1]) j=kmp[k][j];
    			
    			if(x[i] == a[k][j+1]) ++j;
    			
    			if(j==a[k].size()-1)
    			{
					string xx=x;
    				for(int l=i-j+1,r=1;l<=i;++l,++r)
    					xx[l]=b[k][r];
					
					if(xx==y)
						++ans;
					
					j=kmp[k][j];
				}
			}
		}
		
		cout<<ans<<endl;	
	}
	
    return 0;
}
