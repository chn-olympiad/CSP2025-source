#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int ans=0;
	int s=n*m;
	int a[s];
	for(int i=1;i<=s;i++){
		cin>>a[i];
	} 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x=a[1];
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			if(a[i]>a[j]){
				int f=a[j];
				a[j]=a[i];
				a[i]=f;
			}
		} 
	} 
	for(int i=1;i<=s;i++){
		if(a[i]==x)
		{
			ans=i;
			break;
		}
	} 
	if(ans%m>0)
		if(ans/m%2+1==1){
			cout<<ans/m+1<<" "<<ans%m;
			return 0;
		}
	if(ans%2==0 || ans==s){
		cout<<ans/m<<" "<<m-ans%m;
		return 0;
	}
	if(ans%2>1 && ans%2<m)
		if(ans/m%2+1==1){
			cout<<ans/m+1<<" "<<m-ans%m;
			return 0;
			}
	return 0;
}
