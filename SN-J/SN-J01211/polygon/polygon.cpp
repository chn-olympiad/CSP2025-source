#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int maxx;
int summ;
long long ans,cnt;
long long _c(int x,int y){//组合数 
	cnt = 1;
	if(x * 2 > y){
		x = y - x;
	}
	//cout<<" -组合数：x="<<x<<",y="<<y<<endl;
	for(int i = 1;i <= x;i++){
		cnt *= y - i + 1;
		cnt /= i;
		//cnt %= (long long)998244353;
		//cout<<" -组合数：第"<<i<<"次循环后，cnt="<<cnt<<endl;
	}
	return cnt % (long long)998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		maxx = max(maxx,a[i]);
		summ += a[i];
	}
	if(n == 3 && !(maxx == 1)){
		if(summ > maxx * 2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	if(maxx == 1){
		for(int i = 3;i <= n;i++){
			//cout<<"计算组合数：c("<<i<<","<<n<<")"<<endl;
			ans += _c(i,n) % (long long)998244353;
			ans %= (long long)998244353;
		}
		cout<<ans;
	}
	return 0;
}
/*
50
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

//我的输出：65979708 
*/
//WA 12~36 只拿局部分 
