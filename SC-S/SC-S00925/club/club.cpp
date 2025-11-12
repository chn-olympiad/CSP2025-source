#include<bits/stdc++.h>
using namespace std;
int t;
long long a[100001][5]={0},s=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,zo[4]={0};
		cin>>n;
		int M=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][1]==0&&j==2){
					swap(a[i][1],a[i][2]);
				}
				if(a[i][2]==0&&j==3){
					swap(a[i][2],a[i][3]);
				}
				if(a[i][j]==0) zo[j]++;
			}
		}
	
		if(zo[2]==n&&zo[3]==n){
			int tp[n+1];
			for(int i=1;i<=n;i++){
				tp[i]=a[i][1];
			}
			sort(tp+1,tp+n+1);
			for(int i=n;i>M;i--){
				s+=tp[i];
			}
			cout<<s<<'\n';
			continue;
		}
		
		if(zo[3]==n&&zo[2]!=n){
			while(1){
				int flag=0;
				for(int i=1;i<n;i++){
					if(a[i][2]<a[i+1][2]){
						swap(a[i],a[i+1]);
						flag=1;
					}
				}
				if(!flag) break;
			}
			for(int i=1;i<=n;i++){
				if(i<=M) s+=a[i][2];
				else s+=a[i][1];
			}
			cout<<s<<'\n';
			continue;
		}
		
		for(int i=1;i<=n;i++){
			s+=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		s=s*2/3;
		cout<<s<<'\n';
	}
	return 0;
}