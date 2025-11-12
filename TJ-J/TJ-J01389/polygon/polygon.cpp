#include <bits/stdc++.h> 

using namespace std;
int a[5005];
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0,cnt1=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			f=0;
		}
		if(a[i]==1){
			cnt++;
		}
		if(a[i]==0){
			cnt1++;
		}
	}
	if(f){
		if(cnt==1||cnt==2){
			cout<<0;
			return 0;
		}
		cout<<cnt1+cnt-2;
		return 0;
	}
	if(n<=2){
		cout<<0;
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
			return 0;
		}
		cout<<0;
	}
	if(n==4){
		int ans=0;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) ans++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))) ans++;
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[4],a[3]))) ans++;
		if(a[4]+a[2]+a[3]>2*max(a[4],max(a[2],a[3]))) ans++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))) ans++;
		cout<<ans;
		return 0;
	}
	if(n==5){
		int ans=0;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) ans++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))) ans++;
		if(a[1]+a[2]+a[5]>2*max(a[1],max(a[2],a[5]))) ans++;
		
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[4],a[3]))) ans++;
		if(a[1]+a[3]+a[5]>2*max(a[1],max(a[5],a[3]))) ans++;
		
		if(a[1]+a[4]+a[5]>2*max(a[1],max(a[5],a[4]))) ans++;
		
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[4],a[3]))) ans++;
		if(a[2]+a[3]+a[5]>2*max(a[2],max(a[5],a[3]))) ans++;
		if(a[5]+a[2]+a[4]>2*max(a[5],max(a[4],a[2]))) ans++;
		
		if(a[5]+a[3]+a[4]>2*max(a[5],max(a[4],a[3]))) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))) ans++;
		if(a[1]+a[2]+a[3]+a[5]>2*max(a[1],max(a[2],max(a[3],a[5])))) ans++;
		if(a[1]+a[2]+a[4]+a[5]>2*max(a[1],max(a[2],max(a[4],a[5])))) ans++;
		if(a[1]+a[3]+a[4]+a[5]>2*max(a[1],max(a[4],max(a[3],a[5])))) ans++;
		
		if(a[5]+a[2]+a[3]+a[4]>2*max(a[5],max(a[2],max(a[3],a[4])))) ans++;
		
		if(a[1]+a[5]+a[2]+a[3]+a[4]>2*max(a[5],max(a[2],max(a[3],max(a[4],a[1]))))) ans++;
		cout<<ans;
		return 0;
	}
	if(n==6){
		int ans=0;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) ans++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))) ans++;
		if(a[1]+a[2]+a[5]>2*max(a[1],max(a[2],a[5]))) ans++;
		if(a[1]+a[2]+a[6]>2*max(a[1],max(a[2],a[6]))) ans++;
		
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[4],a[3]))) ans++;
		if(a[1]+a[3]+a[5]>2*max(a[1],max(a[5],a[3]))) ans++;
		if(a[1]+a[3]+a[6]>2*max(a[1],max(a[6],a[3]))) ans++;
		
		if(a[1]+a[4]+a[5]>2*max(a[1],max(a[5],a[4]))) ans++;
		if(a[1]+a[4]+a[6]>2*max(a[1],max(a[6],a[4]))) ans++;
		
		if(a[1]+a[5]+a[6]>2*max(a[1],max(a[6],a[5]))) ans++;
		
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[4],a[3]))) ans++;
		if(a[2]+a[3]+a[5]>2*max(a[2],max(a[5],a[3]))) ans++;
		if(a[2]+a[3]+a[6]>2*max(a[2],max(a[6],a[3]))) ans++;
		
		if(a[5]+a[2]+a[4]>2*max(a[5],max(a[4],a[2]))) ans++;
		if(a[6]+a[2]+a[4]>2*max(a[6],max(a[4],a[2]))) ans++;
		
		if(a[5]+a[2]+a[6]>2*max(a[5],max(a[6],a[2]))) ans++;
		
		if(a[5]+a[3]+a[4]>2*max(a[5],max(a[4],a[3]))) ans++;
		if(a[6]+a[3]+a[4]>2*max(a[6],max(a[4],a[3]))) ans++;
		
		if(a[5]+a[3]+a[6]>2*max(a[5],max(a[6],a[3]))) ans++;
		
		if(a[5]+a[4]+a[6]>2*max(a[5],max(a[6],a[4]))) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))) ans++;
		if(a[1]+a[2]+a[3]+a[5]>2*max(a[1],max(a[2],max(a[3],a[5])))) ans++;
		if(a[1]+a[2]+a[3]+a[6]>2*max(a[1],max(a[2],max(a[3],a[6])))) ans++;
		
		if(a[1]+a[2]+a[4]+a[5]>2*max(a[1],max(a[2],max(a[4],a[5])))) ans++;
		if(a[1]+a[2]+a[4]+a[6]>2*max(a[1],max(a[2],max(a[4],a[6])))) ans++;
		
		if(a[1]+a[2]+a[5]+a[6]>2*max(a[1],max(a[2],max(a[5],a[6])))) ans++;
		
		
		if(a[1]+a[3]+a[4]+a[5]>2*max(a[1],max(a[4],max(a[3],a[5])))) ans++;
		if(a[1]+a[3]+a[4]+a[6]>2*max(a[1],max(a[4],max(a[3],a[6])))) ans++;
		
		if(a[1]+a[3]+a[6]+a[5]>2*max(a[1],max(a[6],max(a[3],a[5])))) ans++;
		
		if(a[1]+a[4]+a[6]+a[5]>2*max(a[1],max(a[6],max(a[4],a[5])))) ans++;
		
		if(a[5]+a[2]+a[3]+a[4]>2*max(a[5],max(a[2],max(a[3],a[4])))) ans++;
		if(a[6]+a[2]+a[3]+a[4]>2*max(a[6],max(a[2],max(a[3],a[4])))) ans++;
		
		if(a[5]+a[6]+a[3]+a[4]>2*max(a[5],max(a[6],max(a[3],a[4])))) ans++;
		
		if(a[1]+a[5]+a[2]+a[3]+a[4]>2*max(a[5],max(a[2],max(a[3],max(a[4],a[1]))))) ans++;
		if(a[1]+a[6]+a[2]+a[3]+a[4]>2*max(a[5],max(a[2],max(a[3],max(a[4],a[1]))))) ans++;
		
		if(a[1]+a[5]+a[2]+a[3]+a[6]>2*max(a[5],max(a[2],max(a[3],max(a[6],a[1]))))) ans++;
		
		if(a[1]+a[5]+a[2]+a[6]+a[4]>2*max(a[5],max(a[2],max(a[6],max(a[4],a[1]))))) ans++;
		
		if(a[6]+a[5]+a[2]+a[3]+a[4]>2*max(a[5],max(a[2],max(a[3],max(a[4],a[6]))))) ans++;
		
		if(a[6]+a[5]+a[2]+a[3]+a[4]+a[1]>2*max(a[5],max(a[2],max(a[3],max(a[4],max(a[6],a[1])))))) ans++;
		cout<<ans;
		return 0;
	}
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	return 0;
}
