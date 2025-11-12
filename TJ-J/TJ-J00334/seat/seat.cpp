#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct node{
	int x,id;
}a[100005];
bool cmp(node x,node y){
	return x.x>y.x;
}
void f(int x){
	if(x%m==0){
		cout<<x/m<<" "<<n;
	}
	else{
		cout<<x/m+1<<" "<<x-(x/m)*n; 
	} 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<x<<" "<<y;
			return 0;
		}
		if(i%n==0){
			x++;
		}
		else{
			if(x%2==1)y++;
			else y--;
		}
	}
	return 0;
}
