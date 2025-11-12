#include<bits/stdc++.h> 
using namespace std;
long long n,m,c,s,i,j,k,p,q;
int a[10010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(k==0&&a[0]==a[n-1]&&a[0]==1){
		cout<<n/2;
		return 0;
	}
	if(a[0]==0&&a[n-1]==1){
		for(i=0;i<n;i++){
			if(a[i]==1){
				s=i;
				break;
			}
		}
		if(k==0){
			cout<<((s+1)/2)+((n-s+1)/2);
			return 0;
		}else if(k==1){
			cout<<min(s+1,n-s+1);
			return 0;
		}
	}
	for(i=0;i<n;i++){
		if(a[i]==k){
			c++;
		}if(c!=0&&a[i]!=k){
			break;
			
		}
	}
	cout<<c;
	return 0;
}
