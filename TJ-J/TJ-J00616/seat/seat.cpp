#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b;
	cin>>n>>m;
	int nn=n*m;
	for(int i=1;i<=nn;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+nn+1);
	reverse(a+1,a+nn+1);
	int i1;
	for(int i=1;i<=nn;i++){
		if(a[i]==b){
			i1=i;
			break;
		}
	}int h,l;
	h=(i1/n);
	l=i1%n;
    if(l!=0){
    	h++;
	}
	if(l==0){
		l=n;
	}if(h%2==0){
		l=n+1-l;
	}
	cout<<h<<' '<<l;
	return 0;
}
