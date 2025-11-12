// 考号：SN-J01164 姓名：马星辰 学校：西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
int i,n,k,a[500020],ans = 0,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	i = n;
	sum = 0;
	while(i--){
		sum+=a[n-i];
		if (sum == k)
			ans++,sum = 0;
	}
	cout<<ans;
	return 0;
} 
