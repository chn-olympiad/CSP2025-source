#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e3+5;
const int mmod = 998244353;
int n, cnt, mmax, tmp;
int a[maxN];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				mmax = 0;
				tmp += a[k];
				mmax = max(mmax, max(a[i], max(a[j], a[k])));
				if (tmp > 2 * mmax) {
					cnt++;
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					mmax = 0;
					tmp += a[p];
					mmax = max(mmax, max(a[i], max(a[j], max(a[k], a[p]))));
					if (tmp > 2 * mmax) {
						cnt++;
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						mmax = 0;
						tmp += a[q];
						mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], a[q])))));
						if (tmp > 2 * mmax) {
							cnt++;
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							mmax = 0;
							tmp += a[r];
							mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], a[r]))))));
							if (tmp > 2 * mmax) {
								cnt++;
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								mmax = 0;
								tmp += a[w];
								mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], a[w])))))));
								if (tmp > 2 * mmax) {
									cnt++;
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									mmax = 0;
									tmp += a[v];
									mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], a[v]))))))));
									if (tmp > 2 * mmax) {
										cnt++;
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										mmax = 0;
										tmp += a[l];
										mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], a[l])))))))));
										if (tmp > 2 * mmax) {
											cnt++;
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											mmax = 0;
											tmp += a[m];
											mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
											                               a[m]))))))))));
											if (tmp > 2 * mmax) {
												cnt++;
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												mmax = 0;
												tmp += a[b];
												mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
												                               max(a[m], a[b])))))))))));
												if (tmp > 2 * mmax) {
													cnt++;
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													mmax = 0;
													tmp += a[c];
													mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
													                               max(a[m], max(a[b], a[c]))))))))))));
													if (tmp > 2 * mmax) {
														cnt++;
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													tmp += a[c];
													for (int d = c + 1; d <= n; d++) {
														mmax = 0;
														tmp += a[d];
														mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
														                               max(a[m], max(a[b], max(a[c], a[d])))))))))))));
														if (tmp > 2 * mmax) {
															cnt++;
														}
														tmp -= a[d];
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													tmp += a[c];
													for (int d = c + 1; d <= n; d++) {
														tmp += a[d];
														for (int e = d + 1; e <= n; e++) {
															mmax = 0;
															tmp += a[e];
															mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
															                               max(a[m], max(a[b], max(a[c], max(a[d], a[e]))))))))))))));
															if (tmp > 2 * mmax) {
																cnt++;
															}
															tmp -= a[e];
														}
														tmp -= a[d];
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													tmp += a[c];
													for (int d = c + 1; d <= n; d++) {
														tmp += a[d];
														for (int e = d + 1; e <= n; e++) {
															tmp += a[e];
															for (int f = e + 1; f <= n; f++) {
																mmax = 0;
																tmp += a[f];
																mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
																                               max(a[m], max(a[b], max(a[c], max(a[d], max(a[e], a[f])))))))))))))));
																if (tmp > 2 * mmax) {
																	cnt++;
																}
																tmp -= a[f];
															}
															tmp -= a[e];
														}
														tmp -= a[d];
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													tmp += a[c];
													for (int d = c + 1; d <= n; d++) {
														tmp += a[d];
														for (int e = d + 1; e <= n; e++) {
															tmp += a[e];
															for (int f = e + 1; f <= n; f++) {
																tmp += a[f];
																for (int g = f + 1; g <= n; g++) {
																	mmax = 0;
																	tmp += a[g];
																	mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
																	                               max(a[m], max(a[b], max(a[c], max(a[d], max(a[e], max(a[f], a[g]))))))))))))))));
																	if (tmp > 2 * mmax) {
																		cnt++;
																	}
																	tmp -= a[g];
																}
																tmp -= a[f];
															}
															tmp -= a[e];
														}
														tmp -= a[d];
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													tmp += a[c];
													for (int d = c + 1; d <= n; d++) {
														tmp += a[d];
														for (int e = d + 1; e <= n; e++) {
															tmp += a[e];
															for (int f = e + 1; f <= n; f++) {
																tmp += a[f];
																for (int g = f + 1; g <= n; g++) {
																	tmp += a[g];
																	for (int h = g + 1; h <= n; h++) {
																		mmax = 0;
																		tmp += a[h];
																		mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
																		                               max(a[m], max(a[b], max(a[c], max(a[d], max(a[e], max(a[f], max(a[g], a[h])))))))))))))))));
																		if (tmp > 2 * mmax) {
																			cnt++;
																		}
																		tmp -= a[h];
																	}
																	tmp -= a[g];
																}
																tmp -= a[f];
															}
															tmp -= a[e];
														}
														tmp -= a[d];
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													tmp += a[c];
													for (int d = c + 1; d <= n; d++) {
														tmp += a[d];
														for (int e = d + 1; e <= n; e++) {
															tmp += a[e];
															for (int f = e + 1; f <= n; f++) {
																tmp += a[f];
																for (int g = f + 1; g <= n; g++) {
																	tmp += a[g];
																	for (int h = g + 1; h <= n; h++) {
																		tmp += a[h];
																		for (int o = h + 1; o <= n; o++) {
																			mmax = 0;
																			tmp += a[o];
																			mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
																			                               max(a[m], max(a[b], max(a[c], max(a[d], max(a[e], max(a[f], max(a[g], max(a[h], a[o]))))))))))))))))));
																			if (tmp > 2 * mmax) {
																				cnt++;
																			}
																			tmp -= a[o];
																		}
																		tmp -= a[h];
																	}
																	tmp -= a[g];
																}
																tmp -= a[f];
															}
															tmp -= a[e];
														}
														tmp -= a[d];
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													tmp += a[c];
													for (int d = c + 1; d <= n; d++) {
														tmp += a[d];
														for (int e = d + 1; e <= n; e++) {
															tmp += a[e];
															for (int f = e + 1; f <= n; f++) {
																tmp += a[f];
																for (int g = f + 1; g <= n; g++) {
																	tmp += a[g];
																	for (int h = g + 1; h <= n; h++) {
																		tmp += a[h];
																		for (int o = h + 1; o <= n; o++) {
																			tmp += a[o];
																			for (int s = o + 1; s <= n; s++) {
																				mmax = 0;
																				tmp += a[s];
																				mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
																				                               max(a[m], max(a[b], max(a[c], max(a[d], max(a[e], max(a[f], max(a[g], max(a[h], max(a[o], a[s])))))))))))))))))));
																				if (tmp > 2 * mmax) {
																					cnt++;
																				}
																				tmp -= a[s];
																			}
																			tmp -= a[o];
																		}
																		tmp -= a[h];
																	}
																	tmp -= a[g];
																}
																tmp -= a[f];
															}
															tmp -= a[e];
														}
														tmp -= a[d];
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp += a[i];
		for (int j = i + 1; j <= n; j++) {
			tmp += a[j];
			for (int k = j + 1; k <= n; k++) {
				tmp += a[k];
				for (int p = k + 1; p <= n; p++) {
					tmp += a[p];
					for (int q = p + 1; q <= n; q++) {
						tmp += a[q];
						for (int r = q + 1; r <= n; r++) {
							tmp += a[r];
							for (int w = r + 1; w <= n; w++) {
								tmp += a[w];
								for (int v = w + 1; v <= n; v++) {
									tmp += a[v];
									for (int l = v + 1; l <= n; l++) {
										tmp += a[l];
										for (int m = l + 1; m <= n; m++) {
											tmp += a[m];
											for (int b = m + 1; b <= n; b++) {
												tmp += a[b];
												for (int c = b + 1; c <= n; c++) {
													tmp += a[c];
													for (int d = c + 1; d <= n; d++) {
														tmp += a[d];
														for (int e = d + 1; e <= n; e++) {
															tmp += a[e];
															for (int f = e + 1; f <= n; f++) {
																tmp += a[f];
																for (int g = f + 1; g <= n; g++) {
																	tmp += a[g];
																	for (int h = g + 1; h <= n; h++) {
																		tmp += a[h];
																		for (int o = h + 1; o <= n; o++) {
																			tmp += a[o];
																			for (int s = o + 1; s <= n; s++) {
																				tmp += a[s];
																				for (int t = s + 1; t <= n; t++) {
																					mmax = 0;
																					tmp += a[t];
																					mmax = max(mmax, max(a[i], max(a[j], max(a[k], max(a[p], max(a[q], max(a[r], max(a[w], max(a[v], max(a[l],
																					                               max(a[m], max(a[b], max(a[c], max(a[d], max(a[e], max(a[f], max(a[g], max(a[h], max(a[o], max(a[s],
																					                                   a[t]))))))))))))))))))));
																					if (tmp > 2 * mmax) {
																						cnt++;
																					}
																					tmp -= a[t];
																				}
																				tmp -= a[s];
																			}
																			tmp -= a[o];
																		}
																		tmp -= a[h];
																	}
																	tmp -= a[g];
																}
																tmp -= a[f];
															}
															tmp -= a[e];
														}
														tmp -= a[d];
													}
													tmp -= a[c];
												}
												tmp -= a[b];
											}
											tmp -= a[m];
										}
										tmp -= a[l];
									}
									tmp -= a[v];
								}
								tmp -= a[w];
							}
							tmp -= a[r];
						}
						tmp -= a[q];
					}
					tmp -= a[p];
				}
				tmp -= a[k];
			}
			tmp -= a[j];
		}
		tmp -= a[i];
	}
	printf("%d", cnt % mmod);
	return 0;
}
