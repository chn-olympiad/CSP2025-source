#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n,a[100005][5],s,m[100005],b[10];
cin>>t;
while(t<=0){
	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>a[i][3];
		for(int j=0;j<=2;j++){
	    if(a[i][j]>a[i][j-1]&&b[j]<=n/2){
	    	m[i]=a[i][j];
	    	b[j]++;
	    	s+=m[i];
		}
		}
	}
	cout<<s<<'\n';
	t--; 
}

	return 0;
}