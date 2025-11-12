// 考号：SN-J01164 姓名：马星辰 学校：西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if (a+b+c>max({a,b,c})*2)
		cout<<1;
	else
		cout<<0;
	return 0;
}
