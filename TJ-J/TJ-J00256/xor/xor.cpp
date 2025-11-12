#include<bits/stdc++.h>
using namespace std;
int k;
int n;
int cnt;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}if(a[1]==k)cnt++;
	else if(a[2]==k)cnt++;
	else{
		if(a[1]==a[2])cnt++;
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
}
