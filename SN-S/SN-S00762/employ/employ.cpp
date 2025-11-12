#include<bits/stdc++.h>
using namespace std;
int q;
int ans;
int s[3000010];
bool di[1000];
int pat[1000];
void d(int x,int y,int z){
	for(int i=1;i<=x;i--){
		if(di[i]==0)	y--;
		else{
			for(int i=1;i<=x;i++){
				pat[i]--;
				if(pat[i]<=0){
					di[i]=1;
				}
			}
		}
		
	}
	if(y<=0){
		q++;
		}
		
	for(int i=1;i<z;i++){
		int u;
		u=pat[i];
		pat[i]=pat[z];
		pat[z]=u;
		d(x,y,x-1);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>di[i];
	for(int i=1;i<=n;i++)	cin>>pat[i];
	sort(pat,pat+n+1);
	d(n,m,n);
	
	for(int i=1;i<=n;i++)	p+=i;
	cout<<p-q;
	return 0;
}
