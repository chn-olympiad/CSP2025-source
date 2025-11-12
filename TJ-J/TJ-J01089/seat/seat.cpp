#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
int R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	int y=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=(n*m);i++){
		if(a[i]!=R){
			y++;
		}
		else{
			break;
		}
	}

	y++;
	int lie=(y/n);
	int hang=(y%n);
	if(hang==0){
		if(lie%2==0){
			cout<<lie<<' '<<1;
		}
		else{
			cout<<lie<<' '<<n;
		}
	}
	else{
		if(lie%2==0){
			cout<<lie+1<<' '<<hang;
		}
		else{
			cout<<lie+1<<' '<<n-hang+1;
		}
	}
	return 0;
}
