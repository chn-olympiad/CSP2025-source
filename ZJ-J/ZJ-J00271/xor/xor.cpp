#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 1 << 21;

int n, k, a[N];
long long f[N];
int mp[M];
vector<int> vec[M];

int find(int x, int p){
	if(vec[x].size() == 0) return -1;
	int l = 0, r = vec[x].size() - 1;
	int res = -1;
	while(l <= r){
		int mid = l + r >> 1;
		if(vec[x][mid] < p){
			res = vec[x][mid];
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	
	return res;
}

int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	scanf("%d%d", &n, &k);
	
	for(int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), a[i] ^= a[i - 1];

	for(int i = 0; i < M; i ++)
		mp[i] = i ^ k;
		
	for(int i = 0; i <= n; i ++)
		vec[a[i]].push_back(i);

	for(int i = 1; i <= n; i ++){
		int j = find(mp[a[i]], i);
		
		if(j != -1) f[i] = max(f[i], f[j] + 1);
		
		f[i] = max(f[i], f[i - 1]);
	}

	
	printf("%d\n", f[n]);
	
	return 0;
}