#include <bits/stdc++.h>
using namespace std;
int n,m;//n行数,m列数 
struct czbjz{
	int s;
	bool f;
}a[105];
bool cmp(czbjz b,czbjz j){
	return b.s>j.s;
}
int id;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].f=1;
	for (int i=1;i<=n*m;i++){
		cin>>a[i].s;
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i].f==1){
			id=i;
			break;
		}
	}
	int lie=0;
	if (floor(id*1.0/n)!=(1.0*id/n)){
		lie=floor(id/n)+1;
	}
	else{
		lie=id/n;
	} 
	int hang=0;
	if (lie%2==1){
		hang=id%n;
		if (hang==0){
			hang=n;
		}
	}
	else{
		hang=id%n;
		if (hang==0){
			hang=1;
		}
		else{
			hang++;
		}
	} 
	cout<<lie<<' '<<hang;
	return 0;
} 
