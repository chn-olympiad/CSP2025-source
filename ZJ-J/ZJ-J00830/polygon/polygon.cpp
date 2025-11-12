#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long num;
long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int cnt=max(max(a[i],a[j]),a[k]);
				if(a[i]+a[j]+a[k]>2*cnt){
					num++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					int cnt=max(max(a[i],a[j]),max(a[k],a[b]));
					if(a[i]+a[j]+a[k]+a[b]>2*cnt){
						num++;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					for(int c=b+1;c<n;c++){
						int cnt=max(max(max(a[i],a[j]),max(a[k],a[b])),a[c]);
					    if(a[i]+a[j]+a[k]+a[b]+a[c]>2*cnt){
						    num++;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					for(int c=b+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							int cnt=max(max(max(a[i],a[j]),max(a[k],a[b])),max(a[c],a[d]));
					    	if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]>2*cnt){
						    	num++;
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					for(int c=b+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							for(int e=d+1;e<n;e++){
								int cnt=max(max(max(a[i],a[j]),max(a[k],a[b])),max(max(a[c],a[d]),a[e]));
					    		if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]>2*cnt){
						    		num++;
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					for(int c=b+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							for(int e=d+1;e<n;e++){
								for(int f=e+1;f<n;f++){
									int cnt=max(max(max(a[i],a[j]),max(a[k],a[b])),max(max(a[c],a[d]),max(a[e],a[f])));
					    			if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]>2*cnt){
						    			num++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					for(int c=b+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							for(int e=d+1;e<n;e++){
								for(int f=e+1;f<n;f++){
									for(int g=f+1;g<n;g++){
										int cnt=max(max(max(a[i],a[j]),max(a[k],a[b])),max(max(a[c],a[d]),max(max(a[e],a[f]),a[g])));
					    				if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>2*cnt){
						    				num++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int b=k+1;b<n;b++){
					for(int c=b+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							for(int e=d+1;e<n;e++){
								for(int f=e+1;f<n;f++){
									for(int g=f+1;g<n;g++){
										for(int h=g+1;h<n;h++){
											int cnt=max(max(max(a[i],a[j]),max(a[k],a[b])),max(max(a[c],a[d]),max(max(a[e],a[f]),max(a[g],a[h]))));
					    					if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>2*cnt){
						    					num++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<num%mod;
	return 0;
}
