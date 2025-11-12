#include<bits/stdc++.h>
using namespace std;
int m,n,x,y;
int a[105];
int q,e=0;
int main(){
	cin>>m>>n;
	q=n*m;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	int w=a[1];
	for(int i=1;i<=q;i++){
		if(a[i]>w){
			e++;
		}
	}
	e++;
	if(e%n!=0){
		x=e/n+1;
		if(x%2==0){
			y=n+1-e%n;
		}
		else{
			y=e%n;
		}
	}
	else{
		x=e/n;
		if(x%2==0){
			y=1;
		}
		else{
			y=n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
/*º«ÓêÔó */
