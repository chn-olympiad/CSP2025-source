#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool mp[10005];
pair<int ,long long> tmp_sp;
struct node1{
	int prev;
	int in = 0,out = 0;
	bool is_p;
	vector<pair<int,long long>>to;
}a[10050];
struct node2{
	long long val1;
	long long val2[10050];
	bool st = false;
}b[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int x,y;
	long long v;
	for(int i = 1;i <= m;i++){
		cin >> x >> y >> v;
		a[x].in++;a[x].out++;
		a[y].in++;a[y].out++;
		a[x].to.push_back(make_pair(y,v));
		a[y].to.push_back(make_pair(x,v));
	}
	bool flag = true;
	for(int i = 1;i <= k;i++){
		cin >> b[i].val1;
		if(b[i].val1)flag = 0;
		for(int j = 1;j <= n;j++){
			cin >> b[i].val2[j];
			if(b[i].val2)flag = 0;
		}
	}
	if(flag)cout << 0;
	int start = 1;
	for(int i = 2;i <= n;i++){
		if(a[i].in < a[start].in)start = i;
	}
	long long ans = 0;
	int tmp_n = n;
	for(int ab = 1;ab < n;ab++){
		if(start == -1)break;
		mp[start] = 1;
		tmp_sp.first = -1;
		tmp_sp.second = 0xffffffff;
		bool is_open;
		int open_city;
		for(int i = 0;i < a[start].to.size();i++){
			if(a[start].to[i].first == -1)continue;
			if(a[start].to[i].second < tmp_sp.second){
				tmp_sp.second = a[start].to[i].second;
				is_open = false;
				tmp_sp.first = a[start].to[i].first;
			}
		}
		for(int i = 1;i <= k;i++){  
			for(int j = 1;j <= n;j++){
				if(mp[j])continue;
				long long country_spend = b[i].val2[start] + b[i].val2[j];
				if(!b[i].st)country_spend += b[i].val1;
				if(country_spend < tmp_sp.second){
					tmp_sp.second = country_spend;
					tmp_sp.first = j;
					is_open = true;
					open_city = i;
				}
			}
		}
		if(tmp_sp.second != 0xffffffff)
			ans += tmp_sp.second;
		if(is_open){
			b[open_city].st = true;
		}
		for(int i = 0;i < a[start].to.size();i++){
			for(int j = 0;j < a[a[start].to[i].first].to.size();j++){
				if(a[a[start].to[i].first].to[j].first == start){
					a[a[start].to[i].first].to[j].first = -1;
					break;
				}
			}
			a[start].to[i].first = -1;
		}
		start = tmp_sp.first;
	}
	cout << ans;
	return 0;
}