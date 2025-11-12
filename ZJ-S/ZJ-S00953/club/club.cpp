#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn][10];
int chazhi[maxn];
int t;
int f(){
	int n;
	cin>>n;
	int cnt[5]={},c=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxnn=max(max(a[i][1],a[i][2]),a[i][3]),tmp=-1;
		ans+=maxnn;
		if(maxnn==a[i][1]){
			cnt[1]++;
			tmp++;
		}
		if(maxnn==a[i][2]){
			cnt[2]++;
			tmp++;
		}
		if(maxnn==a[i][3]){
			cnt[3]++;
			tmp++;
		}
		c+=min(tmp,1);
	}
	int cnt_max=max(max(cnt[1],cnt[2]),cnt[3]);
	if(cnt_max-c>n/2){
		for(int i=1;i<=3;i++){
			if(cnt[i]==cnt_max){
				int sum=0;
				for(int j=1;j<=n;j++){
					int maxnn=max(max(a[j][1],a[j][2]),a[j][3]);
					int minn=min(min(a[j][1],a[j][2]),a[j][3]);
					if(maxnn==a[j][i]&&maxnn-a[j][1]-a[j][2]-a[j][3]+minn+maxnn!=0){
						sum++;
						chazhi[sum]=maxnn-a[j][1]-a[j][2]-a[j][3]+minn+maxnn;
					}
				}
				sort(chazhi+1,chazhi+1+sum);
				for(int j=1;j<=cnt_max-c-n/2;j++){
					ans-=chazhi[j];
				}
				return ans;
			}
		}
	}
	else{
		return ans;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cout<<f()<<endl;
	}
	return 0;
}
