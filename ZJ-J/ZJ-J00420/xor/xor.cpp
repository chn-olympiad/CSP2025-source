#include<bits/stdc++.h>
using namespace std;
int n,k,y=0;
int a[500007],r[1000001],l[1000001],dp[1000001],rr[1000001],ll[1000001];
bool cheak(int o,int j){
	for(int i=1;i<=o;i++){
		if((r[j]<=rr[i]&&r[j]>=ll[i])||(l[j]<=rr[i]&&l[j]>=ll[i]))
		return false;
		if((r[j]>=rr[i]&&rr[i]<=l[j])||(l[j]<=ll[i]&&r[j]>=ll[i]))
		return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			f=1;
		}
	}
	if(f==1){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int x=0;
			for(int l=j;l<=j+i-1;l++){
				if(l==j){
					x=a[l];
				}else{
				x=x^a[l];	
				}
			}
			if(x==k){
				l[++y]=j;
				r[y]=j+i-1;
			}
		}
	}
	int t=0,ans=0;;
	for(int i=1;i<=y;i++){
		t=1;int o=0;
		ll[++o]=l[i];
		rr[o]=r[i];
		for(int j=i+1;j<=y;j++){
			if(cheak(o,j)){
				ll[++o]=l[j];
				rr[o]=r[j];
				t++;
			}
		}
		memset(ll,0,sizeof(ll));
		memset(rr,0,sizeof(rr));
		ans=max(ans,t);
	}
	cout<<ans<<endl;
	}else{
		if(k==1){
			int t=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					t++;
				}
			}
			cout<<t<<endl;
		}else{
			int t=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					t++;
				}
				if(a[i]==1&&a[i-1]==1){
					t++;
				}
			}
			cout<<t<<endl;			
		}
	}
	return 0;
}