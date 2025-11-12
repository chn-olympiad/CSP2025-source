//估测正解时间复杂度瓶颈为排序
//O(n^3) 暴力32分
//将所有符合要求的区间加入数组
//最后贪心选区间 
//(a ^ b ^ b) = a --> 前缀和优化 O(n^3)->O(n^2)
//(a ^ (a ^ b) ) = b --> map查找优化 O(n^2)->O(nlogn)
//9:50 正解！！！ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct str{
	int l,r;
};
int n,k,a[500005],f[500005];
vector<str> ma;
bool cmp(str a,str b){
	return a.r<b.r;
}
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	mp[0] = 1;
	for(int i = 1;i<=n;i++){
		f[i] = f[i-1]^a[i];
		mp[f[i]] = i+1;
		int lp = f[i]^k;
		if(a[i]==k){
			ma.push_back({i,i});
		}
		if(mp.count(lp)){
			if(mp[lp]!=i+1) ma.push_back({mp[lp],i});
		}
	}
	sort(ma.begin(),ma.end(),cmp);
	int l = -1;
	int sum = 0;
	for(int i = 0;i<ma.size();i++){
		if(ma[i].l>l){
			l = ma[i].r;
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
