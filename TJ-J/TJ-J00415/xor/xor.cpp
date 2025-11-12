#include <iostream>
using namespace std;
int n,k,a[100005],x,sam,p,r;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=i+1;l-1<=j;l++){
				if(i==j){
					x=a[i];
					break;
				}
				else{
				    x+=a[i]|a[i-1];
		    	}
			}
			if(x==k && i>p && j>r){
				sam++;
				p=i;
				r=j;
			}
			x=0;
		}
	}
	cout<<sam;
}
