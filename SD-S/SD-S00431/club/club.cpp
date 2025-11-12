#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


const int N = 1e5 + 10;
typedef pair<int, int> PII;
typedef long long LL;

int T;
int n;



bool cmp(PII a, PII b)
{
	return a.first > b.first;
}


struct AC{
	PII a[4];
	int dx;
	
	void init()
	{
		sort(a + 1, a + 4, cmp);
		dx = a[2].first - a[1].first;
	}
	bool operator < (const AC &b) const{
		return dx < b.dx;
	}

}s[N];


bool cmmp (AC x, AC y){
	return x.dx > y.dx;
}



void solve() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> s[i].a[1].first >> s[i].a[2].first >> s[i].a[3].first;
		
		s[i].a[1].second = 1;s[i].a[2].second = 2;s[i].a[3].second = 3;
		
		s[i].init();
	}
	
	sort(s + 1, s + n + 1, cmmp);
	int cnt[4] = {0, 0, 0, 0}, t = 0;
	for(int i = 1; i <= n; i++)
	{
		int b = s[i].a[1].second;
		cnt[b]++;
		if(cnt[b] == n / 2) 
		{
			t = b;
			break;
		}
	}
	
	priority_queue<AC> qu;
	
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int aa = s[i].a[1].first, b = s[i].a[1].second;
		if(b == t)
		{
			if(qu.size() < (n / 2))
			{
				ans = ans + aa;
				qu.push(s[i]);
			}
			else
			{
				AC p = qu.top();
				if(aa + p.dx > 0)
				{
					qu.pop();
					qu.push(s[i]);
					ans =  ans + p.dx + aa;
				}
				else
				{
					ans = ans + s[i].a[2].first;
				}
			}
		}
		else
		{
			ans = ans + aa;
		} 
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}

