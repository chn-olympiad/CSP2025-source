#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,s;
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
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(s>n){
			s-=n;
		}else{
			if(i%2==1){
				cout<<i<<" "<<s;
			}else{
				cout<<i<<" "<<n-s+1;
			}
			break;
		}
	}
	return 0;
}
