#include<iostream>
using namespace std;
void pi(int ren[][3],int *she,int wei,int ci,int b,int *tuan){
//cout<<1;
	int mei[b],v[b];
	for(int i=0;i<b;i++){
		int ma=20000;
		for(int j=0;j<3;j++){
			if(j==wei)continue;
			if(ren[i][wei]-ren[i][j]<ma){
				ma=ren[i][wei]-ren[i][j];
				v[i]=j;
			}
			mei[i]=ma;
		}}	//cout<<mei[1]<<" ";
		for(int i=0;i<ci;i++){
			int ma=20000;
			int vei;
			for(int j=0;j<b;j++){	
				if(ma>mei[j]&&mei[j]>=0){
					ma=mei[j];
				//	cout<<ma;
					vei=j;
				}
			}
			*tuan= *tuan -ma;
			*(she+v[vei])=*(she+v[vei]) +1;
			*(she+wei)=*(she+wei) -1;
		//	cout<<*(she+v[vei])<<' ';
			mei[vei]= -1;
		}
		
	//for(int j=0;j<b;j++){	
	//			cout<<mei[j]<<' ';
	//		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,max;
	cin>>a;
//	cout<<a<<' ';
	for(int ii=1;ii<=a;ii++){
	int b,sum=0,she[3]={0,0,0};
	cin>>b;
	int man[b][3];
	for(int i=0;i<b;i++){
		int ma=-1;
		int wei=-1;
		for(int z=0;z<3;z++){
			cin>>man[i][z];
			if(ma<man[i][z]){
				ma=man[i][z];
				wei=z;
			}	
		}
		she[wei]++;
		sum+=ma;	
	}
//	for(int i=0;i<3;i++){
//		cout<<she[i];
///	}
//cout<<sum<<'\n';
	while(she[0]>b/2||she[1]>b/2||she[2]>b/2)
	for(int i=0;i<3;i++){
		if(she[i]>b/2)pi(man,&she[0],i,she[i]-(b/2),b,&sum);
	}cout<<sum;
	if(ii!=a)cout<<'\n';
	}
	
	return 0;
} 
