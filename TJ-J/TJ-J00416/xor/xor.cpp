#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	int n,k;
//	cin>>n>>k;
//	int a[n+5]={}; 
//	for(int i=1;i<=n;i++){
//		
//	}
	int n,k,a,b,cnt=0;
	cin>>n>>k;
    cin>>a>>b;
    if(a==0){
    	cnt++;
	}
	if(b==0){
    	cnt++;
	}
	if(a+b==0){
    	cnt++;
	}
	cout<<cnt;
	return 0;
}
