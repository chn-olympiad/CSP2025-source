// 考号：SN-J01164 姓名：马星辰 学校：西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],x,n,sn;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sn = n = strlen(s);
	for (int i = 0,j = 1;i < n;i++){
		x = int(s[i]);
		x = x - 48;
		if ((x >= 0) && (x <= 9)){
			a[j] = x;
			j++;
		}
		else
			sn--;
	}
	for (int i = 1;i <= sn;i++){
		for (int j = 1;j <= sn - i;j++)
			if (a[j] < a[j + 1])
				swap(a[j],a[j + 1]);
	}
	for (int i = 1;i <= sn;i++)
		cout<<a[i];
	return 0;
} 
