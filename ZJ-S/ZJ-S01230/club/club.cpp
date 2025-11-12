#include <iostream>
#include <stdio.h>
using namespace std;

int a[10000];
int b[10000];
int c[10000];
int d[10000];
int main(){
	//freopen("clud.in","r",stdin);
	//freopen("clud.out","w",stdout);
	int t;
	cin>>t;
	while(t!=0){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<n;i++){
			int v=a[i],e=1;
			if(v<b[i]){
				v=b[i];
				e=2;
			}
			if(v<c[i]){
				v=c[i];
				e=3;
			}
			d[i]=e;
		}
		int q1=0,w1=0,q2=0,w2=0,q3=0,w3=0;
		for(int i=0;i<n;i++){
			if(d[i]==1){
				q1++;
				w1+=a[i];
			}
			if(d[i]==2){
				q2++;
				w2+=b[i];
			}
			if(d[i]==3){
				q3++;
				w3+=c[i];
			}
		}
		
		
		t--;
	}
	return 0;
}
