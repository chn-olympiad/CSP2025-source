#include <bits/stdc++.h>
using namespace std;
int n,arr[5005],ans;
void xuan(int a){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a>3){
					for(int l=k+1;l<=n;l++){
						if(a>4){
							for(int u=l+1;u<=n;u++){
								if(a>5){
									for(int o=u+1;o<=n;o++){
										if(a>6){
											for(int p=o+1;p<=n;p++){
												if(a>7){
													for(int q=p+1;q<=n;q++){
														if(a>8){
															for(int w=q+1;w<=n;w++){
																if(a>9){
																	for(int e=w+1;e<=n;e++){
																		int m=max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[u],max(arr[o],max(arr[p],max(arr[q],max(arr[w],arr[e])))))))));
																		if(arr[i]+arr[j]+arr[k]+arr[l]+arr[u]+arr[o]+arr[p]+arr[q]+arr[w]+arr[e]>2*m){
																			ans++;
																		}
																	}
																}else{
																	int m=max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[u],max(arr[o],max(arr[p],max(arr[q],arr[w]))))))));
																	if(arr[i]+arr[j]+arr[k]+arr[l]+arr[u]+arr[o]+arr[p]+arr[q]+arr[w]>2*m){
																		ans++;
																	}
																}
															}
														}else{
															int m=max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[u],max(arr[o],max(arr[p],arr[q])))))));
															if(arr[i]+arr[j]+arr[k]+arr[l]+arr[u]+arr[o]+arr[p]+arr[q]>2*m){
																ans++;
															}
														}
													}
												}else{
													int m=max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[u],max(arr[o],arr[p]))))));
													if(arr[i]+arr[j]+arr[k]+arr[l]+arr[u]+arr[o]+arr[p]>2*m){
														ans++;
													}
												}
											}
										}else{
											int m=max(arr[i],max(arr[j],max(arr[k],max(arr[l],max(arr[u],arr[o])))));
											if(arr[i]+arr[j]+arr[k]+arr[l]+arr[u]+arr[o]>2*m){
												ans++;
											}
										}
									}
								}else{
									int m=max(arr[i],max(arr[j],max(arr[k],max(arr[l],arr[u]))));
									if(arr[i]+arr[j]+arr[k]+arr[l]+arr[u]>2*m){
										ans++;
									}
								}
							}
						}else{
							int m=max(arr[i],max(arr[j],max(arr[k],arr[l])));
							if(arr[i]+arr[j]+arr[k]+arr[l]>2*m){
								ans++;
							}
						}
					}
				}else{
					int m=max(arr[i],max(arr[j],arr[k]));
					if(arr[i]+arr[j]+arr[k]>2*m){
						ans++;
					}
				}
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=3;i<=n;i++){
		xuan(i);
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
