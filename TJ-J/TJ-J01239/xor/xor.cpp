#include<bits/stdc++.h>
using namespace std;
int huo(int a,int b){
	int k=0,i;
	if(a>b){
		int h=a;
		a=b;
		b=h;
	}
	if(a==0){
		return b;
	}
	for(i=2;i<=b;i*=2){
		int a1=a%i;
		int b1=b%i;
		if(a1!=b1){
			k+=i/2;
		}
		a=a-a1;
		b=b-b1;
	}
	if(a%i!=b%i) k+=i/2;
	return k;
}
int main(){
	freopen("xor3.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[1]=a[1];
		for(int j=2;j<=i;j++){
			b[j]=huo(b[j-1],a[j]);
		}
	}
	long long num=0,mj=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j&&a[i]==k&&i>mj){
				num++;
				mj=j;
			}
			else{
				if(i==1&&b[j]==k&&i>mj){
					num++;
					mj=j;
				}
				else{
					if(huo(b[j],b[i-1])==k&&i>mj){
						num++;
						mj=j;
					}
				}
			}
		}
	}
	cout<<num;
	return 0;
}
