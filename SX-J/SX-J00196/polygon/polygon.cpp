#include<bits/stdc++.h>
using namespace std;
int n,m[6000];
int pol(int sum,int a){
	if(a==n)
	{
		return 0;
	}
	int ans=0;
	for(int i=a;i<n;i++)
	{
		if(sum>m[i]){
			ans++;
		}
		ans+=pol(sum+m[i],i+1);
	}
	return ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	sort(m,m+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans+=pol(m[i]+m[j],j+1);
		}
	}
	cout<<ans;

	return 0;
}