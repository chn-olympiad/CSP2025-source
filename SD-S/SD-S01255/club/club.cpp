#include<bits/stdc++.h>
#define ll long long
#define inf INT_MAX
#define INF LLONG_MAX
#define lf double
#define ld long double

const int MAXN = 1e5+5;

using namespace std;

int belongs[MAXN];
int tb[3][MAXN];
pair<int, int> que[MAXN];

int main(){
	//auto bg = chrono::high_resolution_clock::now();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		fill(belongs+1, belongs+1+n, 1);
		
		priority_queue <pair<int,int>> Q3, Q2;
		for(int i = 1; i <= n; i++) {
			cin >> tb[0][i] >> tb[1][i] >> tb[2][i];
			Q2.push({tb[1][i] - tb[0][i], i});
			Q3.push({tb[2][i] - tb[0][i], i});
			que[i] = {tb[2][i] - tb[1][i], i}; 
			
		}
		pair<int, int> xx2 = Q2.top(), xx3 = Q3.top(); 
		int in1 = n, in2 = 0, in3 = 0;
		while((in1 > (n>>1) || xx2.first>0 || xx3.first>0) && in2 <= (n>>1)&& in3 <= (n>>1)) {
			if(xx2.second == -inf && xx3.second == -inf) break;
			int nxt;
			if(xx2.first>xx3.first) {
				nxt = xx2.second;
				Q2.pop();
				if(!Q2.empty())xx2 = Q2.top();
				else xx2 = {-inf, -inf};
				if(belongs[nxt] == 1 && in2 < (n>>1))
					belongs[nxt] = 2, in1--, in2++;
			} else {
				nxt = xx3.second;
				Q3.pop();
				if(!Q3.empty())xx3 = Q3.top();
				else xx3 = {-inf, -inf};
				if(belongs[nxt] == 1 && in3 < (n>>1))
					belongs[nxt] = 3, in1--, in3++;
			}
		}
		
		sort(que+1,que+n+1);
		
		int i = 1,j = n;
		while(true) {
			while(belongs[que[i].second] != 3 && i!=n)i++;
			while(belongs[que[j].second] != 2 && j!=1)j--;
			if(i==n||j==1) break;
			if(que[j].first-que[i].first>0 && (in3 == n/2 || in2 == n/2)) belongs[que[j].second] = 3, belongs[que[i].second] = 2;
			else if (in3 < n/2 && que[j].first > 0) belongs[que[j].second] = 3;
			else if (in2 < n/2 && que[i].first < 0) belongs[que[i].second] = 2;
			i++;
		}
		
		ll ans = 0;
		
		for(int i = 1; i <= n; i++){
			ans+= tb[belongs[i]-1][i];
		}
		cout << ans << '\n';	
	}
	//auto ed = chrono::high_resolution_clock::now();
	//auto dur = chrono::duration_cast<chrono::milliseconds>(ed-bg);
	//cout << dur.count()/1e3;
	
	
	
	return 0;

}

