#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt[5005];
bool an[5005];
unsigned long long ans=0;
bool pd(bool an[]){
	int sum=0,k=1;
	for(int i=1;i<=n;i++){
		if(an[i]==1){
			sum++;	
			cnt[k++]=a[i];
		}		
	}if(sum<3)return 0;
	k--;
	for(int i=1;i<=k;i++){
		int t=k-1,j=i;
		sum=0;
		while(t>0){
			sum+=cnt[j++];
			if(j>k)j=1;
			t--;
		}if(sum<=cnt[j])return 0;
	}return 1;
}
void dfs(int x){
	if(x>n){
		if(pd(an)){
			ans++;
			ans%=998244353;
		}return;
	}else{
		for(int i=0;i<=1;i++){			
			an[x]=i;
			dfs(x+1);
			an[x]=(i==0?1:0);			
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
	if(n<=3){
		int q1,q2,q3;
		cin>>q1>>q2>>q3;
		if(q1+q2>q3&&q2+q3>q1&&q1+q3>q2){
			cout<<1;
		}return 0;
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
