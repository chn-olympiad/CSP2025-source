#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int m[n],f=0,z=0,d;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int l=j+1;l<n;l++){
				z=m[i]+m[j]+m[l];
				if(m[i]>m[j]){
					if(m[i]>m[l]){
						d=m[i];
					}else{
						d=m[l];
					}
				}else{
					if(m[j]>m[l]){
						d=m[j];
					}else{
						d=m[l];
					}
				}
				if(z>d*2){
					f++;
					cout<<m[i]<<' '<<m[j]<<' '<<m[l]<<endl;
				}
			}	
		}
	}
	if(n>3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int l=j+1;l<n;l++){
					for(int h=l+1;h<n;h++){
						z=m[i]+m[j]+m[l]+m[h];
						if(m[i]>m[j]){
							if(m[i]>m[l]){
								if(m[i]>m[h]){
									d=m[i];
								}else{
									d=m[h];
								}
							}else{
								if(m[h]>m[l]){
									d=m[h];
								}else{
									d=m[l];
								}
							}
						}else{
							if(m[j]>m[l]){
								if(m[j]>m[h]){
									d=m[j];
								}else{
									d=m[h];
								}
							}else{
								if(m[h]>m[l]){
									d=m[h];
								}else{
									d=m[l];
								}
							}
						}
						if(z>d*2){
							f++;
						
						}
					}
				}	
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int l=j+1;l<n;l++){
				for(int h=l+1;h<n;h++){
					z=m[i]+m[j]+m[l]+m[h];
					if(m[i]>m[j]){
						if(m[i]>m[l]){
							if(m[i]>m[h]){
								d=m[i];
							}else{
								d=m[h];
							}
						}else{
							if(m[h]>m[l]){
								d=m[h];
							}else{
								d=m[l];
							}
						}
					}else{
						if(m[j]>m[l]){
							if(m[j]>m[h]){
								d=m[j];
							}else{
								d=m[h];
							}
						}else{
							if(m[h]>m[l]){
								d=m[h];
							}else{
								d=m[l];
							}
						}
					}
					if(h>d*2){
						f++;
						
					}
				}
			}	
		}
	}
	
	if(n>4){
		d=0;
		for(int i=0;i<n;i++){
			z+=m[i];
			if(m[i]>d){
				d=m[i];
			}
		}
		if(z>d*2){
			f++;
		}
	
	}


	cout<<f;
	
	return 0;
}




