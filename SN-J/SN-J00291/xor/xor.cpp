#include<bits/stdc++.h>
using namespace std;
int n,k,a[100002];
int cnt0=0,cnt1=0,cntelse=0;
int iif(){
	for(int i=0;i<n;i++){
		if(a[i]==0){
			cnt0++;
		}else if(a[i]==1){
			cnt1++;
		}else{
			cntelse++;
		}
	}
	if(cntelse==0&&cnt0==0){
		return 1;
	}else if(cntelse==0){
		return 2; 
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int now=iif();
	if(k==0&&now==1){
		cout<<n/2;
	}else if(k<=1&&now==2){
		int ans;
		if(k==0){
			ans=cnt0;
			int cnt=0;
			for(int i=0;i<n-1;i+=2){
				if(a[i]==a[i+1]&&a[i]==1){
					cnt++;
				}
			}
			ans+=cnt;
		}else{
			ans=cnt1;
		}
		cout<<ans;
	}
	return 0;
}
/*100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1*/
