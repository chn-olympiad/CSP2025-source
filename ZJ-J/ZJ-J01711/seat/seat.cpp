#include <iostream>
#include <algorithm>
using namespace std;
int a[101]={0},b[11][11]={0};
bool cmp(int i,int j){
	if(i>j) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,xy,a1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			cout<<x<<" "<<y<<endl;
			break;
		}
		if(x%2==1){
			if(y==n) x++;
			else y++;
		}
		else{
			if(y==1) x++;
			else y--;
		}
	}
	return 0;
}
