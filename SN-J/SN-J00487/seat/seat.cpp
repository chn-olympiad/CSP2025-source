//西安经开第五学校
//朱梓豪
//SN-J00487 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],cc,n1,m1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		b[i]=a[0];
	}
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]>b[i]){
			cc++;
		}
		n1=cc/n+1; 
		if((cc/m)%2==0){
			m1=cc%m+1;
		}
		else{
			m1=m-cc%m;
		}
	}
	cout<<n1<<" "<<m1;
	return 0;
}
