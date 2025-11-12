#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[115],z,b,c,x,y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			z=i;
			break;
		}
	}
	x=z/m;
	y=z%m;
	if(y!=0){
		x++;
	}
	if(y==0){
		y=m;
	}
	if(x%2==1){
		cout<<x<<" "<<y;
	}
	if(x%2==0){
		cout<<x<<" "<<m-y+1;
	}
	return 0;
}
