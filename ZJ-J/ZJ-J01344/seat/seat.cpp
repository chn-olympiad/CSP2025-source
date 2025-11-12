#include<bits/stdc++.h>
using namespace std;
long long a[200],f[200],n,m,p,x=1,y=1,sum,way1=1,way2=1;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p) sum=i;
	}
	for(int i=2;i<=sum;i++){
		if(way1){
			if(way2){
				x++;
				if(x==n) way1=way2=0;
			}
			else{
				x--;
				if(x==1) way1=0,way2=1;
			}
		}
		else y++,way1=1;
	}
	cout<<y<<' '<<x;
	return 0;
}
