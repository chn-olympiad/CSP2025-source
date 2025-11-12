#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int Sn = 1;Sn <= t;Sn++){
		int n,maxn = 0;
		cin >> n;
		int a[n][3];
		int n1[n],n2[n],n3[n];
		int p1[n],p2[n],p3[n];
	//	int u1[100001],u2[100001],u3[100001];
		int r1 = 0,r2 = 0,r3 = 0;// n1,n2,n3<= n/2
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
	 	}
	// 	for(int m = 1;m <= n;m++){
	// 		for(int m1 = 1;m1 <= n;m1++){
	// 			for(int m2 = 1;m2 <= n;m2++){
	// 				
	//			 }
	//		 }
	//		 if(maxn > max) max = maxn;
	//	 }
	 	for(int m = 1;m <= n;m++){
	 		if(max(a[m][1],max(a[m][2],a[m][3])) == a[m][1]){
	 			r1++;
				n1[r1] = a[m][1];
				p1[r1] = m;
			 }
			else if(max(a[m][1],max(a[m][2],a[m][3])) == a[m][2]){
				r2++;
				n2[r2] = a[m][2];
				p2[r2] = m;
			}
			else{
				r3++;
				n3[r3] = a[m][3];
				p3[r3] = m;
			}
		 }
	//	 cout << r1 << " " << r2 << " " << r3 << endl;
		 if(r2==0 and r3 == 0){ 
		 	sort(n1+1,n1+r1+1);
		 	for(int i = r1;i > n/2;i--){
		 		maxn += n1[i];
			 }
		 }
		 else if(r1==0 and r3 == 0){
		 	sort(n2+1,n2+r2+1);
		 	for(int i = r2;i > n/2;i--) maxn += n2[i];
		 } 
		 else if(r1 == 0 and r2 == 0){
		 	sort(n3+1,n3+r3+1);
		 	for(int i = r3;i > n/2;i--) maxn += n3[i];
		 }
	////	if(r1 > n/2 or r2 > n/2 or r3 >n/2){
	////		
	////	}
		else if(r1 > n/2 or r2 > n/2 or r3 > n/2){
			while(r1 > n/2 or r2 > n/2 or r3 > n/2){
				while(r1 > n/2){
					int minx = 0,minxn = 0,min0 = 0,minn = -1,minn1 = 0;
					for(int x = 1;x <= r1;x++){
						if(r1 <= 2/n) break;
						if(min(n1[x]-a[p1[x]][2],n1[x]- a[p1[x]][3]) == n1[x]-a[p1[x]][2]){
							minx = n1[x] - a[p1[x]][2];
							if(min0 < minx){
								minn = p1[x];
								minxn = 2;
								minn1 = x;
							}
						}
						else if(min(n1[x]-a[p1[x]][2],n1[x]- a[p1[x]][3]) == n1[x]-a[p1[x]][3]){
							minx = n1[x] - a[p1[x]][3];
							if(min0 < minx){
								minn = p1[x];
								minxn = 3;
								minn1 = x;
							}
						}
					}
					if(minxn == 2){
						n2[r2+1] = n1[minn1];
						p2[r2+1] = p1[minn1];
						r2++; 
					}
					else{
						n3[r3+1] = n1[minn1];
						p3[r3+1] = p1[minn1];
						r3++;
					}
					n1[minn1] = 0;
					p1[minn1] = 0;
					r1--;
				}//r1
				while(r2 > n/2){
					int minx = 0,minxn = 0,min0 = 0,minn = -1,minn1 = 0;
					for(int x = 1;x <= r2;x++){
						if(r2 <= 2/n) break;
						if(min(n2[x]-a[p2[x]][1],n2[x]- a[p2[x]][3]) == n2[x]-a[p2[x]][1]){
							minx = n2[x] - a[p2[x]][1];
							if(min0 < minx){
								minn = p2[x];
								minxn = 1;
								minn1 = x;
							}
						}
						else if(min(n2[x]-a[p2[x]][1],n2[x]- a[p2[x]][3]) == n2[x]-a[p2[x]][3]){
							minx = n2[x] - a[p2[x]][3];
							if(min0 < minx){
								minn = p2[x];
								minxn = 3;
								minn1 = x;
							}
						}
					}
					if(minxn == 1){
						n1[r1+1] = n2[minn1];
						p1[r1+1] = p2[minn1];
						r1++; 
					}
					else{
						n3[r3+1] = n1[minn1];
						p3[r3+1] = p1[minn1];
						r3++;
					}
					n2[minn1] = 0;
					p2[minn1] = 0;
					r2--;
				}//r2
				while(r3 > n/2){
					int minx = 0,minxn = 0,min0 = 0,minn = -1,minn1 = 0;
					for(int x = 1;x <= r3;x++){
						if(r3 <= 2/n) break;
						if(min(n3[x]-a[p3[x]][1],n3[x]- a[p3[x]][2]) == n3[x]-a[p3[x]][1]){
							minx = n3[x] - a[p3[x]][1];
							if(min0 < minx){
								minn = p3[x];
								minxn = 1;
								minn1 = x;
							}
						}
						else if(min(n3[x]-a[p3[x]][1],n3[x]- a[p3[x]][2]) == n3[x]-a[p3[x]][2]){
							minx = n3[x] - a[p3[x]][2];
							if(min0 < minx){
								minn = p3[x];
								minxn = 2;
								minn1 = x;
							}
						}
					}
					if(minxn == 1){
						n1[r1+1] = n3[minn1];
						p1[r1+1] = p3[minn1];
						r1++; 
					}
					else{
						n2[r2+1] = n3[minn1];
						p2[r2+1] = p3[minn1];
						r2++;
					}
					n3[minn1] = 0;
					p3[minn1] = 0;
					r3--;
				}//r3
			}
			for(int res = 1;res <= r1;res++) maxn += n1[res];
			for(int res = 1;res <= r2;res++) maxn += n2[res];
			for(int res = 1;res <= r3;res++) maxn += n3[res];
		}
		else{
			for(int res = 1;res <= r1;res++) maxn += n1[res];
			for(int res = 1;res <= r2;res++) maxn += n2[res];
			for(int res = 1;res <= r3;res++) maxn += n3[res];
		}
		cout << maxn << endl;
}
	return 0;
	
} 
