#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans=0;
bool b[100005];
bool check(){
	int s=0,sum=0;
	for(int i=1;i<=n;i++){
		if(b[i]==true)s+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==true){
			sum++;
			if(s<=a[i]*2)return false;
		}
	}
	if(sum<3)return false;
	return true;
}
void fa(int cnt,int k){
	if(cnt>=3&&check())ans++;
	if(k==n)return;
	for(int i=k+1;i<=n;i++){
		b[i]=true;
		fa(cnt+1,i);
		b[i]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fa(0,0);
	cout<<ans;
	return 0;
}
