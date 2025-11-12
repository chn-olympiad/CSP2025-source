#include<bits/stdc++.h>
using namespace std;
int n,k,a[500020]={0},b[500020]={0},ans=0,l,r,len;
void check(){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		if(b[i]==-1){
			//cout<<"o"<<" ";
			return;
		}
		sum=sum^a[i];
		//cout<<sum<<" ";
	}
	if(sum==k&&b[l]!=-1){
		//cout<<"ll ";
		ans++;
		for(int i=l;i<=r;i++){
			b[i]=-1;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=1,len=1;
	for(;len<=n;len++){
		for(l=1,r=l+len-1;l<=n-len+1;l++,r=l+len-1){
			//cout<<l<<"p ";
			check();
		}
	}
	cout<<ans;
}
