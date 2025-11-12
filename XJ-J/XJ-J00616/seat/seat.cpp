#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m,c=1,r=1;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++){
		if(a[0]<a[i]){
			if(c<n&&r==1){
				r++;
				break;
			}
			else if(c==n&&r==1){
				c++;
				break;
			}
			else if((c==n&&r%2==0)||(c!=n&&c<0&&r%2==0)){
				r--;
				break;
			}
			else{
				r++;
				break;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
