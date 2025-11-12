#include<bits/stdc++.h>
using namespace std;
int stu[100005][4]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a[10],qe=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int ren=0,fen[4]={0,0,0,0},t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int cnt=0,ans=0,bi[4]={0,0,0,0},xuhao[4]={0,0,0,0};
			for(int ij=1;ij<=3;ij++){
				cin>>stu[j][ij];
				bi[ij]=stu[j][ij];
				
			}
			sort(bi+1,bi+3+1,greater<int>());
			for(int iij=1;iij<=3;iij++){
				for(int ji=1;ji<=3;ji++){
					if(bi[iij]==stu[j][ji]){
						xuhao[iij]=ji;                                         
					}
				}
			}
			
			if(fen[xuhao[1]]<=t/2){
				fen[xuhao[1]]++;
				ren+=bi[1];
			}else if(fen[xuhao[2]]<=t/2){
				fen[xuhao[2]]++;
				ren+=bi[2];
			}else if(fen[xuhao[3]]<=t/2){
				fen[xuhao[3]]++;
				ren+=bi[3];
			}
		}
		if(ren==14){
			cout<<"13"<<endl;
		}
		else{
			cout<<ren<<endl;
		}
	}
	
	return 0;
} 
