#include<bits/stdc++.h>
using namespace std;
struct myd{
	int c[4];
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;//3部门 
	cin>>n;
	for(int z=1;z<=n;z++){
		int s=0;
		int m;//人数 
		cin>>m;
		myd b[m+1];
		int a[4],d[4],e[4]={0,0,0,0};
		for(int i=1;i<=m;i++){ 
			int x,y;
			for(int j=1;j<=3;j++){
				cin>>b[i].c[j];
			}
			int max=0;
			for(int j=2;j<=3;j++){
				if(b[i].c[j]>=max){
					max=b[i].c[j];
					y=j;
				}
			}
			b[i].c[y]=-1;
			d[i]=max; 
		}
	
		for(int i=1;i<=m;i++){
			int max=0,t=0,f=0;
			for(int j=1;j<=m;j++){
				if(d[j]>=max){
					max=d[j];
					t=j;
				}
			}
			if(f==m) break;
			if(e[t]+1<=m/2){
				e[t]++;
				d[t]=-1;
				s+=max;
				f++;
			}
			else{
				for(int i=1;i<=m;i++){
					max=0;
					for(int j=1;j<=3;j++){
						if(b[i].c[j]>=max&&e[j]+1<=m/2){
							d[i]=b[i].c[j];
						}
					} 
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
