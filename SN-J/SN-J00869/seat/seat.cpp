#include <bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m ;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int hua=a[1];
	int pm;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if (a[i]==hua) {
			pm=i;
		}
	}
	int lie;
	if(pm % n == 0){
		lie = pm / n ;
	}
	else {
		lie = pm / n + 1;
	}
	int pai;
	if(lie%2==1){
	    pai=pm%n;
		if(pm%n==0){
			pai=n;
		}
	}
	else {
		pai=n-pm%n+1;
		if(pm%n==0){
			pai=1;
		}
	}
	cout << lie << " " << pai ;
	return 0;
}

