#include<bits/stdc++.h>
using namespace std;

int pp1[100010],pp2[100010],pp3[100010],bj[100010];
int ddt=0,ddn = 0,dan1 = 0,dan2 = 0,dan3 = 0,dnk = 0,dddt=0,ddn2,df=0;
int ls1,ls2,ls3;


struct ddp{
	int da1=0;
 	int da2=0;
 	int da3=0;
 	int ddi;

 }ddps[100010];

bool ddcmp1(ddp dda1,ddp dda2){
	return dda1.da1>dda2.da1;
}
bool ddcmp2(ddp dda1,ddp dda2){
	return dda1.da2>dda2.da2;
}
bool ddcmp3(ddp dda1,ddp dda2){
	return dda1.da3>dda2.da3;
}


int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>dnk;
	for(int ddi = 0;ddi<dnk;ddi++){
		
		ddt = 0,ddn = 0,dan1 = 0,dan2 = 0,dan3 = 0,dddt=0,df=0;
		memset(bj,0,sizeof(bj));
		memset(ddps,0,sizeof(ddps));
		cin>>ddn;
		ddn2 = ddn/2;
		for(int i=0;i<ddn;i++){
			cin>>ddps[i].da1>>ddps[i].da2>>ddps[i].da3;
			ddps[i].da3 = ddps[i].da1-ddps[i].da2;
			ddps[i].ddi = i;
		}
		ddt = 0;
		sort(ddps,ddps+ddn+1,ddcmp1);
		for(int i=0;i<ddn;i++){
			if(ddt>=ddn2)break;
			ddt++;
			dddt++;
			dan1 += ddps[i].da1;
			bj[ddps[i].ddi] = 1;
		}
		
		cout<<(dan1+dan2)<<endl;		
		
	}
	



	return 0;
	
} 
