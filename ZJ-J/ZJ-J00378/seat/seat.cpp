#include<bits/stdc++.h>
using namespace std;
int n,m,a[300];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//=================
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int tmp=a[1],id;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			id=i;
			break;
		}
	}
	int x=1+(id-1)/n,y,t=id%n;
	if(t==0)t=n;
	if(x%2==0)y=n-t+1;
	else y=t;
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
