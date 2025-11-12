#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll A[10005];
ll a,b;//a1,b0
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;

	for(int i=1;i<=n;i++){
		cin>>A[i];
		if(A[i])a++;
		else b++;
	}	
	if(!k){
		cout<<max(a/2+b/2,b);
	}else{
		cout<<max(min(a,b),a);
	}
	return 0;
}
