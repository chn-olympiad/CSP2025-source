#include<bits/stdc++.h>
using namespace std;
int n,m,arrn[100005],sum1 = 0,lc1 = 1,ds[100000005],sum0 = 0,tg =0,ok1 = 1,ok2 = 1,lj = 0;
string x;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m>>x;
for(int i = 1;i<=n;i++){
	cin>>arrn[i];
}
for(int i = 0;i<=n;i++){
	if(x[i]=='1'){
		sum1++;
	}
}
sort(arrn+1,arrn+n+1);
if(sum1==m){
	for(int i = 1;i<=m;i++){
		lc1*=i;
	}
	cout<<lc1;
	return 0;
}
int l = x.size();
for(int i = 0;i<l;i++){
	ds[i+1] = x[i]-'0';	
}
for(int i = 1;i<=n;i++){
	if(ds[i]==1&&arrn[i]>sum0){
		tg++;
		if(tg==m){
			for(int i = 1;i<=m;i++){
				ok1*=i;
			} 
		}
	}else if(arrn[i]<=sum0){
		for(int i= 1;i<=n-m;i++){
			ok2*=i;
		}
	}else{
		arrn[n-lj]=arrn[i];
		arrn[i] = 0;
		lj++;
		sum0++;
	}	
}
cout<<(ok1*ok2)%998244353;


	return 0;
}

