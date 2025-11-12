#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[1005],mb;
bool cmp(int cmp1,int cmp2){
	return cmp1>cmp2;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	mb=a[1];
	sort(a+1,a+n*m+1,cmp);
	int wz=1;
	while(a[wz]!=mb){
		wz++;
	}
	int lie=(wz-1)/n+1,hang;
	if(lie%2==1){
		hang=wz-(lie-1)*n;
	}
	else{
		hang=n-(wz-(lie-1)*n)+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
