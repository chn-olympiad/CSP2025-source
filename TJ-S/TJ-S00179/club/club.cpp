#include<bits/stdc++.h>
using namespace std;
int arr[10005][10005]={};
struct Node{
	int a;
	int b;
	int step;
	int a1;
	int b1;
	int c1;
}nrr[10005];
int fn[5][2]={{1,2},{1,-2},{1,1},{1,-1},{1,0}};
int brr[10005]={};
int n,e=0,t=0;
int bfs(int x,int y){
	int sum=0,big=-1;
	t=0;
	e=0;
	nrr[t].a=0;
	nrr[t].b=0;
	nrr[t].step=0;
	e++;
	nrr[e].a=x;
	nrr[e].b=y;
	nrr[e].step=arr[x][y];
	if(y==1) nrr[e].a1++;
	else if(y==2) nrr[e].b1++;
	else if(y==3) nrr[e].c1++;
	while(1){
		t++;
		if(t>e) break;
		for(int j=0;j<=4;j++){
			int nx=nrr[t].a+fn[j][0];
			int ny=nrr[t].b+fn[j][1];
			if(nx>=1&&ny>=1&&nx<=n&&ny<=3){
				bool flag=false;
				cout<<nx<<","<<ny<<":";
				if(ny==1&&nrr[t].a1<=n/2-1){
					flag=true;
					nrr[e+1].a1=nrr[t].a1+1;
				}else if(ny==2&&nrr[t].b1<=n/2-1){
					flag=true;
					nrr[e+1].b1=nrr[t].b1+1;
				}else if(ny==3&&nrr[t].c1<=n/2-1){
					flag=true;
					nrr[e+1].c1=nrr[t].c1+1;
				}
				if(flag==true){
					e++;
					nrr[e].a=nx;
					nrr[e].b=ny;
					nrr[e].step=nrr[t].step+arr[nx][ny];
					cout<<nrr[e].step<<endl;
					if(nx==n){
						big=max(big,nrr[e].step);
					}	
				}else{
					cout<<"no"<<endl;
				}
			}
		}
	}
	return big;
}
void qingc(){
	for(int bkm=1;bkm<=e;bkm++){
		nrr[bkm].a1=0;
		nrr[bkm].b1=0;
		nrr[bkm].c1=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int sl;
	cin>>sl;
	for(int i=1;i<=sl;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int z=1;z<=3;z++){
				cin>>arr[j][z];
			}
		}
		qingc();
		cout<<max(bfs(1,1),max(bfs(1,2),bfs(1,3)))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
