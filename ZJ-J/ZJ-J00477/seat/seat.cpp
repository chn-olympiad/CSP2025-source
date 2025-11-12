#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	int st;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			st=i;
			break;
		}
	}
	if((st-1)/n%2==0){ //jishu hang
		cout<<(st-1)/n+1<<' ';
		int ln=(st-1)%n+1;
		cout<<ln;
	}else{ //oushu hang
		cout<<(st-1)/n+1<<' ';
		int ln=(st-1)%n+1;
		cout<<n-ln+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}