#include <bits/stdc++.h>
using namespace std;
int a[500005], sum, maxx = -1, ans, cnt = 0;
int b[500005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				b[++cnt] = a[i];
				b[++cnt] = a[j];
				b[++cnt] = a[k];
				for (int mmm = 1; mmm <= cnt; mmm++) {
					if (b[mmm] > maxx)
						maxx = b[mmm];
					sum += b[mmm];
				}
				if (maxx * 2 < sum)
					ans++;
				sum = cnt = 0;
				maxx = -1;
			}
		}
	}



	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					b[++cnt] = a[i];
					b[++cnt] = a[j];
					b[++cnt] = a[k];
					b[++cnt] = a[l];
					for (int mmm = 1; mmm <= cnt; mmm++) {
						if (b[mmm] > maxx)
							maxx = b[mmm];
						sum += b[mmm];
					}
					if (maxx * 2 < sum)
						ans++;
					sum = cnt = 0;
					maxx = -1;
				}
			}
		}
	}



	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						b[++cnt] = a[i];
						b[++cnt] = a[j];
						b[++cnt] = a[k];
						b[++cnt] = a[l];
						b[++cnt] = a[m];
						for (int mmm = 1; mmm <= cnt; mmm++) {
							if (b[mmm] > maxx)
								maxx = b[mmm];
							sum += b[mmm];
						}
						if (maxx * 2 < sum)
							ans++;
						sum = cnt = 0;
						maxx = -1;
					}
				}
			}
		}
	}


	if (n <= 3) {
		cout << ans;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int nn = m + 1; nn <= n; nn++) {
							b[++cnt] = a[i];
							b[++cnt] = a[j];
							b[++cnt] = a[k];
							b[++cnt] = a[l];
							b[++cnt] = a[m];
							b[++cnt] = a[nn];
							for (int mmm = 1; mmm <= cnt; mmm++) {
								if (b[mmm] > maxx)
									maxx = b[mmm];
								sum += b[mmm];
							}
							if (maxx * 2 < sum)
								ans++;
							sum = cnt = 0;
							maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								b[++cnt] = a[i];
								b[++cnt] = a[j];
								b[++cnt] = a[k];
								b[++cnt] = a[l];
								b[++cnt] = a[m];
								b[++cnt] = a[nn];
								b[++cnt] = a[o];
								for (int mmm = 1; mmm <= cnt; mmm++) {
									if (b[mmm] > maxx)
										maxx = b[mmm];
									sum += b[mmm];
								}
								if (maxx * 2 < sum)
									ans++;
								sum = cnt = 0;
								maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									b[++cnt] = a[i];
									b[++cnt] = a[j];
									b[++cnt] = a[k];
									b[++cnt] = a[l];
									b[++cnt] = a[m];
									b[++cnt] = a[nn];
									b[++cnt] = a[o];
									b[++cnt] = a[p];
									for (int mmm = 1; mmm <= cnt; mmm++) {
										if (b[mmm] > maxx)
											maxx = b[mmm];
										sum += b[mmm];
									}
									if (maxx * 2 < sum)
										ans++;
									sum = cnt = 0;
									maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										b[++cnt] = a[i];
										b[++cnt] = a[j];
										b[++cnt] = a[k];
										b[++cnt] = a[l];
										b[++cnt] = a[m];
										b[++cnt] = a[nn];
										b[++cnt] = a[o];
										b[++cnt] = a[p];
										b[++cnt] = a[q];
										for (int mmm = 1; mmm <= cnt; mmm++) {
											if (b[mmm] > maxx)
												maxx = b[mmm];
											sum += b[mmm];
										}
										if (maxx * 2 < sum)
											ans++;
										sum = cnt = 0;
										maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											b[++cnt] = a[i];
											b[++cnt] = a[j];
											b[++cnt] = a[k];
											b[++cnt] = a[l];
											b[++cnt] = a[m];
											b[++cnt] = a[nn];
											b[++cnt] = a[o];
											b[++cnt] = a[p];
											b[++cnt] = a[q];
											b[++cnt] = a[r];
											for (int mmm = 1; mmm <= cnt; mmm++) {
												if (b[mmm] > maxx)
													maxx = b[mmm];
												sum += b[mmm];
											}
											if (maxx * 2 < sum)
												ans++;
											sum = cnt = 0;
											maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											b[++cnt] = a[i];
											b[++cnt] = a[j];
											b[++cnt] = a[k];
											b[++cnt] = a[l];
											b[++cnt] = a[m];
											b[++cnt] = a[nn];
											b[++cnt] = a[o];
											b[++cnt] = a[p];
											b[++cnt] = a[q];
											b[++cnt] = a[r];
											for (int mmm = 1; mmm <= cnt; mmm++) {
												if (b[mmm] > maxx)
													maxx = b[mmm];
												sum += b[mmm];
											}
											if (maxx * 2 < sum)
												ans++;
											sum = cnt = 0;
											maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											b[++cnt] = a[i];
											b[++cnt] = a[j];
											b[++cnt] = a[k];
											b[++cnt] = a[l];
											b[++cnt] = a[m];
											b[++cnt] = a[nn];
											b[++cnt] = a[o];
											b[++cnt] = a[p];
											b[++cnt] = a[q];
											b[++cnt] = a[r];
											for (int mmm = 1; mmm <= cnt; mmm++) {
												if (b[mmm] > maxx)
													maxx = b[mmm];
												sum += b[mmm];
											}
											if (maxx * 2 < sum)
												ans++;
											sum = cnt = 0;
											maxx = -1;
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



	if (n <= 10) {
		cout << ans;
		return 0;
	}




	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int m = l + 1; m <= n; m++) {
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											for (int s = r + 1; s <= n; s++) {
												b[++cnt] = a[i];
												b[++cnt] = a[j];
												b[++cnt] = a[k];
												b[++cnt] = a[l];
												b[++cnt] = a[m];
												b[++cnt] = a[nn];
												b[++cnt] = a[o];
												b[++cnt] = a[p];
												b[++cnt] = a[q];
												b[++cnt] = a[r];
												b[++cnt] = a[s];
												for (int mmm = 1; mmm <= cnt; mmm++) {
													if (b[mmm] > maxx)
														maxx = b[mmm];
													sum += b[mmm];
												}
												if (maxx * 2 < sum)
													ans++;
												sum = cnt = 0;
												maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											for (int s = r + 1; s <= n; s++) {
												for (int t = s + 1; t <= n; t++) {
													b[++cnt] = a[i];
													b[++cnt] = a[j];
													b[++cnt] = a[k];
													b[++cnt] = a[l];
													b[++cnt] = a[m];
													b[++cnt] = a[nn];
													b[++cnt] = a[o];
													b[++cnt] = a[p];
													b[++cnt] = a[q];
													b[++cnt] = a[r];
													b[++cnt] = a[s];
													b[++cnt] = a[t];
													for (int mmm = 1; mmm <= cnt; mmm++) {
														if (b[mmm] > maxx)
															maxx = b[mmm];
														sum += b[mmm];
													}
													if (maxx * 2 < sum)
														ans++;
													sum = cnt = 0;
													maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											for (int s = r + 1; s <= n; s++) {
												for (int t = s + 1; t <= n; t++) {
													for (int u = t + 1; u <= n; u++) {
														b[++cnt] = a[i];
														b[++cnt] = a[j];
														b[++cnt] = a[k];
														b[++cnt] = a[l];
														b[++cnt] = a[m];
														b[++cnt] = a[nn];
														b[++cnt] = a[o];
														b[++cnt] = a[p];
														b[++cnt] = a[q];
														b[++cnt] = a[r];
														b[++cnt] = a[s];
														b[++cnt] = a[t];
														b[++cnt] = a[u];
														for (int mmm = 1; mmm <= cnt; mmm++) {
															if (b[mmm] > maxx)
																maxx = b[mmm];
															sum += b[mmm];
														}
														if (maxx * 2 < sum)
															ans++;
														sum = cnt = 0;
														maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											for (int s = r + 1; s <= n; s++) {
												for (int t = s + 1; t <= n; t++) {
													for (int u = t + 1; u <= n; u++) {
														for (int v = u + 1; v <= n; v++) {
															b[++cnt] = a[i];
															b[++cnt] = a[j];
															b[++cnt] = a[k];
															b[++cnt] = a[l];
															b[++cnt] = a[m];
															b[++cnt] = a[nn];
															b[++cnt] = a[o];
															b[++cnt] = a[p];
															b[++cnt] = a[q];
															b[++cnt] = a[r];
															b[++cnt] = a[s];
															b[++cnt] = a[t];
															b[++cnt] = a[u];
															b[++cnt] = a[v];
															for (int mmm = 1; mmm <= cnt; mmm++) {
																if (b[mmm] > maxx)
																	maxx = b[mmm];
																sum += b[mmm];
															}
															if (maxx * 2 < sum)
																ans++;
															sum = cnt = 0;
															maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											for (int s = r + 1; s <= n; s++) {
												for (int t = s + 1; t <= n; t++) {
													for (int u = t + 1; u <= n; u++) {
														for (int v = u + 1; v <= n; v++) {
															for (int w = v + 1; w <= n; w++) {
																b[++cnt] = a[i];
																b[++cnt] = a[j];
																b[++cnt] = a[k];
																b[++cnt] = a[l];
																b[++cnt] = a[m];
																b[++cnt] = a[nn];
																b[++cnt] = a[o];
																b[++cnt] = a[p];
																b[++cnt] = a[q];
																b[++cnt] = a[r];
																b[++cnt] = a[s];
																b[++cnt] = a[t];
																b[++cnt] = a[u];
																b[++cnt] = a[v];
																b[++cnt] = a[w];
																for (int mmm = 1; mmm <= cnt; mmm++) {
																	if (b[mmm] > maxx)
																		maxx = b[mmm];
																	sum += b[mmm];
																}
																if (maxx * 2 < sum)
																	ans++;
																sum = cnt = 0;
																maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											for (int s = r + 1; s <= n; s++) {
												for (int t = s + 1; t <= n; t++) {
													for (int u = t + 1; u <= n; u++) {
														for (int v = u + 1; v <= n; v++) {
															for (int w = v + 1; w <= n; w++) {
																for (int x = w + 1; x <= n; x++) {
																	b[++cnt] = a[i];
																	b[++cnt] = a[j];
																	b[++cnt] = a[k];
																	b[++cnt] = a[l];
																	b[++cnt] = a[m];
																	b[++cnt] = a[nn];
																	b[++cnt] = a[o];
																	b[++cnt] = a[p];
																	b[++cnt] = a[q];
																	b[++cnt] = a[r];
																	b[++cnt] = a[s];
																	b[++cnt] = a[t];
																	b[++cnt] = a[u];
																	b[++cnt] = a[v];
																	b[++cnt] = a[w];
																	b[++cnt] = a[x];
																	for (int mmm = 1; mmm <= cnt; mmm++) {
																		if (b[mmm] > maxx)
																			maxx = b[mmm];
																		sum += b[mmm];
																	}
																	if (maxx * 2 < sum)
																		ans++;
																	sum = cnt = 0;
																	maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
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
																		b[++cnt] = a[i];
																		b[++cnt] = a[j];
																		b[++cnt] = a[k];
																		b[++cnt] = a[l];
																		b[++cnt] = a[m];
																		b[++cnt] = a[nn];
																		b[++cnt] = a[o];
																		b[++cnt] = a[p];
																		b[++cnt] = a[q];
																		b[++cnt] = a[r];
																		b[++cnt] = a[s];
																		b[++cnt] = a[t];
																		b[++cnt] = a[u];
																		b[++cnt] = a[v];
																		b[++cnt] = a[w];
																		b[++cnt] = a[x];
																		b[++cnt] = a[y];
																		for (int mmm = 1; mmm <= cnt; mmm++) {
																			if (b[mmm] > maxx)
																				maxx = b[mmm];
																			sum += b[mmm];
																		}
																		if (maxx * 2 < sum)
																			ans++;
																		sum = cnt = 0;
																		maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
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
																		for (int z = y + 1; z <= n; x++) {
																			b[++cnt] = a[i];
																			b[++cnt] = a[j];
																			b[++cnt] = a[k];
																			b[++cnt] = a[l];
																			b[++cnt] = a[m];
																			b[++cnt] = a[nn];
																			b[++cnt] = a[o];
																			b[++cnt] = a[p];
																			b[++cnt] = a[q];
																			b[++cnt] = a[r];
																			b[++cnt] = a[s];
																			b[++cnt] = a[t];
																			b[++cnt] = a[u];
																			b[++cnt] = a[v];
																			b[++cnt] = a[w];
																			b[++cnt] = a[x];
																			b[++cnt] = a[y];
																			b[++cnt] = a[z];
																			for (int mmm = 1; mmm <= cnt; mmm++) {
																				if (b[mmm] > maxx)
																					maxx = b[mmm];
																				sum += b[mmm];
																			}
																			if (maxx * 2 < sum)
																				ans++;
																			sum = cnt = 0;
																			maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
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
																		for (int z = y + 1; z <= n; x++) {
																			for (int aa = z + 1; aa <= n; aa++) {
																				b[++cnt] = a[i];
																				b[++cnt] = a[j];
																				b[++cnt] = a[k];
																				b[++cnt] = a[l];
																				b[++cnt] = a[m];
																				b[++cnt] = a[nn];
																				b[++cnt] = a[o];
																				b[++cnt] = a[p];
																				b[++cnt] = a[q];
																				b[++cnt] = a[r];
																				b[++cnt] = a[s];
																				b[++cnt] = a[t];
																				b[++cnt] = a[u];
																				b[++cnt] = a[v];
																				b[++cnt] = a[w];
																				b[++cnt] = a[x];
																				b[++cnt] = a[y];
																				b[++cnt] = a[z];
																				b[++cnt] = a[aa];
																				for (int mmm = 1; mmm <= cnt; mmm++) {
																					if (b[mmm] > maxx)
																						maxx = b[mmm];
																					sum += b[mmm];
																				}
																				if (maxx * 2 < sum)
																					ans++;
																				sum = cnt = 0;
																				maxx = -1;
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
						for (int nn = m + 1; nn <= n; nn++) {
							for (int o = nn + 1; o <= n; o++) {
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
																		for (int z = y + 1; z <= n; x++) {
																			for (int aa = z + 1; aa <= n; aa++) {
																				for (int bb = aa + 1; bb <= n; bb++) {
																					b[++cnt] = a[i];
																					b[++cnt] = a[j];
																					b[++cnt] = a[k];
																					b[++cnt] = a[l];
																					b[++cnt] = a[m];
																					b[++cnt] = a[nn];
																					b[++cnt] = a[o];
																					b[++cnt] = a[p];
																					b[++cnt] = a[q];
																					b[++cnt] = a[r];
																					b[++cnt] = a[s];
																					b[++cnt] = a[t];
																					b[++cnt] = a[u];
																					b[++cnt] = a[v];
																					b[++cnt] = a[w];
																					b[++cnt] = a[x];
																					b[++cnt] = a[y];
																					b[++cnt] = a[z];
																					b[++cnt] = a[aa];
																					b[++cnt] = a[bb];
																					for (int mmm = 1; mmm <= cnt; mmm++) {
																						if (b[mmm] > maxx)
																							maxx = b[mmm];
																						sum += b[mmm];
																					}
																					if (maxx * 2 < sum)
																						ans++;
																					sum = cnt = 0;
																					maxx = -1;
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
