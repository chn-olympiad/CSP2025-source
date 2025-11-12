#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,s=0;
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<"1 1";
	} 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) s=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	int f=0;
	for(int i=1,j=1,k=1;j<=m;k++){
		
		
		if(f==1)
			if((i==n||i==1)){
				j++;
				k++;
			}
		if(a[k]==s){
			cout<<j<<" "<<i<<endl;
			return 0;
		}
		if(j%2==0){
			i--;
		}
		else{
			i++;
		}
		f=1;
	}
	//I am AK CSP-J
	return 0;
}

