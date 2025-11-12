#include<bits/stdc++.h>
using namespace std;
int check(int a,int b){
	int s1[10],s2[10],s3[10],c=0,d=0,e=0,cnt=0;
	int pf[11]={1,2,4,8,16,32,64,128,256,512,1024};
	while(a){
		s1[c]=a%2;
		a/=2;
		c++;
	}
	while(b){
		s2[d]=b%2;
		b/=2;
		d++;
	}e=max(c,d);
	for(int i=0;i<e;i++){
		if(s1[i]==s2[i])s3[e-i-1]=0;
		else s3[e-i-1]=1;
	}
	for(int i=0;i<e;i++){
		cnt+=s3[i]*pf[e-i-1];
	}
	return cnt;
}
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j>=i&&j<=n;j++){
			if(a[i]==a[j]){
				if(i==k){
					cnt++;
				}
			}else{
				int q=check(a[i],a[i+1]);
				for(int h=i+1;h<j-1;h++){
					q=check(q,a[h+1]);
			}if(q==k){
				cnt++;
			}
   }
		}
	}
	cout<<cnt;
	return 0;
}