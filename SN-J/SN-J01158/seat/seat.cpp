#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,a,x,d=1;
    cin>>n>>m>>a;
    for(int i=2;i<=n*m;i++){
    	cin>>x;
    	if(x>a){
    		d++;
		}
	}
	int h,l;
	l=(d-1)/n+1;
	h=(d-1)%n+1;
	if(l%2==0){
		h=n+1-h;
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
