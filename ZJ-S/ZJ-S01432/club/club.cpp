#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a,b,c[N][3],d[3],cj[N][3],w,p[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b;
		int myd=0;
		w=0;
		for(int j=0;j<3;j++) d[j]=0;
		for(int j=0;j<b;j++){
			for(int k=0;k<3;k++){
				cj[j][k]=-1;
			}
		}
		for(int j=0;j<b;j++){
			cin>>c[j][0]>>c[j][1]>>c[j][2];
			if(c[j][0]>c[j][1]&&c[j][0]>c[j][2]){
				myd+=c[j][0];
				d[0]++;
				cj[j][0]=min(c[j][0]-c[j][1],c[j][0]-c[j][2]);
			}
			else if(c[j][1]>c[j][2]) {
				myd+=c[j][1];
				d[1]++;
				cj[j][1]=min(c[j][1]-c[j][0],c[j][1]-c[j][2]);
			}
			else{
				myd+=c[j][2];
				d[2]++;
				cj[j][2]=min(c[j][2]-c[j][1],c[j][2]-c[j][0]);
			} 
		}
		for(int j=0;j<3;j++){
			if(d[j]>b/2){
				w=j;
				for(int k=0;k<b;k++){
					p[k]=cj[k][w];
				}
				break;
			}
		}
		sort(p,p+b);
		int ll=d[w]-b/2;
		for(int j=0;j<ll;j++){
			if(p[j]==-1) ll++;
			else myd-=p[j];
		}
		cout<<myd<<endl;
	}
	return 0;
} 
