#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,m,a[maxn],tmp;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	int p;
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			p=i;
			break;
		}
	}
	int r=ceil((double)p/(double)n),q=p%n;
	if(r&1){
		if(q==0){
			q=n;
		}
	}else{
		if(q!=0){
			q=n+1-q;
		}else q=1;
	}
	cout<<r<<' '<<q;
	return 0;
}
