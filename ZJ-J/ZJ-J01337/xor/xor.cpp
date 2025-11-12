#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],i,j,cnt,last;
bool text=1;int cnt1;
int ans,checki;
int check(int l,int r){
	ans=a[r];
	for(checki=l;checki<r;checki++)ans^=a[checki];
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1)text=0;
		if(a[i]==1)cnt1++;
	}
	
	if(text && k<2){
		if(k)cout<<cnt1;
		else cout<<cnt1/2;
	}
	
	else{
		for(i=0;i<n;i++){
			for(j=last;j<=i;j++){
				if(check(j,i)==k){
					cnt++;
					last=i+1;
					break;
				}
			}
		}
		cout<<cnt;
	}
	
	return 0;
}
//baoli
