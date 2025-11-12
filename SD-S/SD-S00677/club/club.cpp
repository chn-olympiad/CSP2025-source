#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int I=0;I<T;I++){
		int n;
		cin>>n;
		int a[n][3];
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		int ans=0;
		if(n<=30){
			for(int i=0;i<pow(3,n);i++){
				int cnt[3]={0,0,0},sum=0,xz=i;
				for(int j=0;j<n;j++){
					cnt[xz%3]++;
					sum+=a[j][xz%3];
					xz/=3;
				}
				if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
					ans=max(ans,sum);
				}
				cout<<I<<' '<<i<<endl;
			}
		}else{
			vector<int> b[3];
			for(int i=0;i<n;i++){
				if(a[i][0]<a[i][1]){
					b[1].push_back(a[i][1]-a[i][0]);
					ans+=a[i][1];
				}else if(a[i][0]>a[i][1]){
					b[0].push_back(a[i][0]-a[i][1]);
					ans+=a[i][0];
				}else{
					ans+=a[i][0];
				}
			}
			if(b[0].size()>n/2){
				for(int i=0;i<b[0].size()-1;i++){
					for(int j=i;j<b[0].size()-1;j++){
						if(b[0][j]>b[0][j+1]){
							swap(b[0][j],b[0][j+1]);
						}
					}
				}
				for(int i=0;i<=b[0].size()-n/2;i++){
					ans-=b[0][i];
				}
			}
			if(b[1].size()>n/2){
				for(int i=0;i<b[1].size()-1;i++){
					for(int j=i;j<b[1].size()-1;j++){
						if(b[1][j]>b[1][j+1]){
							swap(b[1][j],b[1][j+1]);
						}
					}
				}
				for(int i=0;i<=b[1].size()-n/2;i++){
					ans-=b[1][i];
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

