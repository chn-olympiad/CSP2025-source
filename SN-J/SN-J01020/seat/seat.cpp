//赵柏然-SN-J01020-曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=1;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			x++;
		}
	}
	int q=x/n;
	if(x%n>0){
		q++;
	}
	int p=0;
	if(q%2==0){
		p=n-x%n;
		if(p==n){
			p=1;
		}else{
			p+=1;
		}
	}else{
		p=x%n;
		if(p==0){
			p=n;
		}
	}
	cout<<q<<" "<<p;
	return 0;
}
