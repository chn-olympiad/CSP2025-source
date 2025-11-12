#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
short p[501];
long long arr[501]={1,1},end;
void a(int n){
	for(int i=1;i<n;i++){
		arr[i]*=i;
	}
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	a(n);
	for(int i=0;i<n;i++)cin>>p[i];
	if(n==m)end=arr[n];
	cout<<end%998244353;
	fclose(stdin);
	fclose(stdout); 
return 0;
}

