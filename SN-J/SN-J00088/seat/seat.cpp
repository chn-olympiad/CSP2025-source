#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, tot;
int pai, lie;
constexpr int N=12*12;
struct node{
	int id, fenshu;
}a[N];
bool cmp(node a, node b){
	return a.fenshu>b.fenshu;
}
int littleR;
signed main(){
	freopen("seat.in", "r", stdin); freopen("seat.out", "w", stdout);
	cin>>n>>m;
	tot=n*m;
	for(int i=1;i<=tot;i++){
		cin>>a[i].fenshu; a[i].id=i;
	}
	sort(a+1, a+1+tot, cmp);
	for(int i=1;i<=tot;i++){
		if(a[i].id==1){
			littleR=i;
			break;
		}
	}
	int lie=littleR/n;
	pai=littleR-n*lie;
	if(pai==0){
		if(lie%2==0) cout<<lie<<" "<<1<<"\n";
		if(lie%2==1) cout<<lie<<" "<<n<<"\n";
		return 0;
	}
	if(lie%2==0){
		cout<<lie+1<<" "<<pai<<"\n";
		return 0;
	}
	if(lie%2==1){
		cout<<lie+1<<" "<<n-pai+1<<"\n";
		return 0;
	}
	return 0;
}
/*
4 3
4 1 2 3 5 6 7 8 9 10 11 12

2 2
99 100 97 98
3 3
94 95 96 97 98 99 100 93 92
*/
