#include<bits/stdc++.h>
using namespace std;
long long t,zui=0,dai=0;
long long daix=0,daiy=0,ai=0,bi=0,ci=0;
long long id[2000],a[2000],b[2000],c[2000];
void dfs(int t){
	zui=0;
	for(int j=1;j<=t;j++){
			cin >> a[j] >> b[j] >> c[j];
		}
		for(int z=1;z<=t;z++){
			if(b[z]<a[z] && c[z]<a[z]){
				dai=a[z];
				ai+=1;
			}
			if(a[z]<b[z] && c[z]<b[z]){
				dai=b[z];
				bi+=1;
			} 
			if(a[z]<c[z] && b[z]<c[z]){
				dai=c[z];
				ci+=1; 
			}
			zui+=dai;
		}
		//1
			if(t/2<ai){
				daix=0;
				for(int i=1;i<=t;i++){
					if(daix<b[i]){
						daix=b[i];
					}
					if(daix<c[i]){
						daix=c[i];
					}
				}
				zui+=daix;
				for(int i=1;i<=t;i++){
					if(t/2<ai){
						if(b[i]==daix || c[i]==daix ){
							ai--;
							zui-=a[i];
						}
					}
				}
			//2	
			}
			
			if(t/2<bi){
				daix=0;
				for(int i=1;i<=t;i++){
					if(daix<a[i]){
						daix=a[i];
					}
					if(daix<c[i]){
						daix=c[i];
					}
				}
				zui+=daix;
				for(int i=1;i<=t;i++){
					if(t/2<bi){
						if(a[i]==daix || c[i]==daix){
							bi--;
							zui-=b[i];
						}
					}
				}
			}
			//3
			if(t/2<ci){
				daix=0;
				for(int i=1;i<=t;i++){
					if(daix<a[i]){
						daix=a[i];
					}
					if(daix<b[i]){
						daix=b[i];
					}
				}
				zui+=daix;
				for(int i=1;i<=t;i++){
					if(t/2<ci){
						if(a[i]==daix || b[i]==daix){
							ci--;
							zui-=c[i];
						}
					}
				}
			}
		cout << zui << endl;
	
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> id[i];
		dfs(id[i]);		
	} 
	return 0;
} 