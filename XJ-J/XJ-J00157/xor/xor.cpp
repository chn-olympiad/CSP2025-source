#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,ans=0;cin>>n>>k;	
    vector<int> a(n+5),b(n+5); 
    int maxn=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=a[i]^k;
    	maxn=max(maxn,a[i]);
	}
	if(maxn==0){
		if(k==0){
			cout<<n;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(maxn==1){
		int sum0=0,sum1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) sum0++;
			else sum1++;
		}
		if(k==1){
		    if(sum1==n){
			    cout<<n;
			    return 0;
		    }
		    else if(sum0==n){
			    cout<<0;
			    return 0;
		    }
		    else{
		    	cout<<sum1;
		    	return 0;
			}
		}
		else{
			if(sum1==n){
			    cout<<n/2;
			    return 0;
		    }
		    else if(sum0==n){
			    cout<<n;
			    return 0;
		    }
		    else{
		    	int sum2=0;
		    	for(int i=1;i<n;i++){
		    		if(a[i]==1&&a[i+1]==1){
		    			sum2++;
					}
				}
				cout<<sum2+sum0;
		    	return 0;
			}
		}
	}
	int l=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;l++;
			continue;
		}
		else if(b[l]==a[i]&&l!=i){
			ans++;l=i+1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
