#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr1[100001];
int arr2[100001];
int arr3[100001];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    for(int T = 1; T <= t; T++)
    {
    	int n;
        cin >> n;
        bool flag_1=true;
        bool flag_2=true;
        bool flag_3=true;
        for (int i = 1; i <= n; i++)
        {
        	cin >> arr1[i];
        	cin >> arr2[i];
        	cin >> arr3[i];
        	if(arr1[i] != 0)
			{
				flag_2 = flag_3 = false;
			}
        	if (arr2[i] != 0)
        	{
        		flag_1= flag_3 = false;
			}
			if(arr3[i] != 0)
			{
				flag_1 = flag_2 =false;
			}
		}

        //1
        if (n == 2)
        {
            int ans = 0;
            ans = max(arr1[1]+arr2[2], ans);
            ans = max(arr1[1]+arr3[2], ans);
            ans = max(arr2[1]+arr1[2], ans);
            ans = max(arr2[1]+arr2[2], ans);
            ans = max(arr3[1]+arr1[2], ans);
            ans = max(arr3[1]+arr2[2], ans);
            cout << ans << endl;
            continue;
        }
        
        //12
		if(flag_1)
		{
			int temp[100001];
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				temp[i] = arr1[i];
			}
			
			for (int i = 1; i <= n/2; i++)
			{
				int maxs = 0;
				int pos = 0;
				for(int j = 1; j <= n; j++)
				{
					maxs = max(maxs, temp[j]);
					pos = i;
				}
				temp[pos] = 0;
				ans += maxs;
			}
			cout << ans << endl;
			continue;
		}
		if(flag_2)
		{
			int temp[100001];
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				temp[i] = arr2[i];
			}
			
			for (int i = 1; i <= n/2; i++)
			{
				int maxs = 0;
				int pos = 0;
				for(int j = 1; j <= n; j++)
				{
					maxs = max(maxs, temp[j]);
					pos = i;
				}
				temp[pos] = 0;
				ans += maxs;
			}
			cout << ans << endl;
			continue;
		}
		if(flag_3)
		{
			int temp[100001];
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				temp[i] = arr3[i];
			}
			
			for (int i = 1; i <= n/2; i++)
			{
				int maxs = 0;
				int pos = 0;
				for(int j = 1; j <= n; j++)
				{
					maxs = max(maxs, temp[j]);
					pos = i;
				}
				temp[pos] = 0;
				ans += maxs;
			}
			cout << ans << endl;
			continue;
		}
		
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
        	ans += max(arr1[i], max(arr2[i], arr3[i]));
		}
		cout << ans << endl;
    }
    return 0;
}
