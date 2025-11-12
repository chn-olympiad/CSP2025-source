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
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin >> T;
	
		cout << ans1 << '\n';
		//dfs

	
	
	
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
