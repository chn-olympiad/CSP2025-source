#include<bits/stdc++.h>
using namespace std;
int a[105],p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			p=i;	
		}
	}
	if(p<=n){
		cout << 1 << " " << p;
		return 0;
	}
	int l=p/n+1;
	if(l%2){
		int h=p-(l-1)*n;
		cout << l << " " << h;
	}else{
		int h=n-(p-(l-1)*n)+1;
		cout << l << " " << h;
	}
	return 0;
}
