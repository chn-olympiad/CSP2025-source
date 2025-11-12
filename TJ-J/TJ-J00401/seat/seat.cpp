#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[107];
int f;
int c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==f){
			c=i/n;
			if(i%n>0){
				++c;
			}
			
			if(c%2==1){
				r=i%n;
			}
			else{
				r=n-(i%n)+1;
			}
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}
