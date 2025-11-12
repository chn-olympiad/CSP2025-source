#include<bits/stdc++.h>
using namespace std;
struct node{
	int fir;
	int sec;
	int thi;
	int maxx;
	int maxs;
	bool flag=false;
	int number;
	int lastmaxx;
	int lastmaxs;
	int endmaxx;
	int endmaxs;
}a[100005];	
bool cmp(node x,node y){
	return x.maxx>y.maxx;
	}
int t;

int main(){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].fir>>a[i].sec>>a[i].thi;
			a[i].number=i;
			int maxxx=max(a[i].fir,max(a[i].sec,a[i].thi));
			a[i].maxx=maxxx;
			if(maxxx==a[i].fir){
				a[i].maxs=1;
			}else if(maxxx==a[i].sec){
				a[i].maxs=2;
			}else if(maxxx==a[i].thi){
				a[i].maxs=3;
			}
			if(a[i].maxx==a[i].fir){
				int w=max(a[i].sec,a[i].thi);
				a[i].lastmaxx=w;
				if(w=a[i].sec){
					a[i].lastmaxs=2;
				}else if(w=a[i].thi){
					a[i].lastmaxs=3;
				}
			}else if(a[i].maxx==a[i].sec){
				int e=max(a[i].fir,a[i].thi);
				a[i].lastmaxx=e;
				if(e=a[i].fir){
					a[i].lastmaxs=1;
				}else if(e=a[i].thi){
					a[i].lastmaxs=3;
				}
			}else if(a[i].maxx==a[i].thi){
				int r=max(a[i].sec,a[i].fir);
				a[i].lastmaxx=r;
				if(r=a[i].sec){
					a[i].lastmaxs=2;
				}else if(r=a[i].fir){
					a[i].lastmaxs=1;
				}
			}
			if(a[i].maxs==1&&a[i].lastmaxs==2){
				a[i].endmaxx=a[i].thi;
				a[i].endmaxs=3;
			}else if(a[i].maxs==1&&a[i].lastmaxs==3){
				a[i].endmaxx=a[i].sec ;
				a[i].endmaxs=2;
			}else if(a[i].maxs==2&&a[i].lastmaxs==1){
				a[i].endmaxx=a[i].thi ;
				a[i].endmaxs=3;
			}else if(a[i].maxs==2&&a[i].lastmaxs==3){
				a[i].endmaxx=a[i].fir ;
				a[i].endmaxs=1;
			}else if(a[i].maxs==3&&a[i].lastmaxs==1){
				a[i].endmaxx=a[i].sec ;
				a[i].endmaxs=2;
			}else if(a[i].maxs==3&&a[i].lastmaxs==2){
				a[i].endmaxx=a[i].fir ;
				a[i].endmaxs=1;
			}
		}
		int q=n/2;
		long long maxx1=0,maxx2=0,maxx3=0,ans=0,ans1=0,maxx4=0,maxx5=0,maxx6=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].maxs==1&&maxx1<=q&&a[i].flag){
				maxx1++;
				ans+=a[i].maxx; 
				a[i].flag=false;
			}else if(a[i].maxs==2&&maxx2<=q&&a[i].flag){
				maxx2++;
				ans+=a[i].maxx;
				a[i].flag=false;
			}else if(a[i].maxs==3&&maxx3<=q&&a[i].flag){
				maxx3++;
				ans+=a[i].maxx;
				a[i].flag=false;
			}else if(a[i].lastmaxs==1&&maxx1<=q&&a[i].flag){
				maxx1++;
				ans+=a[i].lastmaxx;
				a[i].flag=false;
			}else if(a[i].lastmaxs==2&&maxx2<=q&&a[i].flag){
				maxx2++;
				ans+=a[i].lastmaxx;
				a[i].flag=false;
			}else if(a[i].lastmaxs==3&&maxx3<=q&&a[i].flag){
				maxx3++;
				ans+=a[i].lastmaxx;
				a[i].flag=false;
			}else if(a[i].endmaxs==1&&maxx1<=q&&a[i].flag){
				maxx1++;
				ans+=a[i].endmaxx;
				a[i].flag=false;
			}else if(a[i].endmaxs==2&&maxx2<=q&&a[i].flag){
				maxx2++;
				ans+=a[i].endmaxx;
				a[i].flag=false;
			}else if(a[i].endmaxs==3&&maxx3<=q&&a[i].flag){
				maxx3++;
				ans+=a[i].endmaxx;
				a[i].flag=false;
			}
		}
		for(int i=n;i>=1;i++){
			if(a[i].maxs==1&&maxx4<=q&&a[i].flag){
				maxx4++;
				ans1+=a[i].maxx;
				a[i].flag=false; 
			}else if(a[i].maxs==2&&maxx5<=q&&a[i].flag){
				maxx5++;
				ans1+=a[i].maxx;
				a[i].flag=false;
			}else if(a[i].maxs==3&&maxx6<=q&&a[i].flag){
				maxx6++;
				ans1+=a[i].maxx;
				a[i].flag=false;
			}else if(a[i].lastmaxs==1&&maxx4<=q&&a[i].flag){
				maxx4++;
				ans1+=a[i].lastmaxx;
				a[i].flag=false;
			}else if(a[i].lastmaxs==2&&maxx5<=q&&a[i].flag){
				maxx5++;
				ans1+=a[i].lastmaxx;
				a[i].flag=false;
			}else if(a[i].lastmaxs==3&&maxx6<=q&&a[i].flag){
				maxx6++;
				ans1+=a[i].lastmaxx;
				a[i].flag=false;
			}else if(a[i].endmaxs==1&&maxx4<=q&&a[i].flag){
				maxx4++;
				ans1+=a[i].endmaxx;
				a[i].flag=false;
			}else if(a[i].endmaxs==2&&maxx5<=q&&a[i].flag){
				maxx5++;
				ans1+=a[i].endmaxx;
				a[i].flag=false;
			}else if(a[i].endmaxs==3&&maxx6<=q&&a[i].flag){
				maxx6++;
				ans1+=a[i].endmaxx;
				a[i].flag=false;
			}
		}
		cout<<max(ans,ans1);
	}
	fclose(stdin);
	fclose(stdout);
} 
