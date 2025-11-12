#include<bits/stdc++.h>
using namespace std;
int manyi[100001][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	int a1,a2,a3;
	int add=0;
	int p=0;
	int ar=0,br=0,cr=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a1>>a2>>a3;
			manyi[j][1]=a1;
			manyi[j][2]=a2;
			manyi[j][3]=a3;
		}
	}
	for(int i=1;i<=t;i++){
		for(int q=1;q<=n;q++){
			/*if(manyi[q][2]>manyi[q][1]&&(manyi[q][1]+manyi[q+1][2]||manyi[q][1]+manyi[q+1][3])>manyi[q][2]+manyi[q+1][1]&&(manyi[q][1]+manyi[q+1][2]||manyi[q][1]+manyi[q+1][3])>manyi[q][2]+manyi[q+1][3]&&ar<=n/2-1){
				add+=manyi[q][1];
				ar+=1;
			}else if(manyi[q][3]>manyi[q][1]&&(manyi[q][1]+manyi[q+1][2]||manyi[q][1]+manyi[q+1][3])>manyi[q][3]+manyi[q+1][1]&&(manyi[q][1]+manyi[q+1][2]||manyi[q][1]+manyi[q+1][3])>manyi[q][3]+manyi[q+1][3]&&ar<=n/2-1){
				add+=manyi[q][1];
				ar+=1;
			}else if(manyi[q][1]>manyi[q][2]&&(manyi[q][2]+manyi[q+1][1]||manyi[q][2]+manyi[q+1][3])>manyi[q][1]+manyi[q+1][2]&&(manyi[q][2]+manyi[q+1][1]||manyi[q][2]+manyi[q+1][3])>manyi[q][1]+manyi[q+1][3]&&br<=n/2-1){
				add+=manyi[q][2];
				br+=1;
			}else if(manyi[q][3]>manyi[q][2]&&(manyi[q][2]+manyi[q+1][1]||manyi[q][2]+manyi[q+1][3])>manyi[q][3]+manyi[q+1][2]&&(manyi[q][2]+manyi[q+1][1]||manyi[q][2]+manyi[q+1][3])>manyi[q][3]+manyi[q+1][1]&&br<=n/2-1){
				add+=manyi[q][2];
				br+=1;
			}else if(manyi[q][1]>manyi[q][3]&&(manyi[q][3]+manyi[q+1][1]||manyi[q][3]+manyi[q+1][2])>manyi[q][1]+manyi[q+1][2]&&(manyi[q][3]+manyi[q+1][1]||manyi[q][3]+manyi[q+1][2])>manyi[q][1]+manyi[q+1][2]&&cr<=n/2-1){
				add+=manyi[q][3];
				cr+=1;
			}else if(manyi[q][2]>manyi[q][3]&&(manyi[q][3]+manyi[q+1][1]||manyi[q][3]+manyi[q+1][2])>manyi[q][2]+manyi[q+1][1]&&(manyi[q][3]+manyi[q+1][1]||manyi[q][3]+manyi[q+1][2])>manyi[q][2]+manyi[q+1][3]&&cr<=n/2-1){
				add+=manyi[q][3];
				cr+=1;
			}else*/
			
			
			
			if(manyi[q][1]>manyi[q][2]&&manyi[q][1]>manyi[q][3]&&manyi[q][1]>=manyi[q+1][1]&&manyi[q][1]>=manyi[q+2][1]&&manyi[q][1]>=manyi[q+3][1]&&ar<=n/2-1){
				add+=manyi[q][1];
				ar+=1;
			}else if(manyi[q][2]>manyi[q][1]&&manyi[q][2]>manyi[q][3]&&manyi[q][2]>=manyi[q+1][2]&&manyi[q][2]>=manyi[q+2][2]&&manyi[q][2]>=manyi[q+3][2]&&br<=n/2-1){
				add+=manyi[q][2];
				br+=1;
			}else if(manyi[q][3]>manyi[q][1]&&manyi[q][3]>manyi[q][2]&&manyi[q][3]>=manyi[q+1][3]&&manyi[q][3]>=manyi[q+2][3]&&manyi[q][3]>=manyi[q+3][3]&&cr<=n/2-1){
				add+=manyi[q][3];
				cr+=1;
			}else if(manyi[q][1]>manyi[q][2]&&manyi[q][1]>manyi[q][3]&&ar<=n/2-1&&manyi[q][1]+manyi[q+1][2]>manyi[q][2]+manyi[q+1][1]&&manyi[q][1]+manyi[q+1][2]>manyi[q][3]+manyi[q+1][1]){
				add+=manyi[q][1];
				ar+=1;
			}else if(manyi[q][1]>manyi[q][2]&&manyi[q][1]>manyi[q][3]&&ar<=n/2-1&&manyi[q][1]+manyi[q+1][3]>manyi[q][2]+manyi[q+1][1]&&manyi[q][1]+manyi[q+1][3]>manyi[q][3]+manyi[q+1][1]){
				add+=manyi[q][1];
				ar+=1;
			}else if(manyi[q][2]>manyi[q][1]&&manyi[q][2]>manyi[q][3]&&br<=n/2-1&&manyi[q][2]+manyi[q+1][1]>manyi[q][1]+manyi[q+1][2]&&manyi[q][2]+manyi[q+1][1]>manyi[q][3]+manyi[q+1][2]){
				add+=manyi[q][2];
				br+=1;
			}else if(manyi[q][2]>manyi[q][1]&&manyi[q][2]>manyi[q][3]&&br<=n/2-1&&manyi[q][2]+manyi[q+1][3]>manyi[q][1]+manyi[q+1][2]&&manyi[q][2]+manyi[q+1][3]>manyi[q][3]+manyi[q+1][2]){
				add+=manyi[q][2];
				br+=1;
			}else if(manyi[q][3]>manyi[q][1]&&manyi[q][3]>manyi[q][2]&&cr<=n/2-1&&manyi[q][3]+manyi[q+1][1]>manyi[q][1]+manyi[q+1][2]&&manyi[q][3]+manyi[q+1][1]>manyi[q][2]+manyi[q+1][3]){
				add+=manyi[q][3];
				cr+=1;
			}else if(manyi[q][3]>manyi[q][1]&&manyi[q][3]>manyi[q][2]&&cr<=n/2-1&&manyi[q][3]+manyi[q+1][2]>manyi[q][1]+manyi[q+1][2]&&manyi[q][3]+manyi[q+1][2]>manyi[q][2]+manyi[q+1][3]){
				add+=manyi[q][3];
				cr+=1;
			}else if(manyi[q][1]>manyi[q][2]&&manyi[q][1]>manyi[q][3]&&ar<=n/2-1){
				add+=manyi[q][1];
				ar+=1;
			}else if(manyi[q][2]>manyi[q][1]&&manyi[q][2]>manyi[q][3]&&br<=n/2-1){
				add+=manyi[q][2];
				br+=1;
			}else if(manyi[q][3]>manyi[q][1]&&manyi[q][3]>manyi[q][2]&&cr<=n/2-1){
				add+=manyi[q][3];
				cr+=1;
			}
			
			/*else if(manyi[q+1][1]==0&&manyi[q+1][2]==0){
				add+=manyi[q+1][3];
				cr+=1;
			}else if(manyi[q+1][2]==0&&manyi[q+1][3]==0){
				add+=manyi[q+1][1];
				ar+=1;
			}else if(manyi[q+1][3]==0&&manyi[q+1][1]==0){
				add+=manyi[q+1][3];
				br+=1;
			}*/
			
				
			}
		cout<<add<<endl;
	}
return 0;
}
