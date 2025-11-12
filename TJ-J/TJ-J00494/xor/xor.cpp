#include<iostream>
using namespace std;
int a[500050],sum,n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){ cin>>a[i];}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
	}
	else{
	int l=1,r=n;
	for(int r=l;r<=n;r++){
		if(a[l]==k){
	    	ans++,sum=0,l++;
			continue;
		}
		sum+=a[r]^a[r+1];
		if(sum==k){ 
			l=r+1,ans++,sum=0;
			break;
		}
		else if(sum>k){ sum-=a[l+1]^a[l],l++;}
	}
}
	cout<<ans;
	return 0;
}
