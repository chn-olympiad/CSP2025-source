#include<bits/stdc++.h>
using namespace std;
const int MX=6e5+29;
int a[MX];
int n,k,mx,zmx;
void s1(){
	if(k>=2){
		cout<<'0';
		return ;
	}else{
		int t=0,ans=0;
		for(int i=1;i<=n;i++){
			t^=a[i];
			if(t==k){
				t=0;
				ans++;
			}
		}
		cout<<ans;
	}
}
void dfs(int x){
	if(x>n)return ;
	for(int i=x;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			t^=a[j];
			if(t==k){
				mx++;
				zmx=max(mx,zmx);
				dfs(j+1);
				mx--;
			}
		}
	}
}
void s2(){
	mx=0;
	dfs(1);
	cout<<zmx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int b=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)b=0;
	}
	if(b==1)s1();
	else s2();
	return 0;
} 
