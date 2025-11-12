#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	for(int i=2;i<=n*m;i++)  cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	int d=1,x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k) break;
		if(d==1){
			if(x==n){
				y++;
				d=-1;
			}else x++;
		}else{
			if(x==1){
				y++;
				d=1;
			}else x--;
		}
	}
	cout<<y<<' '<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
