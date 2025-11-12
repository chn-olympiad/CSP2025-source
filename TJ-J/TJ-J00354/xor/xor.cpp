#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
//string ejz(long long a){
//	string s,ss;
//	long long cnt=0;
//	while(a>0){
//		s[++cnt]=
//		a/=2;
//	}
//	for(int i=1;i<=cnt;i++){
//		cout<<s[i];
//	}
//	cout<<endl; 
//	for(int i=cnt;i>=1;i--){
//		ss[cnt-i]=s[i];
//	}
//	for(int i=0;i<cnt;i++){
//		cout<<ss[i];
//	}
//	return ss;
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			flag=0;
		}
	}
	if(k==0){
		if(flag==1){
			cout<<n/2; 
		}else{
			long long ans=0,num=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans+=num/2;
					num=0;
					ans++;
				}else{
					num++;
				}
			} 
			cout<<ans;
		}
	}else if(k==1){
		if(flag==1){
			cout<<n;
		}else{
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			} 
			cout<<ans;
		}
	}
	return 0;
} 
