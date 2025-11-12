#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
bool pendA=false,pendB=false;
int n,k;
int a[N];

void PA(){
	int sum=0;
	int ad=2;
	while(ad<=n){
		sum+=(n-ad+1);
		ad+=2;
	}
	cout<<sum;
	return;
}

void PB(){
	int sum=0;
	int cnt0=0,cnt1=0;
	int sum0[N],sum1[N];
	sum0[0]=0;sum1[0]=0;
	for(int i=1;i<=n;i++){
		sum0[i]=sum0[i-1]+(a[i]==0);
		sum1[i]=sum1[i-1]+(a[i]==1);
		cnt0+=(a[i]==0);
		cnt1+=(a[i]==1);
	}
	if(k==0){
		sum+=cnt0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j=n;j++){
				int s0=sum0[j]-sum0[i-1];
				int s1=sum1[j]-sum1[i-1];
				s0%=2;s1%=2;
				if(s0==s1){
					sum++;
				}
			}
		}
		cout<<sum;
		return;
	}
	else if(k==1){
		sum+=cnt1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int s0=sum0[j]-sum0[i-1];
				int s1=sum1[j]-sum1[i-1];
				s0%=2;s1%=2;
				if(s1!=s0){
					sum++;
				}
			}
		}
		cout<<sum;
		return;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)pendA=true;
		if(a[i]>1)pendB=true;
	}
	if(!pendA&&k==0){//A
		PA();return 0;
	}
	
	if(!pendB&&k<=1){//B
		PB();return 0;
	}
	
	return 0;
}
