#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[505],x=0,y=0,z=0,m=0,v,q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x+=a[j];
			y++;
			z=a[j];
			if(x>z*2&&y>=3){
				m++;
				
			}
			q=z;
            for(int k=1;k<=n-j;k++){
		    	for(int l=1;l<y;l++){
					v=x+a[j+k]-a[j-l+1];
					q=a[j+k];
					if(v>2*q&&y>=3){
					    m++;
					}
				}
			}			
		}
		x=0;
		y=0;
		z=0;
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

