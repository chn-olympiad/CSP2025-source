#include<bits/stdc++.h>
using namespace std;
int n,a[100],ans;
void dfs(int now,int c,int h,string s){
	//cout<<now<<" ";
	h+=a[now];
	s+=char(a[now]+48);
	if(c==0){
		if(h>a[now]*2){
			ans++;
			//cout<<s<<endl;
		}
		return;
	}else{
		c-=1;
		for(int i=now+1;i<=n-c;i++){
			dfs(i,c,h,s);
		}	
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>20){
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			dfs(j,i-1,0,"");
		}
	}
	cout<<ans;
	return 0;
}
