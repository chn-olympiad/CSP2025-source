#include<iostream>
using namespace std;
int a[110];
int n,m,b;
int main()
{
	cin>>n>>m;
	int c=m,r=n;
	cin>>b;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>b){
			if(r>0)r-=1;
			else if(c>0){
				c-=1;
			}
		}
		else{
			cout<<c<<" "<<r;
		}
	}
    return 0;
 } 
