#include<bits/stdc++.h>
using namespace std;
int a[10005];
int ai,bi,ci;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	long long n;
	int mx;
    cin>>t;
    while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			mx=ai=bi=ci=0;
			cin>>ai>>bi>>ci;
			mx=max(ai,max(bi,ci));
			a[i]=mx;
		}
		for(int i=1;i<=n;i++){
			a[i]=a[i]+a[i-1];
		
		}	
		cout<<a[n];
    }
	return 0;
}



	
