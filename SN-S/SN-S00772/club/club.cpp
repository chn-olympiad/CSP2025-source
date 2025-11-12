#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t,n;
int a[N+5],b[N+5],c[N+5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int m = 1;m<=t;m++){
		cin>>n;
		int s[n],o;
		int counts[5] = {0,0,0};
		char x[n];
		for(int i = 1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		while(1){
			for(int i = 1;i<=n;i++){
				int maxi = -1;
				if(a[i]>maxi){
					maxi = a[i];
				}
				if(b[i]>maxi){
					maxi = b[i];
				}
				if(c[i]>maxi){
					maxi = c[i];
				}
				s[i] = maxi;
				if(a[i] == s[i]){
					x[i] = 'a';
				}
				if(b[i] == s[i]){
					x[i] = 'b';
				}
				if(c[i] == s[i]){
					x[i] = 'c';
				}
				o = i;
			}
			for(int i = 1;i<=n;i++){
				if(x[i] == 'a'){
					counts[1] ++;
				}
				if(x[i] == 'a'){
					counts[2] ++;
				}
				if(x[i] == 'a'){
					counts[3] ++;
				}
			}
			int up = n / 2;
			int mini = 1e6+5;
			if(counts[1]>up){
				for(int i = 1;i<=n;i++){
					if(a[i]<mini){
						mini = a[i];
						a[i] = 0;
						continue;
					}
					if(b[i]<mini){
						mini = b[i];
						b[i] = 0;
						continue;
					}
					if(c[i]<mini){
						mini = c[i];
						c[i] = 0;
						continue;
					}
				}
				continue;
			}
			if(counts[2]>up){
				for(int i = 2;i<=n;i++){
					if(a[i]<mini){
						mini = a[i];
						a[i] = 0;
						continue;
					}
					if(b[i]<mini){
						mini = b[i];
						b[i] = 0;
						continue;
					}
					if(c[i]<mini){
						mini = c[i];
						c[i] = 0;
						continue;
					}
				}
				continue;
			}
			if(counts[3]>up){
				for(int i = 3;i<=n;i++){
					if(a[i]<mini){
						mini = a[i];
						a[i] = 0;
						continue;
					}
					if(b[i]<mini){
						mini = b[i];
						b[i] = 0;
						continue;
					}
					if(c[i]<mini){
						mini = c[i];
						c[i] = 0;
						continue;
					}
				}
				continue;
			}
			else{
				cout<<s[o]<<endl;
				break;
			}
		}
	}
	return 0;
}
