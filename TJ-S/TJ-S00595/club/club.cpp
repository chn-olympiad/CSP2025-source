#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,c[3]={0},sum=0,t=1;
		cin>>n;
		int a[n+1][3];
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]==0||a[i][1]==0||a[i][2]==0){
				swap(a[i][0],a[t][0]);
				swap(a[i][1],a[t][1]);
				swap(a[i][2],a[t][2]);
				t++;
			}
		}
		t--;
		for(int i=1;i<=t;i++){
			for(int j=i+1;j<=t;j++){
				if(a[i][0]<a[j][0]||a[i][1]<a[j][1]||a[i][2]<a[j][2]){
					swap(a[i][0],a[j][0]);swap(a[i][1],a[j][1]);swap(a[i][2],a[j][2]);
				}
			}
		}
		for(int i=t+1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(max(max(a[i][0],a[i][1]),a[i][2])<max(max(a[j][0],a[j][1]),a[j][2])){
					swap(a[i][0],a[j][0]);swap(a[i][1],a[j][1]);swap(a[i][2],a[j][2]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			int maxt=0,mint=0,midt;
			for(int j=0;j<3;j++){
				if(a[i][maxt]<a[i][j])maxt=j;
				if(a[i][mint]>a[i][j])mint=j;
			}
			midt=3-maxt-mint;
			if(c[maxt]==n/2){
				if(c[midt]==n/2){
					sum+=a[i][mint];c[mint]++;
				}
				else {
					sum+=a[i][midt];c[midt]++;
				}
			}
			else{
				sum+=a[i][maxt];c[maxt]++;
			}
		}
		cout<<sum<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
