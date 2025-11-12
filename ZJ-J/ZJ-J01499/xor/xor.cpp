#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005],d[500005];
bool vis[500005];
bool check(int l,int r){
	if(d[r]^d[l-1]==k)return 1;
	return 0;
}
namespace sbAB{
	int solve(){
		int now=-1,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				cnt++;
				now=-1;
			}else if(a[i]^now==k){
				cnt++;
				now=-1;
			}else{
				now=a[i];
			}
		}
		return cnt;
	}
}
namespace sbC{
	long long solve(){
		long long cnt=0;
		for(int s=1;s<=n;s++){
			for(int i=1;i+s-1<=n;i++){
				if(check(i,i+s)){
					bool flag=1;
					for(int j=i;j<=i+s;j++){
						if(vis[j]){
							flag=0;
							break;
						}
					}
					if(flag){
						cnt++;
						for(int j=i;j<=i+s;j++){
							vis[j]=1;
						}
					}
				}
			}
		}
		return cnt;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=0;
		d[i]=d[i-1]^a[i];
	}
	if(flag&&k==0||k==1){
		cout<<sbAB::solve();
	}else cout<<sbC::solve();
	return 0;
}
//#Shang4Shan3Ruo6Shui4
