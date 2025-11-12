#include <bits/stdc++.h>
using namespace std;
int n,m,arr[110];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) cin >> arr[i];
	int x=arr[1],i=0,j=1,xb=1;
	bool flag=true;
	sort(arr+1,arr+n*m+1,cmp);
	while(arr[xb]>=x) {
		if(flag)
			i++;
		else
			i--;
		if(i>n&&flag) {
			j++;
			i=n;
			flag=false;
		}
		if(i<1&&!flag) {
			j++;
			i=1;
			flag=true;
		}
		xb++;
	}
	cout << j << ' ' << i;
	return 0;
}
