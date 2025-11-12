//SN-J00689  wangqikun  xi'anjiaodafuzhongchanbayouanxuexiao
#include "bits/stdc++.h"
using namespace std;
int n,m,R,R_idx,num,ans_1,ans_2;
struct stu{ int fen; }a[107];
bool cmp(stu x,stu y){ return x.fen>y.fen; }
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].fen;
	R=a[1].fen;
	sort(a+1,a+n*m+1,cmp); 
	for(int i=1;i<=n;i++){ if(a[i].fen==R){ R_idx=i; break; } }
	num=R_idx/n;
	if(num%2==0){ ans_1=n+1-R_idx%n; ans_2=num; }
	else{ ans_1=R_idx%n; ans_2=num; }
	cout<<ans_1<<' '<<ans_2;
	return 0;
}
