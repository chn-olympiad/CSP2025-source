//SN-J00818  甘智中  西安市雁塔区第一学校 
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l; 
long long a[100005],sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+n*m+1);
	k=n*m;
	
	for(int i=1;i<=m;i++){
		sum+=1;
		
		if(sum%2==1){
			
			for(int j=1;j<=n;j++){
				if(l==a[k]){
					cout<<i<<" "<<j;
					return 0;
				}
				k=k-1;
			}
		}
		else{
			
			for(int j=n;j>=1;j--){
				if(l==a[k]){
					cout<<i<<" "<<j;
					return 0;
				}
				k=k-1;
			}
		}
		
	}
	
	
	
	return 0;
}
