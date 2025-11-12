#include<bits/stdc++.h>
using namespace std;
int a[509090],cnt,dq=-1,c[11],d[11];
int bf(int q,int w){
	if(q==-1){
		dq=w;
		return 0;
	}
	if(w==-1){
		dq=-1;
		return 0;
	}
	if(q>127)q-=128,c[8]++;
	if(q>63)q-=64,c[7]++;
	if(q>31)q-=32,c[6]++;
	if(q>15)q-=16,c[5]++;
	if(q>7)q-=8,c[4]++;
	if(q>3)q-=4,c[3]++;
	if(q>1)q-=2,c[2]++;
	if(q>0)c[1]++;
	if(w>127)w-=128,d[8]++;
	if(w>63)w-=64,d[7]++;
	if(w>31)w-=32,d[6]++;
	if(w>15)w-=16,d[5]++;
	if(w>7)w-=8,d[4]++;
	if(w>3)w-=4,d[3]++;
	if(w>1)w-=2,d[2]++;
	if(w>0)d[1]++;
	int ans=0;
	int f1=0,f2=0;
	for(int i=8,j=128;i>1;i--,j/=2){
		if(c[i]==1)f1=1;
		if(d[i]==1)f2=1;
		if(f1==0 && f2==0)ans-=j;
	}
	for(int i=1,j=1;i<=8;i++,j*=2)if(c[i]==0 || d[i]==0)ans+=j;
	dq=ans;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)a[i]=-1,cnt++;
	}
	
	int r=1;
	while(r<=n){
		bf(dq,a[r]);
		if(dq==k){
			cnt++,dq=-1;
		}
		r++;
	}
	cout<<cnt;
	return 0;
}
