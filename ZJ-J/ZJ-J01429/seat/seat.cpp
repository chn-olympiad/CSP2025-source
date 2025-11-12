#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			int x=i/m;
			if(x*m!=i){
				x++;
			}
			if(x%2==1){
				cout<<x<<" "<<i-(x-1)*m;
			}else{
				cout<<x<<" "<<n-(i-(x-1)*m)+1;
			}
		}
	}
	return 0;
}

