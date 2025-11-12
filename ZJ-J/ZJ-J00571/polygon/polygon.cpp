#include<bits/stdc++.h>
using namespace std;
int pop_count(int a){
	int res=0;
	while(a){
		if(a&1) res++;
		a>>=1;
	}
	return res;
}
vector<int> get_one(int a){
	vector<int>cnt;int res=0;
	while(a){
		if(a&1) cnt.push_back(res);
		a>>=1,res++;
	}
	return cnt;
}
const int N=24;
int n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<(1<<n);i++){
		if(pop_count(i)<3) continue;
		int sum=0,Max=0;
		for(int p:get_one(i)){
			sum+=a[p],Max=max(Max,a[p]);
		}
		if(sum>2*Max) ans++;
	}
	cout<<ans%998244353;
	return 0;
}
