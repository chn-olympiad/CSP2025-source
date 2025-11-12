#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,j;
    int a[101]={};
    a[0]=102;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	j=a[1];
	for(int i=1;i<=n*m;i++){
		for(int i=1;i<=n*m;i++){
		    if(a[i]>a[i-1]){
		        a[i]=a[i-1];
			}
    	}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==j){
		    cout<<i/n+i%n<<" "<<i/m+i%m;
		    break ;
		}
	}

    return 0;
}
