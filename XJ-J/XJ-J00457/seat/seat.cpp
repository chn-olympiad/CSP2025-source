#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[110];
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int f=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==f) f=i;
	}
	if(f%n!=0){
		if((f/n+1)%2!=0) cout << f/n+1 << " " << f-(f/n*n);
		else cout << f/n+1 << " " << f/n*n;
	}
	else{
		if(f/n%2!=0) cout << f/n << " " << f/n*n;
		else cout << f/n << " " << f-(f/n*n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
