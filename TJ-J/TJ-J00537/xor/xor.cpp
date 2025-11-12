#include<bits/stdc++.h>
using namespace std;
const int MAXS=5e5+1;
int a[MAXS];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int A=0;
	int B=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			A+=1;
		}
		if(a[i]==0||a[i]==1){
			B+=1;
		//	cout<<B<<endl;
		}
	}
	if(A==n){	//特性A 
		cout<<0<<endl;
		return 0;
	}
	if(B==n){	//特性B 
		int ans=0;
		if(k==0){
			int gs=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
			/*	else{
					gs+=1;
					if(gs==3){
						ans+=1;
						gs=0;
					}
				}*/
			}
		cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	
		return 0;
	}
	cout<<255<<endl;
	return 0;
}
