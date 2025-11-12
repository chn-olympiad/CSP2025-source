#include <bits/stdc++.h>
using namespace std;
const int N = 1E5+3;

int t,n;
int num[N][5],cho[N],rank[5],cal[N][5],sor[N];
long long sum,cnt;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		sum = 0;
		rank[1] = 0,rank[2] = 0,rank[3] = 0;
		for (int i = 1; i<= n; i++)
		{
			cin >> num[i][1] >> num[i][2] >> num[i][3];
			sum += num[i][1] + num[i][2] + num[i][3];
			cal[i][1] = num[i][2] + num[i][3];
			cal[i][2] = num[i][1] + num[i][3];
			cal[i][3] = num[i][1] + num[i][2];
			
			int k = max(num[i][1],max(num[i][2],num[i][3]));
			if (k == num[i][1]) cho[i] = 1,rank[1]++,sor[i] = min(num[i][1]-num[i][2],num[i][1]-num[i][3]);
			else if (k == num[i][2]) cho[i] = 2,rank[2]++,sor[i] = min(num[i][2]-num[i][1],num[i][2]-num[i][3]);
			else cho[i] = 3,rank[3]++,sor[i] = min(num[i][3]-num[i][2],num[i][3]-num[i][1]);
		}
		cnt = 0;
		for (int i = 1; i<= n; i++)	cnt += cal[i][cho[i]];
		int k = 0;
		for (int i = 1; i<= 3; i++) if (rank[i] > (n/2)) k = i;
		if (k != 0)
		{
			for (int i = 1; i<= n; i++) if (cho[i] != k) sor[i] = N;
			sort (sor+1, sor+n+1);
			for (int i = 1; i<= (rank[k] - (n/2)); i++) cnt += sor[i];
		}
		sum -= cnt;
		cout << sum << endl;
	}
	
	return 0;
}
