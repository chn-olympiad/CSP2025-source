#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int p=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	int q=0;
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==p){
			q=i-1;
		}
	}
	int x=1,y=1;
	while(q--){
		if (x%2==1){
			y++;
			if (y>n){
				x+=1;
				y=n;
			}
		}
		else if (x%2==0){
			y--;
			if (y<1){
				x+=1;
				y=1;
			}
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
