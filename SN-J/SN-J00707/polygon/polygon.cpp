#include<bits/stdc++.h>
using namespace std;
//SN-J00707 西安市曲江第一学校
int a[100001];
int n; 
int v[100001];
int s[100001];
long long ans;
bool cmp(int x,int y){
	return x>y;
}
void f(int m,int x){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if(x>m){
		long long temp=0;
		for(int i=1;i<x-1;i++){
			temp+=s[i];
		}
		if(temp>s[x-1]){
			ans++;	
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(x==1){
			if(v[i]!=1){
				s[x]=a[i];
				v[i]=1;
				f(m,x+1);
				v[i]=0;
			}
		}else{
			if(v[i]!=1&&a[i]>=s[x-1]){
				s[x]=a[i];
				v[i]=1;
				f(m,x+1);
				v[i]=0;
			}
		} 
		
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=3;i<=n;i++){
		f(i,1);
	}
	cout<<ans%998244353;
	return 0;
} 
