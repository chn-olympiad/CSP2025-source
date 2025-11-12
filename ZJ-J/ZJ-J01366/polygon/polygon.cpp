#include<bits/stdc++.h>

using namespace std;

int n;
long long a[5005];
bool vis[5005];
long long ans;

void search(long long step,long long mmax,long long lim,long long sum,long long prev){
	if(step==lim+1){
		if(sum>2*mmax){
			ans++;
			ans=ans%998244353;
			/*
			for(int i=1;i<=n;i++){
				if(vis[i]==true){
					cout<<a[i]<<" ";
				}
			}
			cout<<endl;
			*/
		}
		return;
	}else{
		for(long long i=prev;i<=n;i++){
			if(vis[i]==false){
				vis[i]=true;
				//cout<<i<<endl;
				search(step+1,max(mmax,a[i]),lim,sum+a[i],i+1);
				vis[i]=false;
			}
		}
	}
}

int main(){

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//sort(a+1,a+1+n);
	
	
	for(long long i=3;i<=n;i++){
		search(1,0,i,0,1);
	}

	cout<<(ans%998244353)<<endl;


	return 0;
}






//By StuffyWalk Problem4
