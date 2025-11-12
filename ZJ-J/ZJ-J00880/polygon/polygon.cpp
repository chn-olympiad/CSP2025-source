#include<bits/stdc++.h>
using namespace std;
int a[10001],n,cnt=0;
bool check(int num[],int n){
	int ans=0;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		ans+=num[i];
		if(num[i]>maxn){
			maxn=num[i];
		}
	}
	if(ans<=maxn*2 || n<3){
		return false;
	}else{
		return true;
	}
}
void search(int now){
	int p=log2(now)+1;
	if(p>=n+1){
		int numlist[5001]={0};
		int m=0;
		for(int i=0;i<n;i++){
			if(now%2==1){
				numlist[m++]=a[i];
			}
			now>>1;
		}
		if(check(numlist,m)){
			cnt++;
		}
		return;
	}else{
		search(now<<1);
		search((now<<1)+1);
		return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(max(max(a[0],a[1]),a[2])*2>=(a[0]+a[1]+a[2])){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	search(1);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4