#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[10001][4]={};
	int an[10001];
	int d[10001];
	cin>>t;
	int maxx=0,maxy[4]={};
	for(int s=0;s<t;s++){
		cin>>n;
		
		maxx=0;
		maxy[1]=0;
		maxy[2]=0;
		maxy[3]=0;
		int cnt=0;
		int c=0;
		int x=0,y=0,z=0;
		int xcnt=0,ycnt=0,zcnt=0;
		int mx=0,my=0,mz=0;
		int fl=0;
		int g=0;
		for(int i=0;i<n;i++){
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
			d[i]=0;
		}
		
		for(int i=0;i<n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		for(int i=0;i<3;i++){
			int cntt=0;
			for(int j=0;j<n;j++){
				if(a[j][i]>maxy[i]&&cntt+1<n/2){
					maxy[j]=a[j][i];
					cntt++;
				}
				else if(a[j][i]==maxy[i]&&cntt+1<n/2){
					cntt++;
					maxy[j]=a[j][i];
					d[j]=maxy[j];
				}
			}
		}
		
		for(int i=0;i<n;i++){
			maxx=0;
			if(a[i][1]>maxx){
				maxx=a[i][1];
				c=1;
			}
			if(a[i][2]>maxx){
				maxx=a[i][2];
				c=2;
			}
			if(a[i][3]>maxx){
				maxx=a[i][3];
				c=3;
			}
			
			if(c==1&&xcnt<=n/2){
				x+=maxx;
				xcnt++;
			}
			else if(c==1){
				x+=maxy[i];
				fl=1;
			}
			
			if(c==2&&ycnt<=n/2){
				y+=maxx;
				ycnt++;
			}
			else if(c==2){
				y+=maxy[i];
				fl=1;
			}
			
			if(c==3&&zcnt<=n/2){
				z+=maxx;
				zcnt++;
			}
			else if(c==3){
				z+=maxy[i];
				fl=1;
			}
		}
		an[s]=x+y+z;
	}
	for(int i=0;i<t;i++){
		cout<<an[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
