#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//#define I return
//#define love 0
//#define BJX ;
//#define afor(a, b) for(int i = a;i <= b;i++)
//#define bfor(a, b) for(int i = b;i > a;i++)
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int q = n * m;
	vector<int> g(q);
	for(int i = 1;i <= q;i++) cin >> g[i];
	int R = g[1];
	int s = 1;
	sort(g.begin(), g.end());
	
	for(int i = g.size();i > 0;i--) if(g[i] > R) s++;
	
	int r = s % n;
	int ans = 0, ans1 = 0;
	
	if(r == 0) ans = s / n;
	else ans = s / n + 1;
	
	int yu = ans % 2;
	
	if(yu == 1)
	{
		if(r == 0)
		{
			ans1 = n;
		}
		else
		{
			ans1 = r;
		}
	}
	else ans1 = (m + 1 - r) % m;
	
	//cout<<s;
	cout<<ans<<" "<<ans1<<'\n';
	
	fclose(stdin);
	fclose(stdout);
	
	//I love BJX
	return 0;
}
