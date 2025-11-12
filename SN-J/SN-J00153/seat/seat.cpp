#include<bits/stdc++.h>
using namespace std;
int n,m,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[100];
    int x = n*m;
    for(int i = 1;i <= n*m;i++){
    	cin>>a[i];
	}
	int z = a[1];
	sort(a+1,a+x+1);
	for(int i = x;i >= 1;i--){
	    if(a[i] == z){
		   y = x-i+1;
	    break;
		}
	}
	if(n==1&&m==1){
		cout<<"1"<<" "<<"1";
	}
	else if(n==1&&m<=10){
		cout<<y<<" "<<"1";
	}
	else if(n<=10&&m==1){
		cout<<"1"<<" "<<y;
	}
	else if(n<=2&&m<=2){
		if(z/n==0){
			cout<<"1"<<" "<<y;
		}else{
			if(z/n%2==0){
				cout<<z/n<<" "<<y;
		    }else{
		    	cout<<z/n<<" "<<n-y+1;
	     	}
		}
	}
	return 0;
}

