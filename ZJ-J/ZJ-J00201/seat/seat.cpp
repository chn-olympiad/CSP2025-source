#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[1000001],x,xh,t,w;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	t=1,w=1;xh=1;
	while(t<=n&&w<=m){
		if(a[xh]==x){
			cout<<w<<" "<<t;return 0;
		}
		if(xh%n==0)w++;
		else{
			if(w%2==1)t++;
		    else t--;
		}
		xh++;
	}
}
