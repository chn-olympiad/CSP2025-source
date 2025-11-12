#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],ans;
int tj[500005];
struct node{
	int l,r;
};
vector<node> t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long edu = a[i]; 
			for(int now = i+1;now <= j;now++){
				edu ^= a[now];
			}
			if(edu != k) continue;
			t.push_back({i,j});
		}	
	}
	cout << t.size();
	return 0;
}
