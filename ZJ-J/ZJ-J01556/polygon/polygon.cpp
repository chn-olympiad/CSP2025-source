#include<bits/stdc++.h>
using namespace std;
int n,a[6666],maxn,b[6666];
long long ans=1,s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(a[i], maxn);
	}
	if(maxn == 1){
		for(int i = 3; i <= n; i++){
			int ans = 1;
			for(int j = 0; j < i; j++){
				ans = ans * (n - j)/(j+1)%998244353;
				
			}
			s = (s + ans) % 998244353;
		}
		cout << s % 998244353;
	}else{
		sort(a + 1, a + n + 1);
		
		
		int ans = 0;
		
		
		
		for(int q1 = 1; q1 <= n; q1++){
			for(int q2 = 1; q2 <= n; q2++){
				for(int q3 = 1; q3 <= n; q3++){
					if(q1 < q2 && q2 < q3){
						int h = a[q1] + a[q2] + a[q3];
						if(h > 2 * a[q3])
							ans++;
					}
				}
			}
		}
			
		for(int q1 = 1; q1 <= n; q1++){
			for(int q2 = 1; q2 <= n; q2++){
				for(int q3 = 1; q3 <= n; q3++){
					for(int q4 = 1; q4 <= n; q4++){
						if(q1 < q2 && q2 < q3 && q3 < q4){
						int h = a[q1] + a[q2] + a[q3] + a[q4];
						if(h > 2 * a[q4])
							ans++;
						}
					}
					
				}
			}
		}	
		
		
		for(int q1 = 1; q1 <= n; q1++){
			for(int q2 = 1; q2 <= n; q2++){
				for(int q3 = 1; q3 <= n; q3++){
					for(int q4 = 1; q4 <= n; q4++){
						for(int q5 = 1; q5 <= n; q5++){
						
						if(q1 < q2 && q2 < q3 && q3 < q4 && q4 < q5){
							int h = a[q1] + a[q2] + a[q3] + a[q4] + a[q5];
							if(h > 2 * a[q5])
								ans++;
							}
						}
					}
				}
			}
		}
		
		for(int q1 = 1; q1 <= n; q1++){
			for(int q2 = 1; q2 <= n; q2++){
				for(int q3 = 1; q3 <= n; q3++){
					for(int q4 = 1; q4 <= n; q4++){
						for(int q5 = 1; q5 <= n; q5++){
						for(int q6 = 1; q6 <= n; q6++){ 
						
						if(q1 < q2 && q2 < q3 && q3 < q4 && q4 < q5 && q5 < q6){
							int h = a[q1] + a[q2] + a[q3] + a[q4] + a[q5] + a[q6];
							if(h > 2 * a[q6])
								ans++;
							}
						}
						}
					}
				}
			}
		}
		
		
		for(int q1 = 1; q1 <= n; q1++){
			for(int q2 = 1; q2 <= n; q2++){
				for(int q3 = 1; q3 <= n; q3++){
					for(int q4 = 1; q4 <= n; q4++){
						for(int q5 = 1; q5 <= n; q5++){
						for(int q6 = 1; q6 <= n; q6++){ 
						for(int q7 = 1; q7 <= n; q7++){
						
						if(q1 < q2 && q2 < q3 && q3 < q4 && q4 < q5 && q5 < q6 && q6 < q7){
							int h = a[q1] + a[q2] + a[q3] + a[q4] + a[q5] + a[q6] + a[q7];
							if(h > 2 * a[q7])
								ans++;
							}
						}
					}
						}
					}
				}
			}
		}
		
		
		for(int q1 = 1; q1 <= n; q1++){
			for(int q2 = 1; q2 <= n; q2++){
				for(int q3 = 1; q3 <= n; q3++){
					for(int q4 = 1; q4 <= n; q4++){
						for(int q5 = 1; q5 <= n; q5++){
						for(int q6 = 1; q6 <= n; q6++){ 
						for(int q7 = 1; q7 <= n; q7++){
						for(int q8 = 1; q8<=n;q8++){
						
						if(q1 < q2 && q2 < q3 && q3 < q4 && q4 < q5 && q5 < q6 && q6 < q7 && q7 < q8){
							int h = a[q1] + a[q2] + a[q3] + a[q4] + a[q5] + a[q6] + a[q7] + a[q8];
							if(h > 2 * a[q8])
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
		
		
		
		for(int q1 = 1; q1 <= n; q1++){
			for(int q2 = 1; q2 <= n; q2++){
				for(int q3 = 1; q3 <= n; q3++){
					for(int q4 = 1; q4 <= n; q4++){
						for(int q5 = 1; q5 <= n; q5++){
						for(int q6 = 1; q6 <= n; q6++){ 
						for(int q7 = 1; q7 <= n; q7++){
						for(int q8 = 1; q8<=n;q8++){
						for(int q9 = 1; q9 <= n; q9++){
						
						if(q1 < q2 && q2 < q3 && q3 < q4 && q4 < q5 && q5 < q6 && q6 < q7 && q7 < q8 && q8 < q9){
							int h = a[q1] + a[q2] + a[q3] + a[q4] + a[q5] + a[q6] + a[q7] + a[q8] + a[q9];
							if(h > 2 * a[q9])
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
		
		
		
		
		for(int q1 = 1; q1 <= n; q1++){
			for(int q2 = 1; q2 <= n; q2++){
				for(int q3 = 1; q3 <= n; q3++){
					for(int q4 = 1; q4 <= n; q4++){
						for(int q5 = 1; q5 <= n; q5++){
						for(int q6 = 1; q6 <= n; q6++){ 
						for(int q7 = 1; q7 <= n; q7++){
						for(int q8 = 1; q8<=n;q8++){
						for(int q9 = 1; q9 <= n; q9++){
						for(int q10 = 1; q10 <= n; q10++){
						
						if(q1 < q2 && q2 < q3 && q3 < q4 && q4 < q5 && q5 < q6 && q6 < q7 && q7 < q8 && q8 < q9 && q9 < q10){
							int h = a[q1] + a[q2] + a[q3] + a[q4] + a[q5] + a[q6] + a[q7] + a[q8] + a[q9] + a[q10];
							if(h > 2 * a[q10])
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
		
		cout << ans;
		
	}
	return 0;
}
