#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m;
int a[maxn];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int boss=0,id=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	boss=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==boss){
			id=i;
		}
	}
	int x=(id+n-1)/n;
	int y;
	if(x%2==0){
		if(id%n==0){
			id=n;
		}else{
			id%=n;
		}
		y=n-id+1;
	}else{
		if(id%n==0){
			id=n;
		}else{
			id%=n;
		}
		y=id;
	}
	cout<<x<<" "<<y;
	return 0;
}
