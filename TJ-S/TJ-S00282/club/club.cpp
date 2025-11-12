#include <bits/stdc++.h>
using namespace std;
int a1=0,b1=0,c1=0;
int ans = 0;
int s;
int mx = -123;
int a[100032],b[100032],c[100032];
void DoA(int i){
	if(a[i] > b[i] && a[i] > c[i]){
		if(a1 + 1 <= s){
			a1++;
			ans += a[i];
		}
		else{
			if(b[i] > c[i]){
				if(b1+1 <= s){
					b1 ++;
					ans += b[i];
				}
			}
			else{
				c1++;
				ans += c[i] ;
			}
		}
	}
}
void DoB(int i){
	if(b[i] > a[i] && b[i] > c[i]){
		if(b1 + 1 <= s){
			b1++;
			ans += b[i];
		}
		else{
			if(a[i] > c[i]){
				if(a1+1 <= s){
					a1 ++;
					ans += a[i];
				}
			}
			else{
				c1++;
				ans += c[i] ;
			}
		}
	}
}
void DoC(int i){
	if(c[i] > b[i] && c[i] > a[i]){
		if(c1 + 1 <= s){
			c1++;
			ans += c[i];
		}
		else{
			if(b[i] > a[i]){
				if(b1+1 <= s){
					b1 ++;
					ans += b[i];
				}
			}
			else{
				a1++;
				ans += a[i] ;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	for(int o=0;o<T;o++){
		int n;
		cin >> n;
		int q=0,w=0,e=0;
		for(int i=0;i<n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if(a[i] > b[i] && a[i] > c[i])
				q++;
			else if(b[i] > a[i] && b[i] > c[i])
				w++;
			else
				e++;
		}
		if(q == max(max(q,w),max(w,e)) && b[0] != c[0]){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i < j && a[i] > a[j]){
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						swap(c[i],c[j]);
					}
				}
			}
		}
		else if(q == max(max(q,w),max(w,e)) && b[0] == c[0]){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i < j && a[i] < a[j]){
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						swap(c[i],c[j]);
					}
				}
			}
		}
		else if(w == max(max(q,w),max(w,e))  && a[0] != c[0]){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i < j && b[i] > b[j]){
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						swap(c[i],c[j]);
					}
				}
			}
		}
		else if(w == max(max(q,w),max(w,e))  && a[0] == c[0]){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i < j && b[i] < b[j]){
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						swap(c[i],c[j]);
					}
				}
			}
		}
		else if(a[0] != b[0]){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i < j && c[i] > c[j]){
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						swap(c[i],c[j]);
					}
				}
			}
		}
		else{
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i < j && c[i] < c[j]){
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						swap(c[i],c[j]);
					}
				}
			}
		}
		a1=0,b1=0,c1=0;
		ans = 0;
		s = n/2;
		mx = -123;
	
		for(int i=0;i<n;i++){
			if(q == max(max(q,w),max(w,e))){ 
				DoA(i);
				DoB(i);
				DoC(i);
			} 
			else if(w == max(max(q,w),max(w,e))){ 
				DoB(i);
				DoC(i);
				DoA(i);
			} 
			else{ 
				DoC(i);
				DoA(i);
				DoB(i); 
			} 
			mx = max(mx,ans);
		}
		cout << mx << endl;
	}
	return 0;
}
