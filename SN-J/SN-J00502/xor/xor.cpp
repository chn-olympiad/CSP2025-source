#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,flag1=1,flag2=1,flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=0;
		}
		if(a[i]>1){
			flag2=0;
		}
	}
	if(flag1){
		if(k==1){
			cout<<n;
			return 0;
		}
		cout<<n/2;
		return 0;
	}
	else if(flag2){
		if(k==0){
			for(int i=1;i<n;i++){
				if(flag){
					flag=0;
					continue;
				}
				if(a[i]==0){
					cnt++;
				}
				if(a[i]==1&&a[i+1]==1){
					flag=1;
					cnt++;
					continue;
				}
			}
			if(a[n]==0)cnt++;
			cout<<cnt;
			return 0; 
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}
