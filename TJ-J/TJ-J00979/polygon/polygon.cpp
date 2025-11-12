#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int p=0,s=0;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	for(int i=0;i<n;i++){
		p+=a[i];
	}
	p=p/n*2;
	int l=n*2+1;;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			s+=a[j];
			for(int k=0;k<n;k++){
				s+=a[k];
			}
		}
		if(s<p) l--;
		s=a[i];
	}
	cout<<l-n;
    return 0;
}

