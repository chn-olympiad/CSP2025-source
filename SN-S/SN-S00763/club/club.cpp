//姓名：霍启若 准考证号：SN-S00703 学校：蒲城县城南学校 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],r,m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0;i < n;i++) cin >> a[i] >> b[i] >> c[i];
		if(n == 2){
			r = a[0] + b[1];
			r = max(r,a[0] + c[1]);
			r = max(r,b[0] + a[1]);
			r = max(r,b[0] + c[1]);
			r = max(r,c[0] + a[1]);
			m = max(r,c[0] + b[1]);
		}
		else if(n == 4){
			r = a[0] + a[1] + b[3] + b[4];
			r = max(r,a[0] + a[1] + b[2] + c[3]);
			r = max(r,a[0] + a[1] + c[2] + b[3]);
			r = max(r,a[0] + a[1] + c[2] + c[3]);
			r = max(r,a[0] + b[1] + b[2] + c[3]);
			r = max(r,a[0] + a[1] + c[2] + b[3]);
			r = max(r,a[0] + b[1] + a[2] + c[3]);
			r = max(r,a[0] + b[1] + b[2] + c[3]);
			r = max(r,a[0] + b[1] + c[2] + a[3]);
			r = max(r,a[0] + b[1] + c[2] + b[3]);
			r = max(r,a[0] + b[1] + c[2] + c[3]);
			r = max(r,a[0] + c[1] + a[2] + b[3]);
			r = max(r,a[0] + c[1] + a[2] + c[3]);
			r = max(r,a[0] + c[1] + b[2] + a[3]);
			r = max(r,a[0] + c[1] + b[2] + b[3]);
			r = max(r,a[0] + c[1] + b[2] + c[3]);
			r = max(r,a[0] + c[1] + c[2] + a[3]);
			r = max(r,a[0] + c[1] + c[2] + b[3]);
			r = max(r,b[0] + a[1] + a[2] + b[3]);
			r = max(r,b[0] + a[1] + a[2] + c[3]);
			r = max(r,b[0] + a[1] + b[2] + a[3]);
			r = max(r,b[0] + a[1] + b[2] + c[3]);
			r = max(r,b[0] + a[1] + c[2] + a[3]);
			r = max(r,b[0] + a[1] + c[2] + b[3]);
			r = max(r,b[0] + a[1] + c[2] + c[3]);
			r = max(r,b[0] + b[1] + a[2] + a[3]);
			r = max(r,b[0] + b[1] + a[2] + c[3]);
			r = max(r,b[0] + b[1] + c[2] + a[3]);
			r = max(r,b[0] + b[1] + c[2] + c[3]);
			r = max(r,b[0] + c[1] + a[2] + a[3]);
			r = max(r,b[0] + c[1] + a[2] + b[3]);
			r = max(r,b[0] + c[1] + a[2] + c[3]);
			r = max(r,b[0] + c[1] + b[2] + a[3]);
			r = max(r,b[0] + c[1] + b[2] + c[3]);
			r = max(r,b[0] + c[1] + c[2] + a[3]);
			r = max(r,b[0] + c[1] + c[2] + b[3]);
			r = max(r,c[0] + a[1] + a[2] + b[3]);
			r = max(r,c[0] + a[1] + a[2] + c[3]);
			r = max(r,c[0] + a[1] + b[2] + a[3]);
			r = max(r,c[0] + a[1] + b[2] + b[3]);
			r = max(r,c[0] + a[1] + b[2] + c[3]);
			r = max(r,c[0] + a[1] + c[2] + a[3]);
			r = max(r,c[0] + a[1] + c[2] + b[3]);
			r = max(r,c[0] + b[1] + a[2] + a[3]);
			r = max(r,c[0] + b[1] + a[2] + b[3]);
			r = max(r,c[0] + b[1] + a[2] + c[3]);
			r = max(r,c[0] + b[1] + b[2] + a[3]);
			r = max(r,c[0] + b[1] + b[2] + c[3]);
			r = max(r,c[0] + b[1] + c[2] + a[3]);
			r = max(r,c[0] + b[1] + c[2] + b[3]);
			r = max(r,c[0] + c[1] + a[2] + a[3]);
			r = max(r,c[0] + c[1] + a[2] + b[3]);
			r = max(r,c[0] + c[1] + b[2] + a[3]);
			m = max(r,c[0] + c[1] + b[2] + b[3]);
		}
		else if(n == 10){
			for(int i = 0;i < 3;i++){
				for(int j = 0;j < 3;j++){
					for(int k = 0;k < 3;k++){
						for(int l = 0;l < 3;l++){
							for(int m = 0;m < 3;m++){
								if(i == j && i == k && i == l && i == m) continue;
								for(int n = 0;n < 3;n++){
									if(n == i && n == j && n == k && n == l) continue;
									if(n == i && n == j && n == k && n == m) continue;
									if(n == i && n == j && n == l && n == m) continue;  
									if(n == i && n == k && n == l && n == m) continue; 
									if(n == j && n == k && n == l && n == m) continue;
									for(int o = 0;o < 3;o++){
										if(o == i && o == j && o == k && o == l) continue; 
										if(o == i && o == j && o == k && o == m) continue; 
										if(o == i && o == j && o == k && o == n) continue; 
										if(o == i && o == j && o == l && o == m) continue;  
										if(o == i && o == j && o == l && o == n) continue;  
										if(o == i && o == j && o == m && o == n) continue;  
										if(o == i && o == k && o == l && o == m) continue;  
										if(o == i && o == k && o == l && o == n) continue;   
										if(o == i && o == k && o == m && o == n) continue;  
										if(o == i && o == l && o == m && o == n) continue;  
										if(o == j && o == k && o == l && o == m) continue;  
										if(o == j && o == k && o == l && o == n) continue;  
										if(o == j && o == k && o == m && o == n) continue; 
										if(o == j && o == l && o == m && o == n) continue;  
										if(o == k && o == l && o == m && o == n) continue;        
										for(int p = 0;p < 3;p++){
											if(p == i && p == j && p == k && p == l) continue; 
											if(p == i && p == j && p == k && p == m) continue;  
											if(p == i && p == j && p == k && p == n) continue;
											if(p == i && p == j && p == k && p == o) continue;     
											if(p == i && p == j && p == l && p == m) continue;
											if(p == i && p == j && p == l && p == n) continue;  
											if(p == i && p == j && p == l && p == o) continue;    
											if(p == i && p == j && p == m && p == n) continue;     
											if(p == i && p == j && p == m && p == o) continue;     
											if(p == i && p == j && p == n && p == o) continue;      
											if(p == i && p == k && p == l && p == m) continue;      
											if(p == i && p == k && p == l && p == n) continue;     
											if(p == i && p == k && p == l && p == o) continue;    
											if(p == i && p == k && p == m && p == o) continue;     
											if(p == i && p == k && p == n && p == o) continue;     
											if(p == i && p == k && p == n && p == o) continue;     
											if(p == i && p == l && p == m && p == n) continue;     
											if(p == i && p == l && p == m && p == o) continue;     
											if(p == i && p == l && p == n && p == o) continue;      
											if(p == i && p == m && p == n && p == o) continue;      
											if(p == j && p == k && p == l && p == m) continue;     
											if(p == j && p == k && p == l && p == n) continue;     
											if(p == j && p == k && p == m && p == n) continue;     
											if(p == j && p == l && p == m && p == n) continue;     
											if(p == k && p == l && p == m && p == n) continue;      
											for(int q = 0;q < 3;q++){
												if(q == i && q == j && q == k && q == l)continue;    
												if(q == i && q == j && q == k && q == m)continue;  
												if(q == i && q == j && q == k && q == n)continue; 
												if(q == i && q == j && q == k && q == o)continue;  
												if(q == i && q == j && q == k && q == p)continue;  
												if(q == i && q == j && q == l && q == m)continue;   
												if(q == i && q == j && q == l && q == n)continue;  
												if(q == i && q == j && q == l && q == o)continue;  
												if(q == i && q == j && q == l && q == p)continue;  
												if(q == i && q == j && q == m && q == n)continue;  
												if(q == i && q == j && q == m && q == o)continue;  
												if(q == i && q == j && q == m && q == p)continue;  
												if(q == i && q == j && q == n && q == o)continue;  
												if(q == i && q == j && q == n && q == p)continue;  
												if(q == i && q == j && q == o && q == p)continue;  
												if(q == i && q == j && q == o && q == p)continue;    
												if(q == i && q == k && q == l && q == m)continue;   
												if(q == i && q == k && q == l && q == n)continue;        
												if(q == i && q == k && q == l && q == o)continue;        
												if(q == i && q == k && q == l && q == p)continue;  
												if(q == i && q == l && q == m && q == n) continue;
												if(q == i && q == l && q == m && q == o) continue;
												if(q == i && q == l && q == m && q == p) continue;
												if(q == i && q == l && q == n && q == o) continue;
												if(q == i && q == l && q == n && q == p) continue;
												if(q == i && q == m && q == o && q == p) continue;
												if(q == i && q == n && q == o && q == p) continue;
												if(q == j && q == k && q == l && q == m) continue;
												if(q == j && q == k && q == l && q == n) continue;
												if(q == j && q == k && q == l && q == o) continue;
												if(q == j && q == k && q == l && q == p) continue;
												if(q == j && q == k && q == m && q == p) continue;
												if(q == j && q == k && q == n && q == p) continue;
												if(q == j && q == k && q == o && q == p) continue;
												if(q == j && q == l && q == m && q == n) continue;
												if(q == j && q == l && q == m && q == o) continue;
												if(q == j && q == l && q == m && q == p) continue;
												if(q == j && q == l && q == n && q == o) continue;
												if(q == j && q == l && q == n && q == p) continue;
												if(q == j && q == l && q == o && q == p) continue;
												if(q == j && q == m && q == n && q == o) continue;
												if(q == j && q == m && q == n && q == p) continue;
												if(q == j && q == m && q == o && q == p) continue;
												if(q == j && q == n && q == o && q == p) continue;
												if(q == k && q == l && q == m && q == n) continue;
												if(q == k && q == l && q == m && q == o) continue;
												if(q == k && q == l && q == m && q == p) continue;
												if(q == k && q == l && q == n && q == o) continue;
												if(q == k && q == l && q == n && q == p) continue;
												if(q == k && q == l && q == o && q == p) continue;
												if(q == k && q == m && q == n && q == o) continue;
												if(q == k && q == m && q == n && q == p) continue;
												if(q == k && q == m && q == o && q == p) continue;
												if(q == k && q == n && q == o && q == p) continue;
												if(q == l && q == m && q == n && q == o) continue;
												if(q == l && q == m && q == n && q == p) continue;
												if(q == l && q == m && q == o && q == p) continue;
												if(q == l && q == n && q == o && q == p) continue;
												if(q == m && q == n && q == o && q == p) continue;
												for(int s = 0;s < 3;s++){
													if(s == i && s == j && s == k && s == l) continue;
													if(s == i && s == j && s == k && s == m) continue;  
													if(s == i && s == j && s == k && s == n) continue;    
													if(s == i && s == j && s == k && s == o) continue;    
													if(s == i && s == j && s == k && s == p) continue;    
													if(s == i && s == j && s == k && s == q) continue;    
													if(s == i && s == j && s == l && s == m) continue;     
													if(s == i && s == j && s == l && s == n) continue;     
													if(s == i && s == j && s == l && s == o) continue;     
													if(s == i && s == j && s == l && s == p) continue;     
													if(s == i && s == j && s == l && s == q) continue;     
													if(s == i && s == j && s == m && s == n) continue;     
													if(s == i && s == j && s == m && s == o) continue;       
													if(s == i && s == j && s == m && s == p) continue;       
													if(s == i && s == j && s == m && s == q) continue;      
													if(s == i && s == j && s == n && s == o) continue;     
													if(s == i && s == j && s == n && s == p) continue;       
													if(s == i && s == j && s == n && s == q) continue;       
													if(s == i && s == j && s == o && s == p) continue;       
													if(s == i && s == j && s == o && s == q) continue;       
													if(s == i && s == j && s == p && s == q) continue;        
													if(s == i && s == k && s == l && s == m) continue;        
													if(s == i && s == k && s == l && s == n) continue;        
													if(s == i && s == k && s == l && s == o) continue;        
													if(s == i && s == k && s == l && s == p) continue;        
													if(s == i && s == k && s == l && s == q) continue;        
													if(s == i && s == k && s == m && s == n) continue;        
													if(s == i && s == k && s == m && s == o) continue;         
													if(s == i && s == k && s == m && s == p) continue;         
													if(s == i && s == k && s == m && s == q) continue;         
													if(s == i && s == k && s == n && s == o) continue;         
													if(s == i && s == k && s == n && s == p) continue;        
													if(s == i && s == k && s == n && s == q) continue;        
													if(s == i && s == k && s == o && s == p) continue;         
													if(s == i && s == k && s == o && s == q) continue;         
													if(s == i && s == k && s == p && s == q) continue;        
													if(s == i && s == l && s == m && s == n) continue;        
													if(s == i && s == l && s == m && s == o) continue;          
													if(s == i && s == l && s == m && s == p) continue;         
													if(s == i && s == l && s == m && s == q) continue;         
													if(s == i && s == l && s == n && s == o) continue;        
													if(s == i && s == l && s == n && s == p) continue;     
													if(s == i && s == l && s == n && s == q) continue;      
													if(s == i && s == l && s == o && s == p) continue;      
													if(s == i && s == l && s == o && s == q) continue;      
													if(s == i && s == l && s == p && s == q) continue;      
													if(s == i && s == m && s == n && s == o) continue;      
													if(s == i && s == m && s == n && s == p) continue;      
													if(s == i && s == m && s == n && s == q) continue;      
													if(s == i && s == m && s == o && s == p) continue;      
													if(s == i && s == m && s == o && s == q) continue;      
													if(s == i && s == m && s == p && s == q) continue;      
													if(s == i && s == n && s == o && s == p) continue;      
													if(s == i && s == n && s == o && s == q) continue;    
													if(s == i && s == n && s == p && s == q) continue;   
													if(s == i && s == o && s == p && s == q) continue;  
													if(s == j && s == k && s == l && s == m) continue;  
													if(s == j && s == k && s == l && s == n) continue;  
													if(s == j && s == k && s == l && s == o) continue;  
													if(s == j && s == k && s == l && s == p) continue;  
													if(s == j && s == k && s == l && s == q) continue;  
													if(s == j && s == k && s == m && s == n) continue;  
													if(s == j && s == k && s == m && s == o) continue;  
													if(s == j && s == k && s == m && s == p) continue;
													if(s == j && s == k && s == m && s == q) continue;
													if(s == j && s == k && s == n && s == o) continue;
													if(s == j && s == k && s == n && s == p) continue;
													if(s == j && s == k && s == n && s == q) continue;
													if(s == j && s == k && s == o && s == p) continue;
													if(s == j && s == k && s == o && s == q) continue;
													if(s == j && s == k && s == p && s == q) continue;
													if(s == j && s == l && s == p && s == q) continue;
													if(i == 0) r += a[0];
													if(i == 1) r += b[0];
													if(i == 2) r += c[0];
													if(j == 0) r += a[1];
													if(j == 1) r += b[1];
													if(j == 2) r += c[1];
													if(k == 0) r += a[2];
													if(k == 1) r += b[2];
													if(k == 2) r += c[2];
													if(l == 0) r += a[3];
													if(l == 1) r += b[3];
													if(l == 2) r += c[3];
													if(m == 0) r += a[4];
													if(m == 1) r += b[4];
													if(m == 2) r += c[4];
													if(n == 0) r += a[5];
													if(n == 1) r += b[5];
													if(n == 2) r += c[5];
													if(o == 0) r += a[6];
													if(o == 1) r += b[6];
													if(o == 2) r += c[6];
													if(p == 0) r += a[7];
													if(p == 1) r += b[7];
													if(p == 2) r += c[7];
													if(q == 0) r += a[8];
													if(q == 1) r += b[8];
													if(q == 2) r += c[8];
													if(s == 0) r += a[9];
													if(s == 1) r += b[9];
													if(s == 2) r += c[9];
													m = max(m,r);
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
		else m = rand();
		cout << m << "\n";
	}
	return 0;
}
