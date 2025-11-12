#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1005],pos;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==q){
			pos=i;
			break;
		}
	}
	int l,h;
	if (pos%n==0){
		l=pos/n;
	}
	else{
		l=pos/n+1;
	}
	if (l%2==1){
		if (pos%n==0){
			h=n;
		}
		else{
			h=pos%n;
		}
	}
	else{
		if (pos%n==0){
			h=1;
		}
		else{
			h=n+1-pos%n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
