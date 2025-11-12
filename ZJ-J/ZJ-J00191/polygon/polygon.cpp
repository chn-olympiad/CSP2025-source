#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e7+5;
long long n,a[MAXN],f[MAXN],ans,s[MAXN],h[MAXN],l;
int md(long long h){
	if(h>998244353) return h-998244353;
	else return h;
}
void dg(int b,int m){
	if(m==0){
		for(int i=0;i<n;i++){
			if(f[i]==1){
				//cout<<a[i]<<" ";
				s[l]+=a[i];
				if(h[l]<a[i]){
					h[l]=a[i];
				}
			}
		}
		//cout<<endl;
		l++;
		return;
	}
	else{
		for(int i=b;i<n;i++){
			if(f[i]==0){
				f[i]=1;
				dg(i+1,m-1);
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<n-1;j++){
			memset(f,0,sizeof(f));
			//ans+=md(dp(j,i));
			dg(j,i);
		}
	}
	for(int i=0;i<l;i++){
		for(int j=i+1;j<l;j++){
			if(s[i]==s[j]){
				s[i]=-1;
			}
		}
	}
	for(int i=0;i<l;i++){
		//cout<<s[i]<<" "<<h[i]<<endl;
		if(s[i]>h[i]*2){
			ans=md(ans+1);
		}
	}
	cout<<ans;
	return 0;
	
}

