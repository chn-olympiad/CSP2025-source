#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int a[N][3];
int cnt[3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		int n,max2,max3,pos1,pos2,pos3;
		cin>>n;
		int max_cnt=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				max3=0;pos3=0;
				if(a[i][j]>max3){
					max2=max3;
					max3=a[i][j];
					pos2=pos3;
				    pos3=j;
				}
				if(pos3==0) pos2=1;
				if(cnt[pos3]<max_cnt){
					cnt[pos3]++;
					ans+=max3;
				}
				else if(cnt[pos2]<max_cnt){
					cnt[pos2]++;
					ans+=max2;
				}
				else{
					pos1=3-pos2-pos3;
					cnt[pos1]++;
					ans+=a[i][pos1];
				}
		    }
		}
		cout<<ans;
	}
	return 0;
}