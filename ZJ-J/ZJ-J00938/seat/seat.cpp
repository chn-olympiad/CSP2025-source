#include<bits/stdc++.h>//%%% LinkCatTree
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int x,ans;
	scanf("%d",&x);
	for(int i=2;i<=n*m;i++){
		int t;
		scanf("%d",&t);
		if(t>x)ans++;
	}
	int lie=ans/n+1,hang;
	if(lie%2)hang=ans%n+1;
	else hang=n-(ans%n);
	printf("%d %d",lie,hang);
}
/*
4 5
54 51 52 53 50 55 56 57 58 59 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/
