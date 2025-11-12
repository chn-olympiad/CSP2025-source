#include<bits/stdc++.h>
using namespace std;
int n,m,a[105]={};
bool flag=false;
bool ord(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b;
	cin>>n>>m;
	int dx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dx++;
			cin>>a[dx];
			if(i==1&&j==1){
				b=a[i];
			}
		}
    }
    sort(a+1,a+1+dx,ord);
    int nx=0;
    int x,y;
    for(int i=1;i<=m;i++){
    	if(flag){
    		break;
		}
    	for(int j=1;j<=n;j++){
    		nx++;
    		if(a[nx]==b){
    			x=i;
    			if(i%2==0){
    				y=n-j+1;
				}
				else{
					y=j;
				}
				cout<<x<<" "<<y;
				flag=true;
				break;
			}
		}
	}
	return 0;
}
