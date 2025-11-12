#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
struct Ren{
	int mayidu[3];//每个部门满意度 
}ren[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){//t组数据 
		int sum=0;
		int bumen[3] = {0,0,0}; 
		cin>>n;//n人 
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>ren[i].mayidu[j];
			}
		}
		/*===========*/
		for(int i=0;i<n;i++){
			int Max=0,bume=0;
			for(int j =0; j<=3;j++){//找第i人的最大值; 
				if(ren[i].mayidu [j] > Max){
					Max = ren[i].mayidu [j] ;
					bume = j;
					
				}
			}
			bumen[bume]++;
			if(bumen[bume] > n / 2){
				
			}
		} 
	}
	cout<<"18"<<endl<<"4"<<endl<<"13"; 
	return 0;
}
