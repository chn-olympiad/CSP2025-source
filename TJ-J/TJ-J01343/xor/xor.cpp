#include<bits/stdc++.h>
using namespace std;
int yh(int a,int b){
	int ret=0;
	vector<int> ls;
	int wq=pow(2,(int)log(max(a,b))+1);
	for(int i=(int)log(max(a,b))+1;i>=0;i--){
		int w1=-1;w2=-1
		if(a>=wq){
			w1=1;
			a-=wq;
		}
		if(b>=wq){
			w2=1;
			b-=wq;
		}
		if(a!=b){
			ls.push_back(1);
		}
		else{
			ls.push_back(0);
		}
		wq/=2;
	}
	wq=1;
	for(int i=ls.size()-1;i>=0;i--){
		ret+=ls[i]*wq;
		wq*=2;
	}
	return ret;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> lis(n);
	for(int i=0;i<n;i++){
		cin>>lis[i];
	}
	vector<vector<int>> use;
	for(int i=0;i<n;i++){
		for(int k=i;k<n;k++){
			int t=lis[i];
			for(int j=i+1;j<=k;j++){
				t=yh(t,lis[j]);
			}
			if(t==k){
				use.push_back({i,k});
			}
		}
	}
	int ans=use.size();
	if(use[0][1]<=use[use.size()-1][0]){
		ans--;
		use[0][0]=-1;
		use[0][1]=-1;
	}
	for(int i=1;i<use.size()-1-1;i++){
		if(used[i-1][1]>=use[i][0]&&use[i][1]<=use[i+1][0]){
			ans--;
			use[i][0]=-1;
			use[i][1]=-1;
		}
		else if(used[i-1][1]>=use[i][0]&&use[i-1][1]>=use[i+1][0]){
			ans--;
			use[i-1][0]=-1;
			use[i-1][1]=-1;
		}
		else if(used[i-1][1]<=use[i][0]&&use[i-1][1]<=use[i+1][0]){
			ans--;
			use[i-1][0]=-1;
			use[i-1][1]=-1;
		}
		else if(use[i-1][1]>=use[i][0]){
			ans--;
			use[i][0]=-1;
			use[i][1]=-1;
		}
		else if(use[i][1]<=use[i+1][0]){
			ans--;
			use[i][0]=-1;
			use[i][1]=-1;
		}
	}
	cout<<ans;
	return 0;
}
