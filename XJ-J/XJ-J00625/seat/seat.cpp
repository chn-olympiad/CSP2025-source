#include<bits/stdc++.h>
using namespace std;
int m,n,x=1,a,b;
int num[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=m*n;
	for(int i=1;i<=q;i++){
		cin>>num[i];
	}
	int k=num[1];
	sort(1+num,num+q+1);
	for(int i=q;i>=1;i--){
		if(num[i]==k) break;
		x++;
	}
	if(x<n){
		a=1;
		b=x;
		cout<<a<<" "<<b;
		return 0;
	}
	if(x==n){
		a=1;
		b=n;
		cout<<a<<" "<<b;
		return 0;
	}
	if(x>n){
		int c=x/n+1;
		if(c%2==0){
			a=c;
			b=n-(x-(n*(c-1)))+1;
			cout<<a<<" "<<b;
			return 0;
		}
		if(c%2!=0){
			a=c;
			b=x-n*(c-1);
			cout<<a<<" "<<b;
			return 0;
		}
	}
	return 0;
}
