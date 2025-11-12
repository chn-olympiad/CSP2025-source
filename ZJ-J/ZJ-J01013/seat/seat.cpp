#include<bits/stdc++.h>
using namespace std;
struct node{
	int c,id;
};bool cmp(node a,node b){
	return a.c>b.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,idxx;
	node a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].id=i;
	}sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			idxx=i;
			break;
		}
	}int b1=(idxx+n-1)/n;
	if(b1%2==0){
		cout<<b1<<" "<<n-idxx%n+1;
	}else{
		cout<<b1<<" "<<idxx-(b1-1)*n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
