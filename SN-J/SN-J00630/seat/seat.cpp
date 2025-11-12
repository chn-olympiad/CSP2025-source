#include<bits/stdc++.h>
using namespace std;
int n,m;
int z;
int x;
int t;
int a,b;
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
    cin>>n>>m;
    cin>>z;
    t=0;
    for(int i=2;i<=n*m;i++){
    	cin>>x;
    	if(x>z){
    		t++;
		}
	}
	a=1;
	if(t==0){
		cout<<"1"<<" "<<"1";
		return 0;
	}
	while(t>0){
		if(t>n){
			t-=n;
			a++;
		}else if(t==n){
			a++;
			if(a%2==0){
				b=n;
			}else{
				b=1;
			}
			t=0;
		}else if(t<n){
			if(a%2==0){
				b=n-t;
			}else{
				b=t+1;
			}
			t=0;
		}
	}
	cout<<a<<" "<<b;
	return 0;
}
