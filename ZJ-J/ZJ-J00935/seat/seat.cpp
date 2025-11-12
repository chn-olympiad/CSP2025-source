#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num=n*m;
    int a[num];
    for (int i=0;i<num;i++){
    	cin>>a[i];
	}
	int xm=a[0];
	int t;
	for (int i=0;i<num;i++){
		for (int j=i;j<num;j++){
			if (a[i]<a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	int zx=1,zy=1;
	int fx=1;
	for (int i=0;i<num;i++){
		if (a[i]==xm) {
			cout<<zx<<" "<<zy;
			break;
		}
    	zy+=fx;
    	if (zy==n+1 || zy==0){
    		fx=-fx;
    		zy+=fx;
    		zx+=1;
		}
	}
    return 0;
}

