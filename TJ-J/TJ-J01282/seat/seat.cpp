#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],tgt;
bool cmp(int x,int y){
	return x>y;
}
void f(int x,int y,int dr,int id){
	if (a[id]==tgt){
		cout<<y<<" "<<x;
		return;
	}
	if (x==1&&dr==0){
		f(x,y+1,1,id+1);
	}else if (x==n&&dr==1){
		f(x,y+1,0,id+1);
	}else if (dr==0){
		f(x-1,y,0,id+1);
	}else{
		f(x+1,y,1,id+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[m*(i-1)+j];
		}
	}
	tgt=a[1];
	sort(a+1,a+n*m+1,cmp);
	f(1,1,1,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
