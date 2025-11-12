#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3) cout<<0;
	else if(n==3){
		if(a[0]+a[1]+a[2]>2*a[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
