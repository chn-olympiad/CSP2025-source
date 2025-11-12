#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int c=0;
	int d=0;
	int e=0;
	int z=0;
	int y=0;
	cin>>c>>d>>e;
	long long a[1000];
	long long b[1000];
	long long f[1000];
	for(int i=0;i<1000;i++){
		a[i]=0;
		b[i]=0;
		f[i]=0;
	}
	
	for(int i=0;i<d;i++){
		cin>>a[i]>>b[i]>>f[i];
	}
	for(int j=0;j<e;j++){
		
		for(int k=0;k<c+1;k++){
			cin>>z;
			z=0;
		}
	}
	for(int i=0;i<d;i++){
		y=y+f[i];
	}
	//for(int i=0;i<c;i++){
		//for(int j=0;j<c;j++){
			//if(i=j){
				
			//}else{
				//if(a[i]=a[j]){
					//if(f[i]>=f[j]){
						//f[i]=0;
						//y=y+f[j];
					//}else{
						//f[j]=0;
						//y=y+f[i];
					//}
				//}
			//}
		//}
	//}
	cout<<y;
	return 0;
}

