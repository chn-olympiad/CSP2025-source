#include <bits/stdc++.h>
#define _loopc(i, a, b) for(int i = (a); i <= (b); i ++)
#define _loopo(i, a, b) for(int i = (a); i <  (b); i ++)
#define _rloopc(i, a, b) for(int i = (a); i >= (b); i --)
#define _rloopo(i, a, b) for(int i = (a); i >  (b); i --)
using namespace std;

void solve(){
	int n; cin >> n; // 共招收 n 个新成员(n mod 2 == 0)。
	//	共有三个部门，第 i 个新成员对第 j 个部门的满意度为 Ai,j
	vector<pair<int, int> > A[4], B[4]; // first 满意度 second 编号
	A[1] = A[2] = A[3] = vector<pair<int, int> >(n + 1);
	B[1] = B[2] = B[3] = vector<pair<int, int> >(n + 1);
	_loopc(i, 1, n){	
		cin >> A[1][i].first >> A[2][i].first >> A[3][i].first,
		A[1][i].second = A[2][i].second = A[3][i].second = i;
		B[1][i] = A[1][i];
		B[2][i] = A[2][i];
		B[3][i] = A[3][i];
	}
	
	//优先选满意度大的
	sort(A[1].begin() + 1, A[1].end(), greater<pair<int, int> >()); // 部门 1
	sort(A[2].begin() + 1, A[2].end(), greater<pair<int, int> >()); // 部门 2
	sort(A[3].begin() + 1, A[3].end(), greater<pair<int, int> >()); // 部门 3

	vector<int> Ind[4]; // 满意度排名
	Ind[1] = Ind[2] = Ind[3] = vector<int>(n + 1);
	Ind[1][A[1][1].second] = Ind[2][A[2][1].second] = Ind[3][A[3][1].second] = 1; // 第一名
	for(int ind[4] = {0, 1, 1, 1}, i = 2; i <= n; i ++){
		// 部门 1
		if(A[1][i].first == A[1][i - 1].first) Ind[1][A[1][i].second] = ind[1];
		else Ind[1][A[1][i].second] = ++ ind[1];
		
		// 部门 2
		if(A[2][i].first == A[2][i - 1].first) Ind[2][A[2][i].second] = ind[2];
		else Ind[2][A[2][i].second] = ++ ind[2];
		
		// 部门 3
		if(A[3][i].first == A[3][i - 1].first) Ind[3][A[3][i].second] = ind[3];
		else Ind[3][A[3][i].second] = ++ ind[3];
	}
	
	// 现将他们分到不同的部门
	int siz[4] = {0}; // 部门已招人数
	int ans = 0; // 统计答案
	//	一个分配方案的满意度为所有新成员对分配到的部门的满意度之和
	_loopc(i, 1, n){
		pair<int, int> ind[4]; // first 排名 second 部门
		ind[1] = {Ind[1][i], 1};
		ind[2] = {Ind[2][i], 2};
		ind[3] = {Ind[3][i], 3};
		
		sort(ind + 1, ind + 4, [&](pair<int, int> a, pair<int, int> b){
			if(a.first != b.first) return a < b;
			if(B[a.second][i] != B[b.second][i]) return B[a.second][i] > B[b.second][i];
			return siz[a.second] < siz[b.second];
		});
		
		// 要求在分配方案中，不存在一个部门被分配多于 n/2 个新成员
		if(siz[ind[1].second] < n / 2) siz[ind[1].second] ++, ans += B[ind[1].second][i].first; // 招收人数未满
		else{ // 最大招满
			if(siz[ind[2].second] < n / 2) siz[ind[2].second] ++, ans += B[ind[2].second][i].first; // 尝试次大
			else siz[ind[3].second] ++, ans += B[ind[3].second][i].first; // 只能分到最小
		}
	}
	
	// 求出满足要求的分配方案的满意度的最大值
	cout << ans << '\n';
	return ;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
	
	int t; cin >> t;
	while(t --) solve();
	
	return 0;
}