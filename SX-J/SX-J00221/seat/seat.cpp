#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}
	else{
		return false;
	}
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++){
    	cin>>a[i];
	}
	int q=a[1];
	int c;
	sort(a+1,a+1+t,cmp);
     for(int i=1;i<=t;i++){
        if(a[i]==q){
        	c=i;
		}
	 }

	 if(c<=n){
	 	cout<<1<<" "<<c;
	 	return 0;
	 }
	 if(c%n==0){
	 	if(c/n%2==0){
	 		cout<<c/n<<" "<<1;
	 		return 0;
		 }
		 if(c/n%2!=0){
		 	cout<<c/n<<" "<<n;
		 	return 0;
		 }
	 }
    else{
    	cout<<c/n+1<<" ";
    	if((c/n+1)%2==0){
    		cout<<n-(c%n)+1;
		}
		else{
			cout<<c%n;
		}
	}
	return 0;
}