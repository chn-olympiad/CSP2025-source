#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main(){
	int a[100005],b,n,c,k,f[10005],cnt=0,need[10005];
	cin>>n>>k;
	int sq=1;
	while(sq<=k){
		sq*=2;
	}
	memset(f,1,sizeof f);
	for(int i=0;i<n;i++){
		cin>>a[i];
		
		if(a[i]==k){
			cnt++;
			f[i]=0;
		}
		if(a[i]>sq&&k!=0){
			a[i]=a[i]%sq;
		}
	}
	int ne=0,flag=0;
	
	for(int i=0;i<n;i++){
		if(f[i]==0){
			continue;
			memset(need,0,sizeof need);
		}
		flag=0;
		for(int j=0;j<ne;j++){
			if(need[j]==a[i]){
				cnt++;
				flag=1;
			}
			
		}
		if(flag==0){
			need[ne]=(a[i]^k);
			ne++;
		}
		
	}
	cout<<cnt;
	return 0;
}
