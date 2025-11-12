#include<bits/stdc++.h>
using namespace std;
int a[5010],n;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int big = 0;
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
		if(a[i] > big)big = a[i];
	}

	long long ans = 0;
	if(big == 1){
		for(int i = 3;i <= n;i++){
			long long cnt = 1;
			for(int j = 1;j <= i;j++){
				cnt = cnt*(n + 1 - j)%998244353 / j;
				cnt = cnt%998244353;
			}ans += cnt;
			ans = ans%998244353;
		}
		printf("%d",ans);
	}else if(n == 3){
		if(a[0] + a[1] + a[2]>big * 2){
			printf("1");
		}else{
			printf("0");
		}
	}else if(n == 4){
		for (int i = 1;i <= 4;i++){
			int cnt = 0;
			for(int j = 1;j <= 4;j++){
				if(j!=i){
					cnt+=a[j];
					if(a[j] > big)big = a[j];
				}
			}if(cnt > big * 2)ans++;
		}if(a[0] + a[1] + a[2] + a[3] > big * 2)ans++;
		printf("%d",ans);
	}else if(n == 5){
		for (int i = 1;i <= 5;i++){
			for(int x = 1;x <= 5;x++){
				int cnt = 0;
				for(int j = 1;j <= 5;j++){
					if(j != i && x != i&&x != j){
						cnt+=a[j];
						if(a[j] > big)big = a[j];
					}
				}if(cnt > big * 2)ans++;
			}
		}
		for (int i = 1;i <= 5;i++){
			int cnt = 0;
			for(int j = 1;j <= 5;j++){
				if(j!=i){
					cnt+=a[i];
				}
			}if(cnt > big * 2)ans++;
		}if(a[0] + a[1] + a[2] + a[3] + a[4] > big * 2)ans++;
	}
	return 0;
}
