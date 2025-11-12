#include<bits/stdc++.h>

using namespace std;
struct oi{
	int x,num;
};
int n,a[1000000],b[1000000],c[1000000];
bool cmp(oi x,oi y){
	return x.x>y.x;
}
bool cb(int a,int b){
	return a<b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i]>>b[i]>>c[i];
		int m=n/2;
		int mx[3][100000];
		for(int i=0;i<3;i++){
			for(int j=0;j<9999;j++) mx[i][j]=0;
		}
		int nx[3]={0,0,0};
		int nmx[3]={INT_MAX,INT_MAX,INT_MAX};
		int cnt=0;
		for(int i=0;i<n;i++){
			oi w[3]={{a[i],0},{b[i],1},{c[i],2}};
			sort(w,w+3,cmp);
			int e=0;
			if(nx[w[0].num]<=m && e==0){
				int rr=w[0].num,xx=w[0].x;
				cnt+=xx;
				nx[rr]++;
				mx[rr][nx[rr]-1]=xx;
				nmx[rr]=min(xx,nmx[rr]);
				e=1;
			}
			else if(w[0].x>nmx[w[0].num] && e==0){
				cnt-=nmx[w[0].num];
				cnt+=w[0].x;
				int rr=w[0].num,xx=w[0].x;
				sort(mx[rr],mx[rr]+nx[rr],cb);
				mx[rr][0]=xx;
				nmx[rr]=mx[rr][1];
				e=1;
			}
			if(nx[w[1].num]<=m && e==0){
				int rr=w[1].num,xx=w[1].x;
				cnt+=xx;
				nx[rr]++;
				mx[rr][nx[rr]-1]=xx;
				nmx[rr]=min(xx,nmx[rr]);
				e=1;
			}
			else if(w[1].x>nmx[w[1].num] && e==0){
				cnt-=nmx[w[0].num];
				cnt+=w[0].x;
				int rr=w[1].num,xx=w[1].x;
				sort(mx[rr],mx[rr]+nx[rr],cb);
				mx[rr][0]=xx;
				nmx[rr]=mx[rr][1];
				e=1;
			}
			if(nx[w[2].num]<=m && e==0){
				int rr=w[2].num,xx=w[2].x;
				cnt+=xx;
				nx[rr]++;
				mx[rr][nx[rr]-1]=xx;
				nmx[rr]=min(xx,nmx[rr]);
				e=1;
			}
			else if(w[2].x>nmx[w[2].num] && e==0){
				cnt-=nmx[w[0].num];
				cnt+=w[0].x;
				int rr=w[2].num,xx=w[2].x;
				sort(mx[rr],mx[rr]+nx[rr],cb);
				mx[rr][0]=xx;
				nmx[rr]=mx[rr][1];
				e=1;
			}
		}
		cout << cnt<<endl;
	}
}
