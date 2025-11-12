#include<bits/stdc++.h>
using namespace std;
int a[109];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];		
	}
	int k=a[1],cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				if(a[++cnt]==k){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}	
		else{
			for(int i=1;i<=n;i++){
				if(a[++cnt]==k){
					cout<<j<<' '<<i;
					return 0;
				}
			}			
		}
	}
	return 0;
} 
