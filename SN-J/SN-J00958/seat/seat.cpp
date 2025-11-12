#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int scr=a[1];
	int k;
	sort(a+1,a+n*m+1);
	for (int i=1;i<=n*m;i++){
		if (a[i]==scr){
			k=n*m-i+1;
			break;
		}
	}
	int c=(k-1)/n+1;
	int r=k-(c-1)*n;
	if (c%2==0) r=n-r+1;
	cout << c << ' ' << r;
	fclose(stdin);fclose(stdout);
	return 0;
}
