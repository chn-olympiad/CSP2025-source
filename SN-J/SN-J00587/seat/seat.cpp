#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int num[105]; 
int main(){
    int n,m;
    cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];	
	}
    cout<<n<<m;
	return 0;
} 
