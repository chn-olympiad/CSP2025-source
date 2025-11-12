#include<bits/stdc++.h>
using namespace std;
int a[500005],ans=0,n,k;
int check(int r){
	int sum=0;
	for(int i=r;i<n;i++){
		if(sum==0){
			sum=a[i];
		}else{
			sum=sum^a[i];
		}
		if(sum==k){
			return i+1;
		}
	}
	return -1;
}
int main(){
	freopen(xor.in,"r",stdin);
	freopen(xor.out,"w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int i=0;
	while(i<n){
		if(check(i)==-1){
			i++;
			continue;
		}
		i+=check(i);
		ans++;
	}
	cout<<ans;
	return 0;
} 
