#include<bits/stdc++.h>
using namespace std;
//just stdc++14.:)
//finished at 15:21(too long!!!)
//expected score: 100pts
typedef long long LL;
const int N = 1e5 + 10, M = 5;
int a[N][M];
int maxn[N];
int maxi[M];
int n;
LL ans;
struct Student
{
	int num;
	int maxd;
	
	Student() : num(0), maxd(0) {}
	Student(int x) : num(x)
	{
		int k[2], idx = 0;
		for(int j = 1; j <= 3; j ++)
			if(maxn[num] != j)
				k[idx ++] = j;
		maxd = a[num][maxn[num]] - max(a[num][k[0]], a[num][k[1]]);
	}
	bool operator < (const Student &w) const
	{
		return maxd > w.maxd;
	}
};
priority_queue<Student> q;

int main()
{
	//init the code
freopen("club.in", "r", stdin);
freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//much data
	int t;
	cin >> t;
	while(t --)
	{
		//init
		ans = 0ll;
		memset(maxi, 0, sizeof maxi);
		while(q.size()) q.pop();
		//input
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= 3; j ++)
				cin >> a[i][j];
			//analyze the data
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) maxi[1] ++, maxn[i] = 1;
			else if(a[i][2] > a[i][3]) maxi[2] ++, maxn[i] = 2;
			else maxi[3] ++, maxn[i] = 3;
			ans += a[i][maxn[i]];
		}
		//body
		int gate = n >> 1, upgatei = 0, delt;
		for(int i = 1; i <= 3; i ++)
			if(maxi[i] > gate) upgatei = i, delt = maxi[i] - gate;
		if(upgatei == 0)
		{
			//end(output in the special situation)
			cout << ans << "\n";
			continue;
		}
		for(int i = 1; i <= n; i ++)
			if(maxn[i] == upgatei)
				q.push(Student(i));
		while(delt --) ans -= q.top().maxd, q.pop();
		//output
		cout << ans << "\n";
	}
	
	return 0;
}
//rp++
