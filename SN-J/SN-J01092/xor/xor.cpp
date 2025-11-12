#include<bits/stdc++.h>
using namespace std;
struct q{
	int s,e;
}st[500010] = {};
bool cmp(q x,q y){
	if(x.s  != y.s)return x.s < y.s;
	else return x.e < y.e;
}
int n,k,a[500010] = {},s[500010] = {},dp[500010] = {};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	//区间和公式：s[end] ^ s[start - 1] 
	int ans = 0,sum = 0;
	for(int l = 1;l <= n;l++){
		for(int r = l;r <= n;r++){
			int ans1 = s[r] ^ s[l - 1];
			if(ans1 == k || ( l == r && a[l] == k)){
				sum++;
				st[sum].s = l,st[sum].e = r;
			}
		}
	}
	for(int i = 1;i <= sum;i++){
		if(st[i].s > st[i - 1].e){
			ans ++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
