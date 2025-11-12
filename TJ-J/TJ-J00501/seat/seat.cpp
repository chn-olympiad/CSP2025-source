#include<bits/stdc++.h>
using namespace std;
int c(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	int h=1,l=1;
	sort(a+1,a+n*m+1,c);
	if(a[1]==b){
		cout<<"1 1";
	}else{
		for(int i=2;i<=n*m;i++){
		    if(l%2==1&&h==n){
			    l++;
		    }else if(l%2==0&&h==1){
			    l++;
		    }else if(l%2==1){
			    h++;
		    }else{
			    h--;
		    }
		    if(a[i]==b){
		    	cout<<h<<" "<<l;
		    	break;
			}
	    }
	}
}
