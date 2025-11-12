#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long k = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			for(int t = j+1;t<=n;t++){
				if(a[i]+a[j]+a[t]>max(a[i],max(a[j],a[t]))*2){
					k++;
				}
			}
		}
	}
	if(n>=4){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		if(a[i]+a[j]+a[t]+a[l]>max(a[i],max(a[j],max(a[t],a[l])))*2){
				            k++;
				        }
				        if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        	break;
						}
			    }
			    if(i == n-3){
				        	break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=5){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			if(a[i]+a[j]+a[t]+a[l]+a[p]>max(a[i],max(a[j],max(a[t],max(a[l],a[p]))))*2){
				                k++;
				            }
				            if(i == n-3){
				        	    break;
						    }
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        	break;
					}
			    }
			    if(i == n-3){
				        	break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=6){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],a[u])))))*2){
				                    k++;
				                }
				                if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        	break;
					}
			    }
			    if(i == n-3){
				        	break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=7){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],a[o]))))))*2){
				                         k++;
				                    }
				                    if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=8){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],a[y])))))))*2){
				                            k++;
				                        }
				                        if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=9){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],a[x]))))))))*2){
				                                k++;
				                            }
				                            if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=10){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],a[r])))))))))*2){
				                                    k++;
				                                }
				                                if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=11){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],a[e]))))))))))*2){
				                                        k++;
				                                    }
				                                    if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=12){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],a[w])))))))))))*2){
				                                            k++;
				                                        }
				                                        if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=13){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										for(int q = w+1;q<=n;q++){
			    											if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]+a[q]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],max(a[w],a[q]))))))))))))*2){
				                                                k++;
				                                            }
				                                            if(i == n-3){
				        	                                    break;
						                                    }
														}
														if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=14){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										for(int q = w+1;q<=n;q++){
			    											for(int s = q+1;s<=n;s++){
			    												if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]+a[q]+a[s]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],max(a[w],max(a[q],a[s])))))))))))))*2){
				                                                    k++;
				                                                }
				                                                if(i == n-3){
				        	                                        break;
						                                        }
															}
															if(i == n-3){
				        	                                    break;
						                                    }
														}
														if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=15){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										for(int q = w+1;q<=n;q++){
			    											for(int s = q+1;s<=n;s++){
			    												for(int d = s+1;d<=n;d++){
			    													if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]+a[q]+a[s]+a[d]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],max(a[w],max(a[q],max(a[s],a[d]))))))))))))))*2){
				                                                        k++;
				                                                    }
				                                                    if(i == n-3){
				        	                                            break;
						                                            }
																}
																if(i == n-3){
				        	                                        break;
						                                        }
															}
															if(i == n-3){
				        	                                    break;
						                                    }
														}
														if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=16){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										for(int q = w+1;q<=n;q++){
			    											for(int s = q+1;s<=n;s++){
			    												for(int d = s+1;d<=n;d++){
			    													for(int f = d+1;f<=n;f++){
			    														if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]+a[q]+a[s]+a[d]+a[f]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],max(a[w],max(a[q],max(a[s],max(a[d],a[f])))))))))))))))*2){
				                                                            k++;
				                                                        }
				                                                        if(i == n-3){
				        	                                                break;
						                                                }
																	}
																	if(i == n-3){
				        	                                            break;
						                                            }
																}
																if(i == n-3){
				        	                                        break;
						                                        }
															}
															if(i == n-3){
				        	                                    break;
						                                    }
														}
														if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=17){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										for(int q = w+1;q<=n;q++){
			    											for(int s = q+1;s<=n;s++){
			    												for(int d = s+1;d<=n;d++){
			    													for(int f = d+1;f<=n;f++){
			    														for(int g = f+1;g<=n;g++){
			    															if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]+a[q]+a[s]+a[d]+a[f]+a[g]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],max(a[w],max(a[q],max(a[s],max(a[d],max(a[f],a[g]))))))))))))))))*2){
				                                                                k++;
				                                                            }
				                                                            if(i == n-3){
				        	                                                    break;
						                                                    }
																		}
																		if(i == n-3){
				        	                                                break;
						                                                }
																	}
																	if(i == n-3){
				        	                                            break;
						                                            }
																}
																if(i == n-3){
				        	                                        break;
						                                        }
															}
															if(i == n-3){
				        	                                    break;
						                                    }
														}
														if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=18){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										for(int q = w+1;q<=n;q++){
			    											for(int s = q+1;s<=n;s++){
			    												for(int d = s+1;d<=n;d++){
			    													for(int f = d+1;f<=n;f++){
			    														for(int g = f+1;g<=n;g++){
			    															for(int h = g+1;h<=n;h++){
			    																if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]+a[q]+a[s]+a[d]+a[f]+a[g]+a[h]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],max(a[w],max(a[q],max(a[s],max(a[d],max(a[f],max(a[g],a[h])))))))))))))))))*2){
				                                                                    k++;
				                                                                }
				                                                                if(i == n-3){
				        	                                                        break;
						                                                        }
																			}
																			if(i == n-3){
				        	                                                    break;
						                                                    }
																		}
																		if(i == n-3){
				        	                                                break;
						                                                }
																	}
																	if(i == n-3){
				        	                                            break;
						                                            }
																}
																if(i == n-3){
				        	                                        break;
						                                        }
															}
															if(i == n-3){
				        	                                    break;
						                                    }
														}
														if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=19){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										for(int q = w+1;q<=n;q++){
			    											for(int s = q+1;s<=n;s++){
			    												for(int d = s+1;d<=n;d++){
			    													for(int f = d+1;f<=n;f++){
			    														for(int g = f+1;g<=n;g++){
			    															for(int h = g+1;h<=n;h++){
			    																for(int z = h+1;z<=n;z++){
			    																	if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]+a[q]+a[s]+a[d]+a[f]+a[g]+a[h]+a[z]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],max(a[w],max(a[q],max(a[s],max(a[d],max(a[f],max(a[g],max(a[h],a[z]))))))))))))))))))*2){
				                                                                        k++;
				                                                                    }
				                                                                    if(i == n-3){
				        	                                                            break;
						                                                            }
																				}
																				if(i == n-3){
				        	                                                        break;
						                                                        }
																			}
																			if(i == n-3){
				        	                                                    break;
						                                                    }
																		}
																		if(i == n-3){
				        	                                                break;
						                                                }
																	}
																	if(i == n-3){
				        	                                            break;
						                                            }
																}
																if(i == n-3){
				        	                                        break;
						                                        }
															}
															if(i == n-3){
				        	                                    break;
						                                    }
														}
														if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	if(n>=20){
		for(int i = 1;i<=n;i++){
		    for(int j = i+1;j<=n;j++){
			    for(int t = j+1;t<=n;t++){
			    	for(int l = t+1;l<=n;l++){
			    		for(int p = l+1;p<=n;p++){
			    			for(int u = p+1;u<=n;u++){
			    				for(int o = u+1;o<=n;o++){
			    					for(int y = o+1;y<=n;y++){
			    						for(int x = y+1;x<=n;x++){
			    							for(int r = x+1;r<=n;r++){
			    								for(int e = r+1;e<=n;e++){
			    									for(int w = e+1;w<=n;w++){
			    										for(int q = w+1;q<=n;q++){
			    											for(int s = q+1;s<=n;s++){
			    												for(int d = s+1;d<=n;d++){
			    													for(int f = d+1;f<=n;f++){
			    														for(int g = f+1;g<=n;g++){
			    															for(int h = g+1;h<=n;h++){
			    																for(int z = h+1;z<=n;z++){
			    																	for(int c = z+1;c<=n;c++){
			    																		if(a[i]+a[j]+a[t]+a[l]+a[p]+a[u]+a[o]+a[y]+a[x]+a[r]+a[e]+a[w]+a[q]+a[s]+a[d]+a[f]+a[g]+a[h]+a[z]+a[c]>max(a[i],max(a[j],max(a[t],max(a[l],max(a[p],max(a[u],max(a[o],max(a[y],max(a[x],max(a[r],max(a[e],max(a[w],max(a[q],max(a[s],max(a[d],max(a[f],max(a[g],max(a[h],max(a[z],a[c])))))))))))))))))))*2){
				                                                                            k++;
				                                                                        }
				                                                                        if(i == n-3){
				        	                                                                break;
						                                                                }
																					}
																					if(i == n-3){
				        	                                                            break;
						                                                            }
																				}
																				if(i == n-3){
				        	                                                        break;
						                                                        }
																			}
																			if(i == n-3){
				        	                                                    break;
						                                                    }
																		}
																		if(i == n-3){
				        	                                                break;
						                                                }
																	}
																	if(i == n-3){
				        	                                            break;
						                                            }
																}
																if(i == n-3){
				        	                                        break;
						                                        }
															}
															if(i == n-3){
				        	                                    break;
						                                    }
														}
														if(i == n-3){
				        	                                break;
						                                }
													}
													if(i == n-3){
				        	                            break;
						                            }
												}
												if(i == n-3){
				        	                        break;
						                        }
											}
											if(i == n-3){
				        	                    break;
						                    }
										}
										if(i == n-3){
				        	                break;
						                }
									}
									if(i == n-3){
				        	            break;
						            }
								}
								if(i == n-3){
				        	        break;
						        }
							}
							if(i == n-3){
				        	    break;
							}
						}
						if(i == n-3){
				        	break;
						}
					}
					if(i == n-3){
				        break;
					}
			    }
			    if(i == n-3){
				    break;
			    }
		    }
		    if(i == n-3){
				break;
		    }
	    }
	}
	//QAQ
	//AC
	//叽里咕噜说啥呢？跟我的暴力枚举说去吧 
	cout<<k;
}

