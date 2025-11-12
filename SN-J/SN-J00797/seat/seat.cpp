//SN-J00797 王者淳 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],cnt=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[1])
		cnt++;
	}
	x=cnt/n+(cnt%n>0);
	if(x%2){
		y=cnt%n;
		if(cnt%n==0)y=n;
	}
	else{
		y=n-(cnt%n)+1;
		if(cnt%n==0)y=1;
	}
	cout<<x<<" "<<y;
	return 0;
}
