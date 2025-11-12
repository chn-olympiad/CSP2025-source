#include<bits/stdc++.h>
using namespace std;
const long long N=1e5*5+5;
long long n,k,a[N],ans,no[N],sum,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			no[i]=1;
		}
	}
	for(int i=1;i<n;i++){
		if(no[i]||no[i+1]){
			continue;
		}else{
			for(int j=i+1;j<=n;j++){
				f=0;
				sum=a[i];
				for(int q=i+1;q<=j;q++){
					if(no[q]||f){
						f=1;
						break;
					}else{
						sum=sum^a[q];
					}
				}
				if(f){
					break;
				}else if(sum==k){
					ans++;
					for(int q=i;q<=j;q++){
						no[q]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
