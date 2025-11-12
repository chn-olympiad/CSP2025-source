#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+7;
int a[N];
int b[N];
int c[N];
int d[N];
int n,k,flag=1,flag2=1;
int ans,ans1;
int check(int a[N],int b,int c){
	int ans=a[b];
	for(int i=b+1;i<=b+c-1;i++){
		ans=ans^a[i];
	}
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);	
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int sum=check(a,j,i);
			b[flag]=sum,flag++;
			
		}
	}
	for(int i=1;i<=flag;i++){
		if(b[i]==k) ans++;
	}
	for(int i=1;i<=flag2-1;i++){
		for(int j=1;j<=n;j++){
			if(c[i]<=j&&d[i]>=j&&c[i+1]<=j&&d[i+1]>=j) ans1++;
		}
	}
	cout<<(ans-ans1/6)/100+(ans-ans1/6)%100;
	return 0; 
}
