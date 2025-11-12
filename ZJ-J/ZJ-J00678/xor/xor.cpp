#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,k,ans;
int a[N],le[N],ri[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}
	}
	int id=1;
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			int sum=a[l];
			for(int i=l+1;i<=r;i++){
				if(l+1==r) break;
				if(a[i]==-1) break;
				sum=sum^a[i];
				if(sum==k){
					le[id]=l;
					ri[id]=i;
					id++;
					ans++;
					break;
				}
			}
		}
    }//所有区间中异或和为K的组数 
    cout<<ans;
	return 0;
}
