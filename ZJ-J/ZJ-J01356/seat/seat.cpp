#include<bits/stdc++.h>
using namespace std;
struct nod{
	int x,s;
}e[101];
int n,m;
bool cmp(nod a,nod b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=m*n;
	for(int i=1;i<=l;i++){
		cin>>e[i].x;
		e[i].s=i;
	}
	sort(e+1,e+l+1,cmp);
	int f;
	for(int i=1;i<=l;i++){
		if(e[i].s==1){
			f=i;
			break;
		}
	}
	int k=f/n;
	int h=f%n;
	if(h==0){
		cout<<k<<' ';
		if(k%2)cout<<n;
		else cout<<1;
	}
	else{
		cout<<k+1<<' ';
		if(k%2)cout<<n-h+1;
		else cout<<h;
	}
	return 0;
}
