//赵柏然-SN-J01020-曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon","w",stdout);
	int n;
	cin>>n;
	long long c=0,r=0,l=1,xx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xx+=a[i];
	}

	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		xx-=a[i];
		r=xx;
		l=1;
		if(xx>a[i]){
			c++;
		}
		for(int k=n;k>3;k--){
			for(int j=l;j<i;j++){
				r-=a[j];
				if(r>a[i]){
					c++;
				}
				r+=a[j];
			}	
			r-=a[l];
			l++;			
		}

	}
	cout<<c;
	return 0;
}
