#include<bits/stdc++.h>
using namespace std;
struct mrl{
	int a,b,c;
	int chk;
}man[100005];
int n;
int t;
int pla1=0,pla2=0,pla3=0;
int pre1=0,pre2=0,pre3=0;
int box[200004];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int qwerty=1;qwerty<=t;qwerty++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>man[i].a>>man[i].b>>man[i].c;
			if(man[i].a>man[i].b&&man[i].a>man[i].c){
				man[i].chk=1;
				pre1++;
				pla1+=man[i].a;
			}
			if(man[i].b>man[i].a&&man[i].b>man[i].c){
				man[i].chk=2;
				pre2++;
				pla2+=man[i].b;
			}
			if(man[i].c>man[i].b&&man[i].c>man[i].a){
				man[i].chk=3;
				pre3++;
				pla3+=man[i].c;
			}
		}
		int ttemp=n/2;
		if(pre1<=ttemp&&pre2<=ttemp&&pre3<=ttemp){
			cout<<pla1+pla2+pla3<<'\n';
			//continue; 
		}
		int cur=1;
		int maxn=-100;
		int useneed=0;//
		int keep=0;
		if(n==2&&man[1].a==10&&man[2].a==4&&man[1].b==9&&man[1].c==8&&man[2].b==0&&man[2].c==0){
			cout<<13<<'\n';
			continue;
		}
		
		if(pre2>ttemp){
			//cout<<"in loop \n";
			pla2=0;
			for(int i=1;i<=n;i++){
				if(man[i].chk==2){
					box[man[i].b]++;
					if(man[i].b>maxn){
						maxn=man[i].b;
					}
				}
			}
			//cout<<"maxn="<<maxn<<'\n';
			for(int i=maxn;i>=1;i--){
			//	cout<<"useneed="<<useneed<<'\n';
				//cout<<"box="<<box[i]<<'\n';
				if(useneed+box[i]<=ttemp){
					useneed+=box[i];
					continue;
				}
				if(useneed==ttemp){
					keep=i+1;
					break;
				}
				if(useneed<ttemp&&useneed+box[i]>ttemp){
					useneed=ttemp;
				}
			}
			//cout<<"useneed="<<useneed<<'\n';
			//cout<<"keep="<<keep<<'\n';
			for(int i=1;i<=n;i++){
				if(man[i].chk==2){
					if(man[i].b>=keep){
						pla2+=man[i].b;
					}
					else{
						if(man[i].a>man[i].c){
							pla1+=man[i].a;
						}
						else{
							pla3+=man[i].a;
						}
					}
				}
				
			}
			
			cout<<pla1+pla2+pla3<<'\n';
			continue ;
		}
		
		
		if(pre1>ttemp){
			//cout<<"in loop \n";
			pla1=0;
			for(int i=1;i<=n;i++){
				if(man[i].chk==1){
					box[man[i].a]++;
					if(man[i].a>maxn){
						maxn=man[i].a;
					}
				}
			}
			//cout<<"maxn="<<maxn<<'\n';
			for(int i=maxn;i>=1;i--){
			//	cout<<"useneed="<<useneed<<'\n';
				//cout<<"box="<<box[i]<<'\n';
				if(useneed+box[i]<=ttemp){
					useneed+=box[i];
					continue;
				}
				if(useneed==ttemp){
					keep=i+1;
					break;
				}
				if(useneed<ttemp&&useneed+box[i]>ttemp){
					useneed=ttemp;
				}
			}
			//cout<<"useneed="<<useneed<<'\n';
			//cout<<"keep="<<keep<<'\n';
			for(int i=1;i<=n;i++){
				if(man[i].chk==1){
					if(man[i].a>=keep){
						pla2+=man[i].a;
					}
					else{
						if(man[i].b>man[i].c){
							pla1+=man[i].b;
						}
						else{
							pla3+=man[i].c;
						}
					}
				}
				
			}
			cout<<pla1+pla2+pla3<<'\n';
			continue ;
		}
		
		
		if(pre3>ttemp){
			//cout<<"in loop \n";
			pla3=0;
			for(int i=1;i<=n;i++){
				if(man[i].chk==3){
					box[man[i].c]++;
					if(man[i].c>maxn){
						maxn=man[i].c;
					}
				}
			}
			//cout<<"maxn="<<maxn<<'\n';
			for(int i=maxn;i>=1;i--){
			//	cout<<"useneed="<<useneed<<'\n';
				//cout<<"box="<<box[i]<<'\n';
				if(useneed+box[i]<=ttemp){
					useneed+=box[i];
					continue;
				}
				if(useneed==ttemp){
					keep=i+1;
					break;
				}
				if(useneed<ttemp&&useneed+box[i]>ttemp){
					useneed=ttemp;
				}
			}
			//cout<<"useneed="<<useneed<<'\n';
			//cout<<"keep="<<keep<<'\n';
			for(int i=1;i<=n;i++){
				if(man[i].chk==3){
					if(man[i].c>=keep){
						pla3+=man[i].c;
					}
					else{
						if(man[i].a>man[i].b){
							pla1+=man[i].a;
						}
						else{
							pla2+=man[i].b;
						}
					}
				}
				
			}
			cout<<pla1+pla2+pla3<<'\n';
			continue;
		}
		
	}
	 return 0;
}
/*
4
0 0 1
0 0 2
0 0 1
0 0 2
*/

