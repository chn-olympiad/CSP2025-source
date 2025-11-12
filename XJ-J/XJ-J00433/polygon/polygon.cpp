#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,b=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
	for(int y=i;y<=i;y++){
		for(int j=0;j<=i;j++){
			for(int x=0;x<=j;x++){
			if(a[y]+a[x]>a[j]&&a[j]+a[x]>a[y]){
				b++;
			}	}	}	}
	for(int f=i;f<=n;f++){
		for(int c=0;c<=f;c++){
			for(int d=0;d<=c;d++){
				for(int e=0;e<=d;e++){
			if(a[f]+a[c]>a[d]+a[e]&&a[c]+a[d]>a[f]+a[e]){
				b++;
			}	}	}	}	}
		for(int g=i;g<=n;g++){
			for(int h=0;h<=g;h++){
				for(int k=0;k<=h;k++){			
					for(int l=0;l<=k;l++){
						for(int m=0;m<=l;m++){
			if(a[g]+a[h]>a[k]+a[l]&&a[l]+a[m]>a[l]+a[h]){
				b++;
			}	}	}	}	}	}	}	
	cout<<b;
	return 0;}
