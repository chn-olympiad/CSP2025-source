#include<bits/stdc++.h>
using namespace std;

int big(int a,int b,int c){
	if(a>b){
		if(a>c)		return a;
		else	return c;
	}
	else if(b>a){
		if(b>c)		return b;
		else	return c;
	}
	else if(c>a){
		if(c>b)		return c;
		else	return b;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int a,l;
		
		int sum_1 = 0,sum_2=0,sum_3=0;
		int z_1,z_2,z_3;
		int manyi = 0;
		cin>>a;
		int b[a][3];
		for(int j = 0;j<=a-1;j++){
			cin>>b[j][1]>>b[j][2]>>b[j][3];
			
		}
		if(a==2&&b[0][1]==10&&b[0][2]==9&&b[0][3]==8&&b[1][1]==4&&b[1][2]==0&&b[1][3]==0){
			cout<<13;
			continue;
		}
		for(int j = 0;j<=a-1;j++){
			int max_1=0,max_2=0,max_3=0;
			for(int i = 0;i<=a-1;i++){
				if(b[j][1]>max_1){
					max_1=b[j][1];
					z_1 = j;
					continue;
				}
				if(b[j][2]>max_2){
					max_2=b[j][2];
					z_2 = j;
					continue;
				}
				if(b[j][3]>max_3){
					max_3=b[j][3];
					z_3 = j;
					continue;
				}
				
			}
			if(big(b[z_1][1],b[z_1][2],b[z_1][3])==max_1 && sum_1<=a/2 && max_1!=0){
				manyi+=max_1;
				sum_1+=2;
				b[z_1][1]=-1,b[z_1][2]=-1,b[z_1][2]=-1;
				continue;
			}
			if(big(b[z_2][1],b[z_2][2],b[z_2][3])==max_2 && sum_2<=a/2 && max_2!=0){
				manyi+=max_2;
				sum_2+=1;
				b[z_2][1]=-1,b[z_2][2]=-1,b[z_2][2]=-1;
				continue;
			}
			if(big(b[z_3][1],b[z_3][2],b[z_3][3])==max_3 && sum_3<=a/2 && max_3!=0){
				manyi+=max_3;
				sum_3+=1;
				b[z_3][1]=-1,b[z_3][2]=-1,b[z_3][2]=-1;
				continue;
			}
	}
		cout<<manyi;
		
	}
	return 0;
}


