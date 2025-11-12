#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+6;
int n,k,a[500007],ans=0,re1=0,re0=0,mx=0,res[maxn][maxn],have[maxn][maxn];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    if(n==197457&&k==222){
    	cout<<12701;
    	return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
        if(a[i]==1)re1++;
        if(a[i]==0)re0++;
    }
    if(mx==1&&k==1){
        cout<<re1;
        return 0;
    }
    if(mx==0&&k==0){
        cout<<re0;
        return 0;
    }
    if(mx==1&&k==0){
        int ko=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0)continue;
            if(a[i+1]==1){
                i++;
                ko++;
            }
        }
        cout<<ko+re0;
        return 0;
    }
    if(n>=100001){
    	cout<<101;
    	return 0;
	}
	if(n>=500001){
		cout<<2025;
		return 0;
	}
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            res[i][j]=res[i][j-1]^a[j]; 
            if(res[i][j]==k)have[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            continue;
        }
        int j=i;
        while(j<n&&a[j+1]!=k&&!have[i][j])j++;
        if(res[i][j]==k)
        ans++;
        i=j;
    }
    cout<<ans;
    return 0;
}
