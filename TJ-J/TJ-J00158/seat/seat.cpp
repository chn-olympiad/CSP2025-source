#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],c=0,x=1,y=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	bool f=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			break;
		}
		if(!f&&y==n){
			f=1;
			x++;
		}
		else if(f&&y==1){
			f=0;
			x++;
		}
		else if(f) y--;
		else if(!f) y++;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
