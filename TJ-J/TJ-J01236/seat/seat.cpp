#include<bits/stdc++.h>
using namespace std;
int a[10005],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]>x){
			ans++;
		}
	}
	int z=ans+1,lie,hang;
	if(z%n!=0){
		lie=z/m;
		lie++;
	}
	else if(z<=m){
		lie=1;
	}
	else{
		lie=z/m;
	}
	if(lie%2==0){
		hang=2*n-z+1; 
	}
	else{
		if(lie==1){
			hang=z;
		}
		else{
			if(z%n==0){
				hang=n;
			}
			else{
				hang=z%(n*m);
			}
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}

