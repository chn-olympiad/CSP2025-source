#include<bits/stdc++.h>
using namespace std;
int a[20000][10];
int b1[20000];
int b2[20000];
int b3[20000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		int x[6];
		x[1]=0;
		x[2]=0;
		x[3]=0;
		int tot=0,t1=1,t2=1,t3=1;
		for(int i=1;i<=k;i++){
			int ma=-1,p;
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
	
				if(a[i][j] > ma){
					p=j;
					ma=a[i][j];
				}
					
			}
			x[p]++;
			tot+=ma;
				
			if(p==1){
				b1[t1]=max(a[i][2]-ma,a[i][3]-ma);
				t1++;
			}
				
			if(p==2){
				b2[t2]=max(a[i][1]-ma,a[i][3]-ma);
				t2++;
			}
				
			if(p==3){
				b3[t3]=max(a[i][2]-ma,a[i][1]-ma);
				t3++;
			}
			
				
		}
		int mb=-1;
		mb=max(mb,x[1]);
		mb=max(mb,x[2]);
		mb=max(mb,x[3]);
		if(mb > k/2){
			sort(b1+1,b1+t1);
			sort(b2+1,b2+t2);
			sort(b3+1,b3+t3);
			if(mb==x[1]){
				for(int g=t1-1;g >=t1-mb + k/2;g-- ){
				tot+=b1[g];
				
			    }
			}
			if(mb==x[2]){
				for(int g=t2-1;g >=t2-mb + k/2;g-- ){
				tot+=b2[g];
				
				}
			}
			if(mb==x[3]){
				for(int g=t3-1;g >=t3-mb + k/2;g-- ){
				tot+=b3[g];
				
				}
			}
		
			cout<<tot<<endl;
		}else{
			cout<<tot<<endl;
		}
		
	}
	
	return 0;
}
