#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000100],cnt,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			else if(a[i]==1){
				sum++;
			}
		}
		cnt=cnt+sum/2;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
			else if(a[i]==0){
				sum++;
			}
		}
		cnt=cnt+sum/2;
	}
	cout<<cnt;
	
	return 0;
} 
