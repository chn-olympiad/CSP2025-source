#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool kused[500005];
bool used[500005];
int n, k, cnt;
int main()
{
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	//优先使用a[i]==k的[i,i]点区间，并标记 
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == k)
		{
			kused[i] = true;
			used[i] = true;
			cnt++;
		}
	}
	int l = 1;
	while(l < n)
	{
		if(used[l])	l++;
			
			//cout << "start=" << l << '\n';
			int num = 0, r;
			for(r = l ; !used[r] && r <= n; r++)
			{	
				num = num ^ a[r];//累计异或和 
				used[r] = true;//标记使用 
				if(num == k)
				{
					//cout << "合法区间[" << l << ","<< r << "]\n";
					//移动l下标到r+1 
					l = r + 1;
					cnt++;
					break;
				} 
			}
			//cout << "end=" << r << '\n';
			if(num != k)//不相等 回溯  撤销标记 
			{
				for(int i = l; i <= r; i++)
				{
					if(kused[i])
						continue;
					used[i] = false;
				}	
				l++; 
			}
	}
	cout << cnt;
	return 0;
} 
