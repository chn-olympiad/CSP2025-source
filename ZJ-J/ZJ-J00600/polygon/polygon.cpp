#include<bits/stdc++.h>
using namespace std;
long long int n,maxn,ans;
int a[50005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--){
		maxn=a[i];
		int sumn=0;
		for(int j=i-1;j>=1;j--){
			sumn+=a[j];
		}
		//cout<<"sun:"<<sumn<<endl;
		if(sumn<=maxn){
			continue;
		}
		for(int k=3;k<=i;k++){//¼¸±ßÐÎ 
			int l=i-1;
			int r=i-k+1;
			int he=0;
			for(int i=r;i<=l;i++){
				he+=a[i];
			}
			while(he>maxn){
				//cout<<"k:"<<k<<" "<<l<<" "<<r<<endl;
				ans++;
				l--;
				r--;
				he=he-a[l]+a[r];
			}
		}
	}
	cout<<ans%998244353;
	return 0;
} 
