#include<bits/stdc++.h>
using namespace std;
int a[5005],s[5005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[j]-s[i-1] > 2*a[i] && abs(j-i)>2){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
