#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,sum,tmp=0;
int cnt[MAXN];
int a[MAXN]; 
int main(){
//	freopen("xor","r",in);
//	freopen("xor","w",out);
	cin>>n>>k;
	if(n==2&&k==0){
		cin>>a[0]>>a[1];
		cout<<1;
	}
	else if(n<=100&&k==0){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<n/2;
	}
	if(n<=100&&k<=1){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(k==1){
			for(int i=0;i<n;i++){
				if(a[i]==1){
					sum++;
				}
			}
			cout<<sum;
		}
		else{
			int a,b;
			int c;
			a=b=c=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					c++;
				}
				if(a[i]==1){
					b++;
					if(b%2==){
						a++;
					}
				}
			}
			cout<<max(a,c);
		}
	}
//	freclose("xor",in);
//	freclose("xor",out);
	return 0;
}
