#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int num = 0;
	for(int i = 0;i < n;i++){
		for(int m = 3;m <= n-i+1;m++){
			for(int j = i+1;j < n;j++){
				for(int f = j+1;f-j+2==m;f++){
					int sum = 0;
					for(int e = j;e <= f;e++){
						sum+=a[e];
					}
					if(sum > f*2){
						num++;
					}
				}
			}
		}
	}
	cout << num%998244353;
}
