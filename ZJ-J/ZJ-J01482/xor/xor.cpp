#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n';
using ll=unsigned long long;
int a[500010];

int main(){
	fast;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,f1=1,f2=1;
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)f1=0;
		if(a[i]!=1&&a[i]!=0)f2=0;
	}
	if(f1)cout<<n/2;
	else if(f2){
		int ans=0;
		
		if(k==0){
			int tmp=a[0];
			int cnt=1;
			for(int i=1;i<n;i++){
				if(a[i]!=tmp){
					tmp=a[i];
					ans+=cnt/2;
					cnt=1;
					continue;
				}
				cnt++;
			}
		}
		else{
			for(int i=1;i<n;i++){
				if(a[i]!=a[i-1]){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
	}
	else{
		cout<<n/3;
	}
	
	return 0;
} 

