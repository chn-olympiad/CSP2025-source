#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,pos;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(cnt==a[i]){
			pos=i;
			break;
		}
	}
	int x=1,y=1;
	for(int i=1;i<pos;i++){
		if(y%2==1){
			if(x<n) x++;
			else y++;
		}
		else{
			if(x>1) x--;
			else y++;
		}
	}
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
