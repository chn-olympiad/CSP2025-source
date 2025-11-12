#include<bits/stdc++.h>
using namespace std;
struct obj{
	int cj;
	int idx;
};
obj g[1009];
bool cmp(obj a,obj b){
	if(a.cj>b.cj) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>g[i].cj;
		g[i].idx=i;
	}
	int wz;
	sort(g+1,g+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(g[i].idx==1) wz=i;
	}
	int c=wz/n;
	int r;
	if(c%2==0) r=wz%n;
	else{
		r=m-wz%m;
		if(wz%m!=0) r++;
	}
	if(wz%n>0) c++;
	cout<<c<<" "<<r;
	return 0;
}
