#include<bits/stdc++.h>
using namespace std;
int n;
const int maxx = 5e3 + 5;
int a[maxx];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n == 1 || n == 2)cout << 0;
	if(n == 3){
		if(a[1] + a[2] > a[3]){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if(a[n] == 1){
		long long cnt = 0;
		for(int i = 1 ; i <= n ; i++){
			long long sum = 1;
			for(int j = 1 ; j <= n ; j++){
				sum *= (n-j+1);
			}
			cnt += sum;
		}
		cout << cnt % 998 % 244 % 353;
	}
		
	
		
	
    fclose(stdin);fclose(stdout);
	return 0;
}
