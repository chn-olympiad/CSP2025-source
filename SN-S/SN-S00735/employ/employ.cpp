#include<bits/stdc++.h>
using namespace std;
int nx[514] = {},bo[514] = {};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int time = 0,n,m;
	string s;
	long long ans = 0;
	cin >> n >> m >> s;
	s = ' ' + s;
	for(int i = 1;i <= n;i++)cin >> nx[i];
	for(int i = 1;i <= n;i++){
		time++;
		int sum = 0;
		if(s[i] == '0')continue;
		for(int j = 1;j <= n;j++){
			if(nx[j] <= time && !bo[j]){
				sum ++;
				bo[j] = 1;
			}
		}
		if(sum){
			if(ans == 0)ans = 1;
			ans *= sum;
		}
	}
	printf("%d",ans % 998 %244 % 353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
