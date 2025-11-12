#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	cin>>x;
	s+=i;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
