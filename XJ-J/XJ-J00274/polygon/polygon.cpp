#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;	
	int m[n];
	for(int i=0;i<n;i++)
 		cin>>m[i]; 
 	if(n>=3)
 		cout<<1;
 	else 
 		cout<<0;
	return 0;
}
