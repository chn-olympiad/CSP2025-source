#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
};
int n,m,x=1;
node a[1000];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i].x;
    	a[i].y=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[x].y==1){
					cout<<i<<" "<<j;
					return 0;
				}			
				x++;	
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[x].y==1){
					cout<<i<<" "<<j;
					return 0;
				}	
				x++;			
			}
		}
	}
    return 0;
}
