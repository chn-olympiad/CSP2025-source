#include<bits/stdc++.h>
using namespace std;
long long a[11001],m,n,scorer,k=1,seats[1000][1000];
bool cmp(long long x,long long y){
	if(x>y) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m*n;i++) cin>>a[i];
	scorer=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=m;i++){
		if(i%2==1)
		  for(long long j=1;j<=n;j++){
		  	if(a[k]==scorer){
			  cout<<i<<' '<<j<<endl;	
			  return 0;
			}
			k++;
		  }
			
		else
		  for(long long j=n;j>=1;j--){
		  	if(a[k]==scorer){
			  cout<<i<<' '<<j<<endl;	
			  return 0;
			}
			k++;
		  }
			
	}
	return 0;
}
