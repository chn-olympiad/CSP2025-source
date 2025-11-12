#include<iostream>
#include<vector>
using namespace std;

int a[100000][3];
int n;
int half;
int paixu[100000][3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		half=n/2;
		/*int big=0;
		
		abc(0,0,num);
		
		for(int i=0;i<k.size();i++){
			big=max(big,k[i]);
		}
		if(t1==0){
			cout<<big;
		}
		else{
			cout<<endl<<big;
		}
		k.clear();
	}*/
		for(int i=0;i<n;i++){
			if(a[i][0]>=a[i][1] &&a[i][1]>=a[i][2]){
				paixu[i][0]=0;paixu[i][1]=1;paixu[i][2]=2;
			}
			else if(a[i][0]>=a[i][2] &&a[i][2]>=a[i][1]){
				paixu[i][0]=0;paixu[i][1]=2;paixu[i][2]=1;
			} 
			else if(a[i][1]>=a[i][0] &&a[i][0]>=a[i][2]){
				paixu[i][0]=1;paixu[i][1]=0;paixu[i][2]=2;
			} 
			else if(a[i][1]>=a[i][2] &&a[i][2]>=a[i][0]){
				paixu[i][0]=1;paixu[i][1]=2;paixu[i][2]=0;
			}
			else if(a[i][2]>=a[i][1] &&a[i][1]>=a[i][0]){
				paixu[i][0]=2;paixu[i][1]=0;paixu[i][2]=1;
			}
			else if(a[i][2]>=a[i][0] &&a[i][0]>=a[i][1]){
				paixu[i][0]=2;paixu[i][1]=1;paixu[i][2]=0;
			}
		} 
		int count=0;
		int num[3]={0,0,0};
		int c1=0;
		for(int i=0;i<n;i++){
			if(num[paixu[i][0]]+1>half){
				{
					if(a[i][paixu[i][1]]+a[c1][paixu[c1][0]] < a[c1][paixu[c1][1]]+a[i][paixu[i][0]]){
						count-=a[c1][paixu[c1][0]];
						num[paixu[i][0]]-=1;
						count=count+a[c1][paixu[c1][1]]+a[i][paixu[i][0]];
						num[paixu[i][0]]+=1;
						num[paixu[c1][1]]+=1;
					}
					else{
						count+=a[i][paixu[i][1]];
						num[paixu[i][1]]+=1;

					}
				}
			}
			else{
				count+=a[i][paixu[i][0]];
				num[paixu[i][0]]+=1;
				c1=i;
			}
		}
		if(t1==0){
			cout<<count;
		}
		else{
			cout<<endl<<count;
		}
		
	
	}
	return 0;
} 