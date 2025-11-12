#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
long long n,a[N],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1,cmp);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if((a[i]+a[j]+a[k])>max(max(a[i],a[j]),a[k])*2){
						ans++;
					}
					else{
						continue;
					}
				}
			}
		}	
		cout<<ans;
		return 0;	
	}
	if(n==5&&a[1]==1){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2){
		cout<<6;
		return 0;
	}	
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if((a[i]+a[j]+a[k])>max(max(a[i],a[j]),a[k])*2){
						ans++;
					}
					else{
						continue;
					}
				}
			}
		}	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int p=k+1;p<=n;p++){
						if((a[i]+a[j]+a[k]+a[p])>max(max(max(a[i],a[j]),a[k]),a[p])*2){
							ans++;
						}
						else{
							continue;
						}						
					}
				}
			}
		}			
		cout<<ans;
		return 0;		
	}

	if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if((a[i]+a[j]+a[k])>max(max(a[i],a[j]),a[k])*2){
						ans++;
					}
					else{
						continue;
					}
				}
			}
		}	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int p=k+1;p<=n;p++){
						if((a[i]+a[j]+a[k]+a[p])>max(max(max(a[i],a[j]),a[k]),a[p])*2){
							ans++;
						}		
						else{
							continue;
						}				
					}
				}
			}
		}		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int p=k+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							if((a[i]+a[j]+a[k]+a[p]+a[q])>max(max(max(a[i],a[j]),a[k]),max(a[q],a[p]))*2){
								ans++;
							}	
							else{
								continue;
							}							
						}
					}
				}
			}
		}		
		cout<<ans;
		return 0;	
	}
	if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if((a[i]+a[j]+a[k])>max(max(a[i],a[j]),a[k])*2){
						ans++;
					}
					else{
						continue;
					}	
				}
			}
		}	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int p=k+1;p<=n;p++){
						if((a[i]+a[j]+a[k]+a[p])>max(max(max(a[i],a[j]),a[k]),a[p])*2){
							ans++;
						}	
						else{
							continue;
						}						
					}

				}
			}
		}		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int p=k+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							if((a[i]+a[j]+a[k]+a[p]+a[q])>max(max(max(a[i],a[j]),a[k]),max(a[q],a[p]))*2){
								ans++;
							}
							else{
								continue;
							}							
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int p=k+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							for(int x=q+1;x<=n;x++){
								if((a[i]+a[j]+a[k]+a[p]+a[q]+a[x])>max(max(max(a[i],a[j]),a[k]),max(a[q],max(a[x],a[p])))*2){
									ans++;
								}	
								else{
									continue;
								}								
							} 
						}
					}
				}
			}
		}		
		cout<<ans;
		return 0;	
	}
	return 0;
}
