#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[200003];
bool used[200003];
bool if_not_all1;
long long cnt;
long long pre[200003];
bool find(long long i,long long j){
	for(long long k=i;k<=j;k++){
		if(used[k]) return true;
	}
	return false;
}
void give(long long i,long long j){
	for(long long k=i;k<=j;k++){
		used[k]=1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		if(a[i]!=1) if_not_all1=1;
	}
	if(k==0&&if_not_all1==0){
		cout<<n/2;
		return 0;
	}
	if(k==1&&if_not_all1==0){
		cout<<n;
		return 0;
	}
	if(k==1){
		for(long long i=2;i<=n;i++){
			if(a[i]==1){
				used[i]=1;
				cnt++;
			}
			else if(a[i]!=a[i-1]&&!used[i-1]){
				used[i]=1;
				used[i-1]=1;
				cnt++;
			}
			else if(i>2&&a[i]==a[i-1]&&a[i-1]==a[i-2]&&!used[i-1]&&!used[i-2]){
				used[i]=1;
				used[i-1]=1;
				used[i-2]=1;
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(k==0){
		for(long long i=2;i<=n;i++){
			if(a[i]==0){
				used[i]=1;
				cnt++;
			}
			else if(a[i-1]==a[i]){
				used[i-1]=1;
				used[i]=1;
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	else{
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(pre[j]^pre[i]==k&&!find(i,j)){
					cnt++;
					give(i,j);
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
