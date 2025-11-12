#include <bits/stdc++.h>
using namespace std;
long long  n,k;
const int N=5e5+10;
int arr[N];
int main (){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	bool fa=1;
	bool fb=1;
	bool fc=1;
	scanf ("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		scanf ("%d",&arr[i]);
		if (arr[i]!=1)fa=0;
		if (!(arr[i]>=0&&arr[i]<=1))fb=0;
		if (arr[i]>255)fc=0;
	}
	if (fa==1){
		if (k==0)cout <<n/2;
		else {
			cout <<n;
		} 
	}else if(fb==1){
		if (k==0){
			int s1=0,s0=0;
			for (int i=1;i<=n;i++){
				if (arr[i]==1&&arr[i+1]==1){
					s1++;
					i++;
				} 
				s0+=(arr[i]==0?1:0);
			}
			cout <<s1+s0;
		}else{
			int s1=0,s0=0;
			for (int i=1;i<=n;i++){
				if (arr[i]==0&&arr[i+1]==0){
					s0++;
					i++;
				} 
				s1+=(arr[i]==1?1:0);
			}
			cout <<s1+s0;
		}
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
