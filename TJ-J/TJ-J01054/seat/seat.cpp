#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int c,cp;
bool Cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m,Cmp);
	for(int i=1; i<=n*m; i++){
		if(c==a[i]){
			cp=i;
			break;
		}
	}
	int x=0,y=0;
	x=cp/n;
	y=cp%n;
	if(y==0){
		if(x%2==0){
			y=1;
		}
		else if(x%2==1){
			y=n;
		}
	}
	else if(y>0){
		if(x%2==1){
			x++;
			y=n-y+1;
		}
		else if(x%2==0){
			x++;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
