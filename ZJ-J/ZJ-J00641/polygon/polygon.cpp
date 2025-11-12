#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N = 5500;
int a[N];
int n;
bool vis[N];
set<vector<int> > s;
void ptint(vector<int> &st){
	for(int i = 0;  i< st.size(); i++){
		cout << st[i] << ' ';
	}
	cout << '\n';
}
void dfs(int num,int sum,int mx,vector<int> st){
	if(st.size()>=3&&mx*2<sum){
		sort(st.begin(),st.end());
//		ptint(st);
		s.insert(st);
	}
	if(num>n) return ;
	st.push_back(num);
	dfs(num+1,sum+a[num],max(mx,a[num]),st);
	st.pop_back();
	dfs(num+1,sum,mx,st);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	vector<int> v;
	dfs(1,0,0,v);
	int ans=s.size()%MOD;
	cout << ans;
}

