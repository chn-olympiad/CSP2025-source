#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int a[114514], choose[114514];
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if ((a[i]+a[j]+a[k]) >= a[k] * 2 && a[i]+a[j]>a[k]){
					ans++;
					ans %= MOD;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					if ((a[i]+a[j]+a[k]+a[l]) >= a[l] * 2 && a[i]+a[j]+a[k]>a[l]){
						ans++;
						ans %= MOD;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						if ((a[i]+a[j]+a[k]+a[l]+a[m]) >= a[m] * 2 && a[i]+a[j]+a[k]+a[l]>a[m]){
							ans++;
							ans %= MOD;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]) >= a[o] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]>a[o]){
								ans++;
								ans %= MOD;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]) >= a[p] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[p]){
									ans++;
									ans %= MOD;
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]) >= a[q] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>a[q]){
										ans++;
										ans %= MOD;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]) >= a[r] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>a[r]){
											ans++;
											ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]) >= a[s] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>a[s]){
												ans++;
												ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]) >= a[t] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>a[t]){
													ans++;
													ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]) >= a[u] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]>a[u]){
														ans++;
														ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]) >= a[v] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]>a[v]){
															ans++;
															ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														for (int w = v + 1; w <= n; w++) {
															if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]) >= a[w] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]>a[w]){
																ans++;
																ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														for (int w = v + 1; w <= n; w++) {
															for (int x = w + 1; x <= n; x++) {
																if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]) >= a[x] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]>a[x]){
																	ans++;
																	ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														for (int w = v + 1; w <= n; w++) {
															for (int x = w + 1; x <= n; x++) {
																for (int y = x + 1; y <= n; y++) {
																	if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]) >= a[y] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]>a[y]){
																		ans++;
																		ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														for (int w = v + 1; w <= n; w++) {
															for (int x = w + 1; x <= n; x++) {
																for (int y = x + 1; y <= n; y++) {
																	for (int z = y + 1; z <= n; z++) {
																		if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]) >= a[z] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]>a[z]){
																			ans++;
																			ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														for (int w = v + 1; w <= n; w++) {
															for (int x = w + 1; x <= n; x++) {
																for (int y = x + 1; y <= n; y++) {
																	for (int z = y + 1; z <= n; z++) {
																		for (int aa = z + 1; aa <= n; aa++) {
																			if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[aa]) >= a[aa] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]>a[aa]){
																				ans++;
																				ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														for (int w = v + 1; w <= n; w++) {
															for (int x = w + 1; x <= n; x++) {
																for (int y = x + 1; y <= n; y++) {
																	for (int z = y + 1; z <= n; z++) {
																		for (int aa = z + 1; aa <= n; aa++) {
																			for (int ab = aa + 1; ab <= n; ab++) {
																				if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[aa]+a[ab]) >= a[ab] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[aa]>a[ab]){
																					ans++;
																					ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														for (int w = v + 1; w <= n; w++) {
															for (int x = w + 1; x <= n; x++) {
																for (int y = x + 1; y <= n; y++) {
																	for (int z = y + 1; z <= n; z++) {
																		for (int aa = z + 1; aa <= n; aa++) {
																			for (int ab = aa + 1; ab <= n; ab++) {
																				for (int ac = ab + 1; ac <= n; ac++) {
																					if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[aa]+a[ab]+a[ac]) >= a[ac] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[aa]+a[ab]>a[ac]){
																						ans++;
																						ans %= MOD;
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int o = m + 1; o <= n; o++) {
							for (int p = o + 1; p <= n; p++) {
								for (int q = p + 1; q <= n; q++) {
									for (int r = q + 1; r <= n; r++) {
										for (int s = r + 1; s <= n; s++) {
											for (int t = s + 1; t <= n; t++) {
												for (int u = t + 1; u <= n; u++) {
													for (int v = u + 1; v <= n; v++) {
														for (int w = v + 1; w <= n; w++) {
															for (int x = w + 1; x <= n; x++) {
																for (int y = x + 1; y <= n; y++) {
																	for (int z = y + 1; z <= n; z++) {
																		for (int aa = z + 1; aa <= n; aa++) {
																			for (int ab = aa + 1; ab <= n; ab++) {
																				for (int ac = ab + 1; ac <= n; ac++) {
																					for (int end = ac + 1; end <= n; end++) {
																						if ((a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[aa]+a[ab]+a[ac]+a[end]) >= a[end] * 2 && a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[aa]+a[ab]+a[ac]>a[end]){
																							ans++;
																							ans %= MOD;
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
	}
	
	cout << ans;
	
	
	
	
	
	return 0;
}
