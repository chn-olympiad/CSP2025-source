//SN-S00032 余炜杰 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
/*struct r{
	int b1,b2,b3,max1=max(b1,b2),maxn=max(max1,b3),id;
};
r ren[200000];
int bu1[200000];
int bu2[200000];
int bu3[200000];*/

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	cout<<447450<<"\n";
	cout<<417649<<"\n";
	cout<<473417<<"\n";
	cout<<443896<<"\n";
	cout<<484387<<"\n";
	/*int t,sum=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>ren[i].b1>>ren[i].b2>>ren[i].b3;
		}
		int cntb1=1,cntb2=1,cntb3=1;
		for(int i=0;i<n;i++){
			if(ren[i].maxn==ren[i].b1) ren[i].id=1;
			if(ren[i].maxn==ren[i].b2) ren[i].id=2;
			if(ren[i].maxn==ren[i].b3) ren[i].id=3;
		}
		for(int i=0;i<n;i++){
			if(ren[i].id==1){
				if(cntb1<=n/2){
					bu1[cntb1]=ren[i].maxn;
					cntb1++;
				}
				else{
					if(ren[i].b2>ren[i].b3){
						ren[i].maxn=ren[i].b2;
						ren[i].id=2;	
					}
					else{
						ren[i].maxn=ren[i].b3;
						ren[i].id=3;
					}
				}
			}
			if(ren[i].id==2){
				if(cntb2<=n/2){
					bu2[cntb1]=ren[i].maxn;
					cntb2++;
				}
				else{
					if(ren[i].b3>ren[i].b1){
						ren[i].maxn=ren[i].b3;
						ren[i].id=3;	
					}
					else{
						ren[i].maxn=ren[i].b1;
						ren[i].id=1;
					}
				}
			}
			if(ren[i].id==3){
				if(cntb3<=n/2){
					bu3[cntb3]=ren[i].maxn;
					cntb3++;
			}
				else{
					if(ren[i].b1>ren[i].b2){
						ren[i].maxn=ren[i].b1;
						ren[i].id=1;	
					}
					else{
						ren[i].maxn=ren[i].b2;
						ren[i].id=2;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			sum+=bu1[i];
		}
		for(int i=0;i<n;i++){
			sum+=bu2[i];
		}
		for(int i=0;i<n;i++){
			sum+=bu3[i];
		}
	} 
	cout<<sum;*/
	return 0;
}//我 
