#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[101];
	for(int i = 1;i <= n*m;i ++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+n*m+1,cmp);
	int i = 1,j = 1;
	bool b = true;
	for(int k = 1;k <= n*m;k ++){
		if(a[k]==r) {
			cout << j << " " << i;
			break;
		}if(b&&n>i){
			i++;
		} else if(b&&n==i){
			j++;
			b = false;
		} else if(!b&&i>1){
			i--;
		} else if(!b&&i==1){
			j++;
			b = true;
		}
	}
	return 0;
} 
