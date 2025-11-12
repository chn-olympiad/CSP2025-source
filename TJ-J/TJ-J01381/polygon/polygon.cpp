#include <bits/stdc++.h>
using namespace std;

int mg[5005];

int maindtd(int n)
{
    int zs,maxx;
	long long out = 0;
    
	for (int i = 0;i < n;i++)
	{
		for (int l = 0;i + l < n;l++)
		{
			zs = 0;
			maxx = 0;
			
			for (int p = i;p <= i + l;p++)
			{
				zs += mg[p];
				maxx = max(maxx,mg[p]);
				//cout << zs << " " << p + 1 << " " << maxx << "#";
			}
			//cout << endl;
			
			if (zs > maxx * 2)
			{
				out++;
				//cout << "out++ now" << out << endl;
			}
			
			if (out >= 998244353)
			{
				out -= 998244353;
				//cout << "outc" << out << endl;
			}
		}
		
	}
	
    return out;
}

int main()
{
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >> n;
	
	for(int i = 0;i < n;i++)
	{
		cin >> mg[i];
    }  
    
    cout << maindtd(n);
    return 0;
    
    
    
    return 0; 
} 
