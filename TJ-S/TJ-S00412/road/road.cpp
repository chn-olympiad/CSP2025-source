#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,k,value=0;
	for(int i=0;i<m;i++){
		int w1,v1,u1;
		cin>>w1>>v1>>u1;
		value+=u1;
	}
	cout<<value;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

