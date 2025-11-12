#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int x=a[i]+a[j]+a[k];
				if(x>2*max(a[i],max(a[j],a[k]))){
					ans++;
				}
				for(int l=k+1;l<=n;l++){
					int x=a[i]+a[j]+a[k]+a[l];
					if(x>2*max(a[i],max(a[j],max(a[k],a[l])))){
						ans++;
					}
					for(int z=l+1;z<=n;z++){
						int x=a[i]+a[j]+a[k]+a[l]+a[z];
						if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],a[z]))))){
							ans++;
						}
						for(int c=z+1;c<=n;c++){
							int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c];
							if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],a[c])))))){
								ans++;
							}
							for(int v=c+1;v<=n;v++){
								int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v];
								if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],a[v]))))))){
									ans++;
								}
								for(int b=v+1;b<=n;b++){
									int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b];
									if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],a[b])))))))){
										ans++;
									}
									for(int q=b+1;q<=n;q++){
										int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q];
										if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],a[q]))))))))){
											ans++;
										}
										for(int w=q+1;w<=n;w++){
											int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w];
											if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],a[w])))))))))){
												ans++;
											}
											for(int e=w+1;e<=n;e++){
												int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e];
												if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],a[e]))))))))))){
													ans++;
												}
												for(int r=e+1;r<=n;r++){
													int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r];
													if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],a[r])))))))))))){
														ans++;
													}
													for(int t=r+1;t<=n;t++){
														int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r]+a[t];
														if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],max(a[r],a[t]))))))))))))){
															ans++;
														}
														for(int u=t+1;u<=n;u++){
															int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r]+a[t]+a[u];
															if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],a[u])))))))))))))){
																ans++;
															}
															for(int o=u+1;o<=n;o++){
																int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r]+a[t]+a[u]+a[o];
																if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[u],a[o]))))))))))))))){
																	ans++;
																}
																for(int p=o+1;p<=n;p++){
																	int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r]+a[t]+a[u]+a[o]+a[p];
																	if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[u],max(a[o],a[p])))))))))))))))){
																		ans++;
																	}
																	for(int s=p+1;s<=n;s++){
																		int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r]+a[t]+a[u]+a[o]+a[p]+a[s];
																		if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[u],max(a[o],max(a[p],a[s]))))))))))))))))){
																			ans++;
																		}
																		for(int d=s+1;d<=n;d++){
																			int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r]+a[t]+a[u]+a[o]+a[p]+a[s]+a[d];
																			if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[u],max(a[o],max(a[p],max(a[s],a[d])))))))))))))))))){
																				ans++;
																			}
																			for(int f=d+1;f<=n;f++){
																				int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r]+a[t]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f];
																				if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[u],max(a[o],max(a[p],max(a[s],max(a[d],a[f]))))))))))))))))))){
																					ans++;
																				}
																				for(int g=f+1;g<=n;g++){
																					int x=a[i]+a[j]+a[k]+a[l]+a[z]+a[c]+a[v]+a[b]+a[q]+a[w]+a[e]+a[r]+a[t]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g];
																					if(x>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(a[c],max(a[v],max(a[b],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[u],max(a[o],max(a[p],max(a[s],max(a[d],max(a[f],a[g])))))))))))))))))))){
																						ans++;
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
	cout<<ans%998224353;
	return 0;
}
