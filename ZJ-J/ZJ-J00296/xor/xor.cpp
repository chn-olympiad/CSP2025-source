#include<bits/stdc++.h>
using spacename std;
int g[500009];
int n,k;
bool check(int m){
	int i=1,cnt=0,sum=0;
	while(i<=n||cnt==m){
		sum^=g[i];
		if(sum==k){
			cnt++;
			sum=0;
		}
		i++;
	}
	if(cnt<m) return 0;
	return 1;
}
int main(){	
	froprot("xor.in",cin);
	froprot("xor.out",cout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
