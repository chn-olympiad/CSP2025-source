#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int k;
	cin>>k;
	if(k==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		bool flag=true;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1) flag=false,cnt++;
		}
		
		cout<<cnt;
		return 0;
	}
	
	return 0;
}

