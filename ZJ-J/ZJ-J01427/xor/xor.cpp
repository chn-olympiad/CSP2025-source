#include<bits/stdc++.h>
using namespace std;
int n,k,a[1001000];
int ans;
bool check(int l,int r){
	if(l>r) return 0;
	int cnt=a[l];
	for(int i=l+1;i<=r;i++){
		cnt=cnt^a[i];
	}
	if(cnt==k){
//		cout<<l<<' '<<r<<endl;
		return 1;	
	} 
	else{
		return check(l+1,r);
	}    
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=1;
	for(int i=1;i<=n;i++){
//		cout<<"*"<<l<<" "<<i<<endl;
		if(check(l,i)==1){
			ans++;
			l=i+1;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
