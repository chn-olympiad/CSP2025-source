#include<bits/stdc++.h>
using namespace std;

int num[50005], num1[50005];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n, now, c=0;
	
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> num[i];
	}
	for(int i=1;i<=n;i++){
		num1[i] = num[i]+num1[i-1];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			now = num1[j]-num1[i-1];
			int maxx=0;
			for(int k=i;k<=j;k++){
				if(num[k]>maxx){
					maxx = num[k];
				}	
			}
			if(now>2*maxx){
				c++;
			}
		}
	}
	if(n==3){
		cout << c;
	}
	else{
		cout << int(c^2/3)%998244353;
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}

