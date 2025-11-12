#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105],c=1,r=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int csp=a[1];
	sort(a+1,a+n*m+1);
	int i=1;
	while(a[i]!=csp){
		i++;
	}
	i=n*m-i;
	i++;
	int js=0;
    for(int c=1;c<=m;c++){
    	int num;
    	for(int r=1;r<=n;r++){
    		if(c%2==0){
				num=(c-1)*n+n+1-r;
			}
			else{
				num=(c-1)*n+r;
			}
			if(num==i){
				cout<<c<<" "<<r;
				return 0;
			}
		}
	}
}