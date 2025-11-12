#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int a[N],jj[N],cnt=0,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=a[i];
		if(ans==k){
			if(i>jj[l]){
				cnt++;
				jj[++l]=i;
			}
			if(i<=jj[l]){
				jj[l]=i;
			}
			continue;
		}
		for(int j=i+1;j<=n;j++){
			ans^=a[j];
			if(ans==k){
				if(i>jj[l]){
					cnt++;
					jj[++l]=j;
				}
				if(j<=jj[l]){
					jj[l]=j;
				}
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
