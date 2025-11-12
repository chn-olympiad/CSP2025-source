#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+10;
long long n,k;
long long a[maxn]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt_1=0;
	bool flagall_1=1;
	bool flagall_10=1;
	bool flagall_255=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt_1++;
		}
		if(a[i]!=1){
			flagall_1=0;
		}
		if(a[i]!=0&&a[i]!=1){
			flagall_10=0;
		}
		if(a[i]>255){
			flagall_255=0;
		}
	}
	
	if(flagall_1==1){
		if(k==1){
			cout<<n;
			return 0;
		}else{
			cout<<n/2;
			return 0;
		}
	}
	else if(flagall_10==1){
		if(k==1){
			cout<<cnt_1;
			return 0;
		}else{
			int sum=n-cnt_1;
			for(int i=1;i<=n;){
				if(a[i]==1&&a[i+1]==1){
					sum++;
					i+=2;
				}
				i++;
			}
			cout<<sum;
			return 0;
		}
	}
	return 0;
}
