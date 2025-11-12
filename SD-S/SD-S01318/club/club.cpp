#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
using piii = pair<int,pair<int,int>>;
bool vis[N];
int cnt[5];
int ccnt;
int n;

namespace brute
{
	void mmain(priority_queue<piii,vector<piii>,less<piii>> q1)
	{
		ccnt = 0;
		int c = 0;
		ll ans = 0;
		while(!q1.empty())
		{
			ans+=q1.top().first;
			q1.pop();
			c ++;
			if(c == n)
			{
				cout << ans << "\n";
				return;
			}
		}
	}
}

ll solve1(priority_queue<piii,vector<piii>,less<piii>> q1,priority_queue<piii,vector<piii>,less<piii>> q2,priority_queue<piii,vector<piii>,less<piii>> q3)
{
	ccnt = 0;
	ll ans = 0;
	for(int i = 1;i<=n;i++)
	{
		vis[i] = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
	}
	while((!q1.empty())||(!q2.empty())||(!q3.empty()))
	{
		pair<int,pair<int,int>> it1 = {-1,{-1,-1}},it2 = {-1,{-1,-1}},it3 = {-1,{-1,-1}};
		while(!q1.empty())
		{
			it1 = q1.top();
			if(vis[it1.second.second]) q1.pop();
			else break;
		}
		while(!q2.empty())
		{
			it2 = q2.top();
			if(vis[it2.second.second]) q2.pop();
			else break;
		}
		while(!q3.empty())
		{
			it3 = q3.top();
			if(vis[it3.second.second]) q3.pop();
			else break;
		}
		//cout << 111 <<endl; 
		pair<int,pair<int,int>> x = max({it1,it2,it3});
		//cout << x.first << "::" << x.second<<endl;
		//return ;
		if(cnt[x.second.first] >= n/2)
		{
			//cout<<x.first<<"!!"<<x.second.first<<endl;
			if(x == it1) while(!q1.empty()) q1.pop();
			else if(x == it2) while(!q2.empty()) q2.pop();
			else if(x == it3) while(!q3.empty()) q3.pop();
			continue;
		}
		//cout << 111 << endl;
		//cout<<x.first<<"::"<<x.second.second<<endl;
		vis[x.second.second] = true;
		cnt[x.second.first] ++;
		ccnt++;
		ans += x.first;
		if(ccnt == n) break;
	}
	return ans;
}

ll solve2(priority_queue<piii,vector<piii>,greater<piii>> q1,priority_queue<piii,vector<piii>,greater<piii>> q2,priority_queue<piii,vector<piii>,greater<piii>> q3)
{
	ccnt = 0;
	ll ans = 0;
	for(int i = 1;i<=n;i++)
	{
		vis[i] = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
	}
	while((!q1.empty())||(!q2.empty())||(!q3.empty()))
	{
		pair<int,pair<int,int>> it1 = {-1,{-1,-1}},it2 = {-1,{-1,-1}},it3 = {-1,{-1,-1}};
		while(!q1.empty())
		{
			it1 = q1.top();
			if(vis[it1.second.second]) q1.pop();
			else break;
		}
		while(!q2.empty())
		{
			it2 = q2.top();
			if(vis[it2.second.second]) q2.pop();
			else break;
		}
		while(!q3.empty())
		{
			it3 = q3.top();
			if(vis[it3.second.second]) q3.pop();
			else break;
		}
		//cout << 111 <<endl; 
		pair<int,pair<int,int>> x = max({it1,it2,it3});
		//cout << x.first << "::" << x.second<<endl;
		//return ;
		if(cnt[x.second.first] >= n/2)
		{
			//cout<<x.first<<"!!"<<x.second.first<<endl;
			if(x == it1) while(!q1.empty()) q1.pop();
			else if(x == it2) while(!q2.empty()) q2.pop();
			else if(x == it3) while(!q3.empty()) q3.pop();
			continue;
		}
		//cout << 111 << endl;
		//cout<<x.first<<"::"<<x.second.second<<endl;
		vis[x.second.second] = true;
		cnt[x.second.first] ++;
		ccnt++;
		ans += x.first;
		if(ccnt == n) break;
	}
	return ans;
}

void sol()
{
	bool bru = 1;
	ll ans = 0;
	cin >> n;
	priority_queue<piii,vector<piii>,less<piii>> q1,q2,q3;
	priority_queue<piii,vector<piii>,greater<piii>> qq1,qq2,qq3;
	for(int i = 1;i<=n;i++)
	{
		vis[i] = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		int a,b,c;
		cin >> a >> b >> c;
		if(b != 0 || c != 0) bru = 0;
		q1.push({a,{1,i}});
		q2.push({b,{2,i}});
		q3.push({c,{3,i}});
		qq1.push({a,{1,i}});
		qq2.push({b,{2,i}});
		qq3.push({c,{3,i}});
	}
	if(bru){
		brute::mmain(q1);
		return ;
	}
	ll ans1 = solve1(q1,q2,q3);
	ll ans2 = solve2(qq1,qq2,qq3);
	cout << max(ans1,ans2) << "\n"; 
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		sol();
	}
	return 0;
}

/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
