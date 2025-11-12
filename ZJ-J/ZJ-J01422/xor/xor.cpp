#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],vis[500005];
long long tim,cnt;
bool check(int i,int j){
	for(int k=i;k<=j;k++){
		if(vis[k]==1) return false;
	}
	return true;
}
bool f(int i,int j){
	int r=0;
	for(int k=i;k<=j;k++){
		r^=a[k];
	}
	return r==tim;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>tim;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==tim) vis[i]=1,cnt++;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			if(!check(i,j)) continue;
			if(f(i,j)){
				cnt++;
				for(int k=i;k<=j;k++){
					vis[k]=1;
				}
			}
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
