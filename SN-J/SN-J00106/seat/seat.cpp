//刘庭宇 西安市高新第一学校 SN-J00106
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010],b[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int js;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		if(i==1)js=a[i];
	}
	sort(a+1,a+n*m+1);
	int ls=1;
	for(int i=n*m;i>=1;i--){
		b[ls]=a[i];
		ls++;
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]==js){
			ls=i;
			break;
		}
	}
	int gb=ls/n;
	if(ls%n!=0)gb++;
	if(gb%2==1){
		cout<<gb<<' '<<ls-(gb-1)*n;
	}
	else cout<<gb<<' '<<n-(ls-(gb-1)*n)+1;
	return 0;
}
