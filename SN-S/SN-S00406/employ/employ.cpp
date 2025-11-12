#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n,m;
int a[505];
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	char b;
    	cin>>b;
    	a[i]=b-'49';
    	cout<<a[i];
	}
	
	return 0;
}
