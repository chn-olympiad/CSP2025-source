#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
//typedef pair<int,int> PII;
typedef long long LL;
const int N = 100010;
struct Node{
	int v;//value
	int u;//people
	int c;//第几个活动 
	bool operator<(const Node& T) const
	{
		return v > T.v;
	}
};
int n;
//int w[N][4];
int cnt[4];
bool st1[N];//某人是否已参与活动 
//
int a[4];//dfs
LL ans1,ans2;

int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin >> T;
	
	while(T--)
	{
		cin >> n;
		int x,y,z;
		
		vector<Node> p;//tan xin

		
		ans1 = 0;
		ans2 = 0;
		memset(st1,0x0,sizeof st1);
		memset(cnt,0x0,sizeof cnt);
		
		for(int i = 1; i <= n; i ++)
		{
			cin >> x >> y >> z;

//			w[i][1] = x;
//			w[i][2] = y;
//			w[i][3] = z;
			
			p.push_back({x,i,1});
			p.push_back({y,i,2});
			p.push_back({z,i,3});
		}
		 
		sort(p.begin(),p.end());//from bit to small

		  
		for(int i = 0,tot = 0; i < p.size();i ++)//tan value
		{
			Node & t = p[i];
			int v = t.v, u = t.u, c = t.c;//c is activity no
			
			if(!st1[u] && cnt[c] < n / 2)
			{
				ans1 += v;
				st1[u] = true;
				cnt[c] ++;
				
				tot ++;
			}
			if(tot >= n) break;
		}
		
		cout << ans1 << '\n';
		//dfs

	}
	
	
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
