#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],t,tx;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int l=1,r=n*m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]==t){
			tx=mid;
			break;
		}else if(a[mid]<t){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	int hang=tx%(2*n);
	int lie=tx/n+(tx%n!=0)*1;
	if(hang>n){
		hang=n-(hang-n)+1;
	}
	cout<<lie<<" "<<hang;
}
