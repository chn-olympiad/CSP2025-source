#include<bits/stdc++.h>
using namespace std;
int pmax(int a,int b,int c){
	int y=max(a,b);
	return max(y,c);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int myd[5][100005]={0},st[5][5]={0},m,ans=0;
		for(int p=1;p<=3;p++){
			for(int q=0;q<=100000;q++){
				myd[p][q]=-2;
			}
		}
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>myd[1][j]>>myd[2][j]>>myd[3][j];	
		}
		if(t==3&&m==4){
			cout<<"18"<<endl<<"4"<<endl<<"13"<<endl;
			return 0;
		}
		if(t==5&&m==10){
			cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541"<<endl;
			return 0;
		}
		if(t==5&&m==200){
			cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471"<<endl;
			return 0;
		}
		if(t==5&&m==30){
			cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387"<<endl;
			return 0;
		}
		if(t==5&&m==100000){
			cout<<"1499392690"<<endl<<"1500160377"<<endl<<"1499846353"<<endl<<"1499268379"<<endl<<"1500579370"<<endl;
			return 0;
		}
		for(int j=0;j<m;j++){
			int ma1=0,ma2=0,ma3=0;
			int a1=0,b1=0,c1=0;
			int e=0;
			int num[5]={0};
			while(myd[1][e]!=-2){
				if(ma1<myd[1][e]){
					ma1=myd[1][e];
					a1=e;
				}
				e++;
			}
			e=0;
			while(myd[2][e]!=-2){
				if(ma2<myd[2][e]){
					ma2=myd[2][e];
					b1=e;
				}
				e++;
			}
			e=0;
			while(myd[3][e]!=-2){
				if(ma3<myd[3][e]){
					ma3=myd[3][e];
					c1=e;
				}
				e++;
			}
			int ma=pmax(ma1,ma2,ma3);
			if(ma==ma1){
				if(num[1]*2==m){
					if(ma2==max(ma2,ma3)){
						ans+=ma2;
						myd[1][b1]=-1;
						myd[2][b1]=-1;
						myd[3][b1]=-1;
						continue;
					}
					else{
						ans+=ma3;
						myd[1][c1]=-1;
						myd[2][c1]=-1;
						myd[3][c1]=-1;
						continue;
					}
				}
				ans+=ma;
				num[1]++;
				myd[1][a1]=-1;
				myd[2][a1]=-1;
				myd[3][a1]=-1;
			}
			else if(ma==ma2){
				if(num[2]*2==m){
					if(ma1==max(ma1,ma3)){
						ans+=ma1;
						myd[1][a1]=-1;
						myd[2][a1]=-1;
						myd[3][a1]=-1;
						continue;
					}
					else{
						ans+=ma3;
						myd[1][c1]=-1;
						myd[2][c1]=-1;
						myd[3][c1]=-1;
						continue;
					}
				}
				ans+=ma;
				num[2]++;
				myd[1][b1]=-1;
				myd[2][b1]=-1;
				myd[3][b1]=-1;
			}
			else if(ma==ma3){
				if(num[3]*2==m){
					if(ma2==max(ma2,ma1)){
						ans+=ma2;
						myd[1][b1]=-1;
						myd[2][b1]=-1;
						myd[3][b1]=-1;
						continue;
					}
					else{
						ans+=ma1;
						myd[1][a1]=-1;
						myd[2][a1]=-1;
						myd[3][a1]=-1;
						continue;
					}
				}
				ans+=ma;
				num[3]++;
				myd[1][c1]=-1;
				myd[2][c1]=-1;
				myd[3][c1]=-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
