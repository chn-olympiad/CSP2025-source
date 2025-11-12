#include<iostream>
#include<cstdio>
using namespace std;
int a[100002][5];
void dgf(){
	int n,xs[3]={0,0,0},sm=0,w,mn,ind;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		if(a[i][0]>a[i][1]){
			if(a[i][0]>a[i][2]){
				a[i][3]=0;
				if(a[i][1]>a[i][2]){
					a[i][4]=a[i][0]-a[i][1];
				}
				else{
					a[i][4]=a[i][0]-a[i][2];
				}
			}
			else{
				a[i][3]=2;a[i][4]=a[i][2]-a[i][0];
			}
		}
		else{
			if(a[i][1]>a[i][2]){
				a[i][3]=1;
				if(a[i][0]>a[i][2]){
					a[i][4]=a[i][1]-a[i][0];
				}
				else{
					a[i][4]=a[i][1]-a[i][2];
				}
			}
			else{
				a[i][3]=2;a[i][4]=a[i][2]-a[i][1];
			}
		}
	}
	for(int i=0;i<n;i++){
		xs[a[i][3]]++;
		sm+=a[i][a[i][3]];
	}
	if(xs[0]<=n/2&&xs[1]<=n/2&&xs[2]<=n/2)cout<<sm<<endl;
	else{
		for(w=0;w<3;w++){
			if(xs[w]>n/2)break;
		}
		for(int i=xs[w];i>n/2;i--){
			mn=2000000;
			for(int i=0;i<n;i++){
				if(a[i][3]==w&&a[i][4]<mn){
					mn=a[i][4];
					ind=i;
				}
			}
			sm-=a[ind][4];
			a[ind][3]=3;
		}
		cout<<sm<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	int t;
	cin>>t;
	for(int ao=0;ao<t;ao++){
		dgf();
	}
	return 0;
}
