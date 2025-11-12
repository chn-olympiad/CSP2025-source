#include<bits/stdc++.h> 
using namespace std;
int T;
int n;
struct stu{
	int c[3];
	int fnum,snum;
}a[100005];
int cc[3][100005];
int top[3];
int ans;

bool cmp(const int &x,const int &y){
	int xx=a[x].c[a[x].fnum]-a[x].c[a[x].snum];
	int yy=a[y].c[a[y].fnum]-a[y].c[a[y].snum];
	return xx>yy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		memset(top,0,sizeof(top));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c[0]>>a[i].c[1]>>a[i].c[2];
			int maxn=max(max(a[i].c[0],a[i].c[1]),a[i].c[2]);
			if(a[i].c[0]==maxn){
				a[i].fnum=0;a[i].c[0]=-1;
			}
			if(a[i].c[1]==maxn){
				a[i].fnum=1;a[i].c[1]=-1;
			}
			if(a[i].c[2]==maxn){
				a[i].fnum=2;a[i].c[2]=-1;
			}
			int maxm=max(max(a[i].c[0],a[i].c[1]),a[i].c[2]);
			if(a[i].c[0]==maxm){
				a[i].snum=0;
			}
			if(a[i].c[1]==maxm){
				a[i].snum=1;
			}
			if(a[i].c[2]==maxm){
				a[i].snum=2;
			}
			a[i].c[a[i].fnum]=maxn;
		}
		for(int i=1;i<=n;i++){
			cc[a[i].fnum][++top[a[i].fnum]]=i;
		}
		for(int k=0;k<=2;k++){
			if(top[k]>n/2){
				
				sort(cc[k]+1,cc[k]+1+top[k],cmp);
				
				while(top[k]>n/2){
					int p=cc[k][top[k]];
					int psnum=a[p].snum;
					cc[psnum][++top[psnum]]=p;
					top[k]--;
				}
			}
				
		}
		for(int k=0;k<=2;k++){
			
			for(int i=1;i<=top[k];i++){
				int p=cc[k][i];
				
				ans+=a[p].c[k];
			}
			
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}