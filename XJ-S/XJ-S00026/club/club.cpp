#include<bits/stdc++.h>
using namespace std;
long long n,n1;
struct node{
	int x;
	int y;
	int z;
}a[10001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>n1;
		int js=0;
		int js1[4]={0};
		for(int i=1;i<=n1;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		} 
		for(int j=1;j<=n1;j++){
			int maxn[3]={0};
			maxn[0]=1; 
			
			for(int i=1;i<=n1;i++){
				if(a[i].x==0&&a[i].y==0&&a[i].y==0) break;
				if(a[i].x>maxn[1]){
					maxn[1]=a[i].x;
					maxn[2]=1;
					maxn[0]=i;
				}
				if(a[i].y>maxn[1]){
					maxn[1]=a[i].y;
					maxn[2]=2;
					maxn[0]=i;
				}
				if(a[i].z>maxn[1]){
					maxn[1]=a[i].z;
					maxn[2]=3;
					maxn[0]=i;
				}
			}
			if(js1[maxn[2]]<n/2){
				if(maxn[2]==1){
					js+=a[maxn[0]].x;
				}
				if(maxn[2]==2){
					js+=a[maxn[0]].y;
				}
				if(maxn[2]==3){
					js+=a[maxn[0]].z;
				}
				js1[maxn[2]]++;
				a[maxn[0]].x=0;
				a[maxn[0]].y=0;
				a[maxn[0]].z=0;
			}else{
				if(maxn[2]==1){
					a[maxn[0]].x=0;
				}
				if(maxn[2]==2){
					a[maxn[0]].y=0;
				}
				if(maxn[2]==3){
					a[maxn[0]].z=0;
				}
			}
		}
		cout<<js<<endl;
	}
	return 0;
}
