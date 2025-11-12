#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int dp[500010][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	int last=0;
	for(int i=1;i<=n;i++){
	    long long sum=0;
	    for(int j=i;j>=last+1;j--){
	    	sum^=a[j];
	    	if(sum==k){
	    		cnt++;
	    		dp[cnt][0]=j;
	    		dp[cnt][1]=i;
	    	    last=j;
	    		break;
			}
		}
    }
    int ans=0;
    int end=0;
    for(int i=1;i<=cnt;i++){
   	    if(end<dp[i][0]){
   		    ans++;
   		    end=dp[i][1];
   		}
	}
	cout<<ans;
	return 0;
}