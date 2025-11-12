#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,cj[105],R;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
		if(i==1) R=cj[i];
	}
	sort(cj+1,cj+n*m+1,cmp);
	int l=1,r=n*m;
	while(l<r){
		int mid=(l+r+1)/2;
		if(cj[mid]>=R) l=mid;
		else r=mid-1;
	}
	int lie=(l+n-1)/n;
	int hang;
	if(lie%2==0){
		hang=((l%n)!=0?n-(l%n)+1:1);
	}
	else{
		hang=((l%n)!=0?l%n:n);
	}
	cout<<lie<<" "<<hang;
	return 0;
}
