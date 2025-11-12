#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int cmp(int u,int v){
	return u > v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	int x = a[1];
	int p = 0;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == x){
			p = i;
		}
	}
	int l = p/(2*n)*2;
	int h = p%(2*n);
	if(h == 0){
		cout<<l<<" "<<1<<endl;
		return 0;
	}
	if(h <= n){
		l += 1;
		cout<<l<<" "<<h<<endl;
	}else{
		l += 2;
		cout<<l<<" "<<2*n-h+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

