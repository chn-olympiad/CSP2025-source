#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum,x;
int c=1e5;
vector<bool> mdaoguo(n,true);
vector<vector<bool> > mzouguo(n+k,vector<bool>(n+k,true));
vector<vector<int> > luc(n+k,vector<int>(n+k,0));
vector<vector<int> > xia(k,(vector<int>)(5));
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
       cin>>a>>b;
       cin>>luc[a][b];
	}for(int i=0;i<k;i++){
		for(int j=0;j<5;j++){
			cin>>xia[i][j];
			if(j>0){
				luc[j][n+i+1]=xia[i][j];
			}	
			}
		}for(int i=0;i<k-1;i++){
		  if(xia[i][0]>xia[i+1][0]){
		  	for(int j=0;j<n+k;j++){
		  		luc[n+i+1][j]=0;
		  		luc[j][n+i+1]=0;
			  }
			  }else{for(int j=0;j<n+k;j++){
			  	luc[n+i+2][j]=0;
			  	luc[j][n+i+2]=0;
			  }
			  	
			  }}
		  
		
		for(int i=0;i<n+k;i++){
		for(int j=i;j<n+k;j++){
		for(int fe=j+1;fe<n+k;fe++){
			int a,b;
		if(luc[i][fe]!=0&&luc[i][fe]<luc[i][j]&&mzouguo[i][fe]==true&&mdaoguo[fe]==true){
			x=luc[i][fe];
			a=i;
			b=fe;
		}
		if(k=n+k-1){
			sum+=x;
			mzouguo[a][b]=false;
			mzouguo[b][a]=false;
			mdaoguo[b]=false;
			i=b;
			j=0;
			fe=1;
			break;
		}
		
		}
		}
		}int y;
		for(int i=0;i<k-1;i++){
			y=max(xia[i][0],xia[i+1][0]);
		}
		cout<<sum+y;
	fclose(stdin);
	fclose(stdout);
	}




