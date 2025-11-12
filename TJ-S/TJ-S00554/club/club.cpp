#include<iostream>
#include<algorithm>
using namespace std;

int t;

int a[100000][4];
int p[4];


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	
	for(int q=1;q<=t;q++){
		p[1]=0;
		p[2]=0;
		p[3]=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
						
		}
		int good=0;//总满意度 
		int big=n/2;//最大人数 
		int ym[100000]={0};
		for(int i=1;i<=n;i++){
			ym[i] = a[i][1];
		}
		
		sort(ym+1,ym+n+1);
		
	    
		
		for(int i=n;i>big;i--){
			good+=ym[i];
		}
		
		cout<<good<<endl;
		
		
	}
	
	
	
	

	
	
	
	return 0;
} 
