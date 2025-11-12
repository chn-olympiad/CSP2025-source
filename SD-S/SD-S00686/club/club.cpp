#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t; 
int f[100010];
int ans=0;//ÂúÒâ¶È 
bool flag=1;
int maxx1=0,maxx2=0;
int a[100010][6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		flag=1;
		ans=0;
		maxx1=0;
		maxx2=0;
		memset(a,0,sizeof a);
		memset(f,0,sizeof f);
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][3]!=0) flag=0;
		}
		if(n==2){
			if(a[1][1]>=a[1][2]&&a[1][1]>=a[1][3]&&a[1][1]>=a[2][1]&&a[1][1]>=a[2][2]&&a[1][1]>=a[2][3]){
				cout<<a[1][1]+max(a[2][2],a[2][3])<<endl;
				continue;
			}
			if(a[1][2]>=a[1][1]&&a[1][2]>=a[1][3]&&a[1][2]>=a[2][1]&&a[1][2]>=a[2][2]&&a[1][2]>=a[2][3]){
				cout<<a[1][2]+max(a[2][1],a[2][3])<<endl;
				continue;
			}
			if(a[1][3]>=a[1][1]&&a[1][3]>=a[1][2]&&a[1][3]>=a[2][1]&&a[1][3]>=a[2][2]&&a[1][3]>=a[2][3]){
				cout<<a[1][3]+max(a[2][1],a[2][2])<<endl;
				continue;
			}
			if(a[2][1]>=a[2][2]&&a[2][1]>=a[2][3]&&a[2][1]>=a[1][1]&&a[2][1]>=a[1][2]&&a[2][1]>=a[1][3]){
				cout<<a[2][1]+max(a[1][2],a[1][3])<<endl;
				continue;
			}
			if(a[2][2]>=a[2][1]&&a[2][2]>=a[2][3]&&a[2][2]>=a[1][1]&&a[2][2]>=a[1][2]&&a[2][2]>=a[1][3]){
				cout<<a[2][2]+max(a[1][1],a[1][3])<<endl;
				continue;
			}
			if(a[2][3]>=a[2][1]&&a[2][3]>=a[2][2]&&a[2][3]>=a[1][1]&&a[2][3]>=a[1][2]&&a[2][3]>=a[1][3]){
				cout<<a[2][3]+max(a[1][1],a[1][2])<<endl;
				continue;
			}
		}
		else if(flag==1){
			for(int j=1;j<=n;j++){
				maxx1=max(max(maxx1,a[j][1]),a[j][2]);
			}
			for(int j=1;j<=n;j++){
				if(a[j][1]>=maxx2&&a[j][1]<=maxx1) maxx2=a[j][1];
				if(a[j][2]>=maxx2&&a[j][2]<=maxx1) maxx2=a[j][2];
			}
			cout<<maxx1+maxx2<<endl;
		}
		else{
			for(int j=1;j<=n;j++){
				f[j]=max(max(a[j][1],a[j][2]),a[j][3]);
				ans+=f[j];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
