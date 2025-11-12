#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int a[5010];
int n, cnt = 0;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	for (int bian = 3; bian <= n; bian++) { //¼¸±ßĞÎ

		if (bian == 3) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						if (a[i] + a[j] + a[k] > a[k] * 2)
							cnt++;
					}
				}
			}
		}

		if (bian == 4) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							if (a[i] + a[j] + a[k] + a[l] > a[l] * 2)
								cnt++;
						}
					}
				}
			}
		}

		if (bian == 5) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								if (a[i] + a[j] + a[k] + a[l] + a[m] > a[m] * 2)
									cnt++;
							}
						}
					}
				}
			}
		}

		if (bian == 6) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] > a[o] * 2)
										cnt++;
								}
							}
						}
					}
				}
			}
		}

		if (bian == 7) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] > a[a1] * 2)
											cnt++;
									}
								}
							}
						}
					}
				}
			}
		}

		if (bian == 8) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] > a[a2] * 2)
												cnt++;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (bian == 9) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] > a[a3] * 2)
													cnt++;
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

		if (bian == 10) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] > a[a4] * 2)
														cnt++;
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

		if (bian == 11) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++)
														if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] > a[a5] * 2)
															cnt++;
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

		if (bian == 12) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] > a[a6] * 2)
																cnt++;
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

		if (bian == 13) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															for (int a7 = a6 + 1; a7 <= n; a7++) {
																if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] > a[a7] * 2)
																	cnt++;
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

		if (bian == 14) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															for (int a7 = a6 + 1; a7 <= n; a7++) {
																for (int a8 = a7 + 1; a8 <= n; a8++) {
																	if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] > a[a8] * 2)
																		cnt++;
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

		if (bian == 15) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															for (int a7 = a6 + 1; a7 <= n; a7++) {
																for (int a8 = a7 + 1; a8 <= n; a8++) {
																	for (int a9 = a8 + 1; a9 <= n; a9++) {
																		if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] + a[a9] >
																		        a[a9] * 2)
																			cnt++;
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

		if (bian == 16) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															for (int a7 = a6 + 1; a7 <= n; a7++) {
																for (int a8 = a7 + 1; a8 <= n; a8++) {
																	for (int a9 = a8 + 1; a9 <= n; a9++) {
																		for (int a10 = a9 + 1; a10 <= n; a10++) {
																			if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] + a[a9] +
																			        a[a10] >
																			        a[a10] * 2)
																				cnt++;
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

		if (bian == 17) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															for (int a7 = a6 + 1; a7 <= n; a7++) {
																for (int a8 = a7 + 1; a8 <= n; a8++) {
																	for (int a9 = a8 + 1; a9 <= n; a9++) {
																		for (int a10 = a9 + 1; a10 <= n; a10++) {
																			for (int a11 = a10 + 1; a11 <= n; a11++) {
																				if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] + a[a9] +
																				        a[a10] + a[a11] >
																				        a[a11] * 2)
																					cnt++;
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

		if (bian == 18) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															for (int a7 = a6 + 1; a7 <= n; a7++) {
																for (int a8 = a7 + 1; a8 <= n; a8++) {
																	for (int a9 = a8 + 1; a9 <= n; a9++) {
																		for (int a10 = a9 + 1; a10 <= n; a10++) {
																			for (int a11 = a10 + 1; a11 <= n; a11++) {
																				for (int a12 = a11 + 1; a12 <= n; a12++) {
																					if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] + a[a9] +
																					        a[a10] + a[a11] + a[a12] >
																					        a[a12] * 2)
																						cnt++;
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

		if (bian == 19) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															for (int a7 = a6 + 1; a7 <= n; a7++) {
																for (int a8 = a7 + 1; a8 <= n; a8++) {
																	for (int a9 = a8 + 1; a9 <= n; a9++) {
																		for (int a10 = a9 + 1; a10 <= n; a10++) {
																			for (int a11 = a10 + 1; a11 <= n; a11++) {
																				for (int a12 = a11 + 1; a12 <= n; a12++) {
																					for (int a13 = a12 + 1; a13 <= n; a13++) {
																						if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] + a[a9] +
																						        a[a10] + a[a11] + a[a12] + a[a13] >
																						        a[a13] * 2)
																							cnt++;
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

		if (bian == 20) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int o = m + 1; o <= n; o++) {
									for (int a1 = o + 1; a1 <= n; a1++) {
										for (int a2 = a1 + 1; a2 <= n; a2++) {
											for (int a3 = a2 + 1; a3 <= n; a3++) {
												for (int a4 = a3 + 1; a4 <= n; a4++) {
													for (int a5 = a4 + 1; a5 <= n; a5++) {
														for (int a6 = a5 + 1; a6 <= n; a6++) {
															for (int a7 = a6 + 1; a7 <= n; a7++) {
																for (int a8 = a7 + 1; a8 <= n; a8++) {
																	for (int a9 = a8 + 1; a9 <= n; a9++) {
																		for (int a10 = a9 + 1; a10 <= n; a10++) {
																			for (int a11 = a10 + 1; a11 <= n; a11++) {
																				for (int a12 = a11 + 1; a12 <= n; a12++) {
																					for (int a13 = a12 + 1; a13 <= n; a13++) {
																						for (int a14 = a13 + 1; a14 <= n; a14++) {
																							if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] + a[a9] +
																							        a[a10] + a[a11] + a[a12] + a[a13] + a[a14] >
																							        a[a14] * 2)
																								cnt++;
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
	cout << cnt % 998244353;
	return 0;
}
