#include <bits/stdc++.h>
using namespace std;
bool cmp(int z,int y){
	return z>=y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1]={};
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	int r=a[0];
	int h=1,l=1;
	sort(a,a+n*m,cmp);
	for(int i=0;i<m*n;i++){
		if(h%n==0) l++;
		h++;
		if(a[i]==r){
			h=h%n;
			if(h==0) h=n;
			cout<<h<<" "<<l;
			break;
		}
	}
    return 0;
}
