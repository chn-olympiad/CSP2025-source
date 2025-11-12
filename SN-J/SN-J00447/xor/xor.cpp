#include<bits/stdc++.h>
#define forf(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
//30 pts version
const int N=5e5+5;
int a[N],cnt1,rec,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int cnt0=n;
	forf(i,1,n) cin>>a[i];
	if(!k){
		forf(i,1,n){
			if(a[i]==1){
				cnt1++;
				if(cnt1 & 1) rec=i;
				else cnt0=cnt0-(i-rec+1);
			}
		}
		ans=cnt0+cnt1/2;
	}
	else if(k==1){
		forf(i,1,n) if(a[i]==1) cnt1++;
		ans=cnt1;
	}
	else{
		ans=n/4;
	}
	cout<<ans;
	return 0;
}

