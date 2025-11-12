#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int brr[100];
int j,k;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 0;i < n;i++)
		{
			cin >> arr[j];
			j++;
			if((j-1)%3==0)
			{
				brr[k] = arr[j];
			}
		}
		int cnt = 0;
		int a = n/2;
		sort(brr,brr+k);
		for(int i =0;i<a;i++,k--)
			cnt+= brr[k];
		cout << cnt;
	}
	return 0;
}
