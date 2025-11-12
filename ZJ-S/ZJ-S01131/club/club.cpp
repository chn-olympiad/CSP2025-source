#include<bits/stdc++.h>
using namespace std;
struct xl{
	int r1;
	int r2;
	int r3;
}r[300030];

bool cmp(xl x,xl y){
	if(x.r1>y.r1) return true;
	return false;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a=0,b=0;
		int ww[20];
		if(n==2){
			int j=1;
			for(int i=1;i<=2;i++){
				cin>>ww[j]>>ww[j+1]>>ww[j+2];
				j+=3;
		    }		
			int q1=0;
			if(ww[1]>ww[2] && ww[1]>ww[3]){
				q1=1;
			}
			else if(ww[2]>ww[1] && ww[2]>ww[3]){
				q1=2;
			}
			else{
				q1=3;
			}	
	
			int q2=0;			
			if(ww[4]>ww[5] && ww[4]>ww[6]){
				q2=1;
			}
			else if(ww[5]>ww[4] && ww[5]>ww[6]){
				q2=2;
			}
			else{
				q2=3;
			}	
			if(q1!=q2) a=ww[q1]+ww[q2+3];
 			else{
				int qq1=0;
				qq1+=ww[q1]+(ww[4]+ww[5]+ww[6])-ww[q2+3]-min(ww[4],min(ww[5],ww[6]));
				int qq2=0;
				qq2+=ww[q2+3]+(ww[1]+ww[2]+ww[3])-ww[q1]-min(ww[1],min(ww[2],ww[3]));
				a=max(qq1,qq2);
			}
			cout<<a<<endl;
		}
		else if(n==4){
			int t=0,tt=0,ttt=0;
			int j=1;
			for(int i=1;i<=4;i++){
				cin>>ww[j]>>ww[j+1]>>ww[j+2];
				j+=3;
		    }		
		    
			int q1=0;
			if(ww[1]>ww[2] && ww[1]>ww[3]){
				q1=1;
				t++;
			}
			else if(ww[2]>ww[1] && ww[2]>ww[3]){
				q1=2;
				tt++;
			}
			else{
				q1=3;
				ttt++;
			}	
	
			int q2=0;			
			if(ww[4]>ww[5] && ww[4]>ww[6]){
				q2=1;
				t++;
			}
			else if(ww[5]>ww[4] && ww[5]>ww[6]){
				q2=2;
				ttt++;
			}
			else{
				q2=3;
				tt++;
			}	
			
			int q3=0;			
			if(ww[7]>ww[8] && ww[7]>ww[9]){
				q3=1;
				t++;
			}
			else if(ww[8]>ww[7] && ww[8]>ww[9]){
				q3=2;
				tt++;
			}
			else{
				q3=3;
				ttt++;
			}	
			
			int q4=0;			
			if(ww[10]>ww[11] && ww[10]>ww[12]){
				q4=1;
				t++;
			}
			else if(ww[11]>ww[10] && ww[11]>ww[12]){
				q4=2;
				tt++;
			}
			else{
				q4=3;
				ttt++;
			}	
			
			if(t<=2 && tt<=2 && ttt<=2) a=ww[q1]+ww[q2+3]+ww[q3+6]+ww[q4+9];
 			else{
				int qq1=0;
				qq1+=ww[q1]+(ww[4]+ww[5]+ww[6])-ww[q2+3]-min(ww[4],min(ww[5],ww[6]))+ww[q3+6]+ww[q4+9];
				int qq2=0;
				qq2+=ww[q2+3]+(ww[1]+ww[2]+ww[3])-ww[q1]-min(ww[1],min(ww[2],ww[3]))+ww[q3+6]+ww[q4+9];
				int qq3=0;
				qq3+=ww[q1]+ww[q2+3]+(ww[7]+ww[8]+ww[9])-ww[q3+6]-min(ww[7],min(ww[8],ww[9]))+ww[q4+9];
				int qq4=0;
				qq4+=ww[q1]+ww[q2+3]+ww[q3+6]+(ww[10]+ww[11]+ww[12])-ww[q4+9]-min(ww[10],min(ww[11],ww[12]));
				a=max(qq1,max(qq2,max(qq3,qq4)));
			}
			cout<<a<<endl;
		}
		else{
			int c=0;
			for(int i=1;i<=n;i++){
				cin>>r[i].r1>>r[i].r2>>r[i].r3;
				b+=r[i].r2+r[i].r3;
				c+=max(r[i].r1,max(r[i].r2,r[i].r3));
		    }
			if(b==0){
				sort(r+1,r+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					a+=r[i].r1;
				}
			}else a=c;
			cout<<a<<endl;
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
}
