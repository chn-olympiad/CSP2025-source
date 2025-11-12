#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int v[500005][2];
int cnt=1;
bool b[500005];
int aans;
void dfs(int ans){
	if(ans>aans){
		aans=ans;
	}
	for(int i=1;i<cnt;i++){
		bool r=true;
		for(int j=v[i][0];j<=v[i][1];j++){
			if(b[j]){
				r=false;
				break;
			}
		}
		if(r){
			for(int j=v[i][0];j<=v[i][1];j++){
				b[j]=true;
			}
			dfs(ans+1);
			for(int j=v[i][0];j<=v[i][1];j++){
				b[j]=false;
			}
		}
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(b,false,sizeof(b));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			aans++;
			b[i]=true;
		}
	}
	for(int i=1;i<=n-1;i++){
		int x=a[i];
		for(int j=i+1;j<=n;j++){
			x^=a[j];
			if(x==k){
				int l=cnt;
				v[cnt][0]=i;
				v[cnt][1]=j;
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	dfs(0);
	cout<<aans<<endl;
	return 0;
}
