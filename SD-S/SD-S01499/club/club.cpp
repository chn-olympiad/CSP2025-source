#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int abu;
	int bbu;
	int cbu;	
}a[N];//方便我们存储 
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			int c1,c2,c3;
			cin>>c1>>c2>>c3;
			int maxx=-1000;
			maxx=max(maxx,c1);
			maxx=max(maxx,c2);
			maxx=max(maxx,c3);
			cout<<maxx<<"\n";
		} 
		//特殊情况A ，直接判断 
		int arnum=0,brnum=0,crnum=0;
		int bzrs=0;	
		//具体看人数问题
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].abu>>a[i].bbu>>a[i].cbu;
			int b1=a[i].abu,b2=a[i].bbu,b3=a[i].cbu;
			//赋值，后面方便比较 
			int maxz=-1;
			if(b1>b2){
				maxz=max(b1,b2);
				if(arnum<=n/2){
					arnum++;
				}
			}
			else if(b1<b2){
				maxz=max(b1,b2);
				if(arnum<=n/2){
					arnum++;
				}
			}
			else if(b1>b3){
				maxz=max(b1,b3);
				if(brnum<=n/2){
					brnum++;
				}
			}
			else if(b2>b3){
				maxz=max(b2,b3);
				if(brnum<=n/2){
					brnum++;
				}
			}
			else if(b3>b2){
				maxz=max(b2,b3);
				if(crnum<=n/2){
					crnum++;
				}
			}
			else if(b3>b1){
				maxz=max(b2,b3);
				if(crnum<=n/2){
					crnum++;
				}
			}
			maxz=max(maxz,b3);
			ans+=maxz;
			maxz=-1;
		}
		//最多的正常情况 
		cout<<ans<<"\n";
	}
	return 0;
}
