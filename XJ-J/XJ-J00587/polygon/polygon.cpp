#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int arr[N],s[N];
int arr_max(int l,int r){
	int ans=arr[l];
	for(int a=l;a<=r;a++){
		ans=max(ans,arr[a]);
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n; 
	int max_n=0;
	for(int a=1;a<=n;a++){
		cin>>arr[a];
		max_n=max(max_n,arr[a]) ;
		s[a]+=arr[a];
	}
    
    if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3&&(arr[1]+arr[2]+arr[3])>2*max(arr[1],max(arr[2],arr[3]))){
		cout<<1;
		return 0;
	}
	long long int ans=0;
	for(int a=3;a<=n;a++){
		for(int b=1;b<=a-3+1;b++){
			if(s[a]-s[b-1]>2*arr_max(b,a)){
				ans++;
				ans%=998244353;
			}
		}
	}
	cout<<ans;

	return 0;
}
