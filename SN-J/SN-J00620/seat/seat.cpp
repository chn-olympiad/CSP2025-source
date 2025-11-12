//SN-J00620 杨昕然 西安高新第一中学  
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],x1,x2,Fen;
bool flag;
bool cmp(long long x,long long y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n*m; i++){
		cin>>a[i];
	}
	Fen=a[1];
	stable_sort(a+1,a+1+n*m,cmp);
	x1=1;x2=1;
	for(long long i=1; i<=n*m; i++){
		if(a[i]==Fen){
			cout<<x1<<' '<<x2;
			return 0;
		}
		if(flag==0&&x2==n){
			flag=1;
			x1++;
		}
		else if(flag==0){
			x2++;
		}
		else if(flag==1&&x2==1){
			flag=0;
			x1++;
		}
		else if(flag==1){
			x2--;
		}
	}
	return 0;
}
/*
1.
3 3
95 92 93 91 94 96 97 98 99 100
ans:
2 1

longlong

1.moni
*/
