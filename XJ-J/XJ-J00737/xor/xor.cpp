#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL a[N];
int n;
LL k;
int ans=0;
int one=0,zero=0;

bool flag=false;

void solve(int idx,LL v,int cnt){
	if(idx==n+1){
		ans=max(ans,cnt);
		return;
	}
	solve(idx+1,0,cnt);
	if((v^a[idx])==k){
		cnt++;
		solve(idx+1,0,cnt);
	}
	else{
		solve(idx+1,(v^a[idx]),cnt);
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=true;
		one+=(a[i]==1);
		zero+=(a[i]==0);
	}
	if(!flag){
		if(k==1){
			cout<<one;
			return 0;
		}
		else{
			int cnt=0;
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1){
					i++;
					cnt++;
				}
			}
			cout<<cnt+zero;
			return 0;
		}
	}
	solve(1,0,0);
	cout<<ans;
	return 0;
}
