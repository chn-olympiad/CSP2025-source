#include<bits/stdc++.h>
using namespace std;
int n,m,a[30],r;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			int x=i/n,y=i%n;
			if(y==0){
				cout<<x;
				if(x%2) printf(" %d",n);
				else cout<<" 1";
			}else{
				cout<<x+1;
				if(x%2) printf(" %d",n-y+1);
				else printf(" %d",y);
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
