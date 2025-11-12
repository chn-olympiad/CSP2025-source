#include<bits/stdc++.h>
using namespace std;
int m,n,s,a1,sl,y1;
int x,y;
int  a[100005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	s=n*m;
	cin>>a[1];
	a1=a[1];
	for(int i=2;i<=s;i++){
		cin>>a[i];
	}
	for(int i=1;i<=s;i++){
		for(int j=i;j<=s;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=s;i++){
		if(a[i]==a1){
			sl=i;
			break;
		}
	}
	x=floor(sl/n)+1;
	y1=sl%n;
	if(x%2==1){
		if(y1==0){
			y=n;
		}else{
			y=y1;
		}
	}else{
		if(y1==0){
			y=1;
		}else{
			y=n-y1+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
