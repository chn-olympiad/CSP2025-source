#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,maxfeel[6],a1m,a2m,a3m;
struct node{
	int a1,a2,a3;
}feel[6][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>feel[i][j].a1>>feel[i][j].a2>>feel[i][j].a3;
			if(feel[i][j].a1>feel[i][j].a2&&feel[i][j].a1>feel[i][j].a3){
				if(a1m<n/2){
					a1m++;
					maxfeel[i]+=feel[i][j].a1;
				}else if(a1m>n/2){
					if(feel[i][j].a2>feel[i][j].a3&&a2m<n/2){
						a2m++;
						maxfeel[i]+=feel[i][j].a2;
					}else if(a2m>n/2){
						a3m++;
						maxfeel[i]+=feel[i][j].a3;
					}
					if(feel[i][j].a2<feel[i][j].a3&&a3m<n/2){
						a3m++;
						maxfeel[i]+=feel[i][j].a3;
					}else if(a3m>n/2){
						a2m++;
						maxfeel[i]+=feel[i][j].a2;
					}
				} 
			}
			if(feel[i][j].a2>feel[i][j].a1&&feel[i][j].a2>feel[i][j].a3){
				if(a2m<n/2){
					a2m++;
					maxfeel[i]+=feel[i][j].a2;
				}else if(a2m>n/2){
					if(feel[i][j].a1>feel[i][j].a3&&a1m<n/2){
						a1m++;
						maxfeel[i]+=feel[i][j].a1;
					}else if(a1m>n/2){
						a3m++;
						maxfeel[i]+=feel[i][j].a3;
					}
					if(feel[i][j].a1<feel[i][j].a3&&a3m<n/2){
						a3m++;
						maxfeel[i]+=feel[i][j].a3;
					}else if(a3m>n/2){
						a1m++;
						maxfeel[i]+=feel[i][j].a1;
					}
				}
			}
			if(feel[i][j].a3>feel[i][j].a1&&feel[i][j].a3>feel[i][j].a2){
				if(a3m<n/2){
					a3m++;
					maxfeel[i]+=feel[i][j].a3;
				}else if(a3m>n/2){
					if(feel[i][j].a1>feel[i][j].a2&&a1m<n/2){
						a1m++;
						maxfeel[i]+=feel[i][j].a1;
					}else if(a1m>n/2){
						a2m++;
						maxfeel[i]+=feel[i][j].a2;
					}
					if(feel[i][j].a1<feel[i][j].a2&&a2m<n/2){
						a2m++;
						maxfeel[i]+=feel[i][j].a2;
					}else if(a3m>n/2){
						a1m++;
						maxfeel[i]+=feel[i][j].a1;
					}
				}
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<maxfeel[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
