//白梓桐 SN-S00550 西安市曲江第二中学
#include<bits/stdc++.h>
using namespace std;
int t,bj[100010];
struct aq{
	int id,f;
}a[100010][100010],mxd[100010];	
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,pc=0;
		cin>>n;
		pc=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].f;
				a[i][j].id=i;
				bj[i]=0;
			}
		}
		int er[100010];
		for(int i=1;i<=n;i++){
			for(int z=i;z<=3;z++){
				int we=0;
				for(int j=i;j<=n;j++){
					we=a[i][j].id;
					bj[i]+=a[i][j].f;
					mxd[i].id++;
				}
				for(int j=z;j<=n;j++){
					int mx=-1;
					if(mxd[i].id<=pc){
						mx=max(mx,bj[i]);
					}
					er[i]=mx;
				}
				cout<<er[i];
			}
			cout<<endl;
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
