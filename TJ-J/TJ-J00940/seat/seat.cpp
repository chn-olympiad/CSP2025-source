#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MaxN = 11;
int n,m,f;
int a[MaxN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i<n*m;i++) cin >> a[i];f = a[0];
	for(int i = 0;i<n*m;i++){
		for (int j = i;j<n*m;j++){
			if (a[i] <= a[j]) swap(a[i],a[j]);
		}
	} 
	int j = 1;
	bool flag = 0;
	for (int i = 0;i<n*m;i++){
		if (a[i] != f){
			if (!flag){
				if (j == m){
					flag = 1;
				}else j++;
			}else{
				if (j == 1){
					flag = 0;
				}else j--;
			}
		}else if (a[i] == f){
			if (i % 2 == 0){
				i = i/2;
				cout << i << ' ' << j;
				return 0;
			}else{
				cout << i << ' ' << j;
				return 0;
			}
			
		}
	}
	return 0;
}

