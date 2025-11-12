#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,c,b=0;
	cin>>t;
	for(int d=0;d<t;d++){
		cin>>n;
		a[100005][4]={'0'};
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
			cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			c=max(a[i][0],a[i][1]);
			b+=max(c,a[i][2]);
		}
		
	}
	cout<<b/2;
	
	return 0; 
}
