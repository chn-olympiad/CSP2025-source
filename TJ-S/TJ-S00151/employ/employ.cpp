#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[510],tt,cnt=0;
bool f[510];
string s;
void sf(){
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	tt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]-'0'==0||tt>=a[i]){
			tt++;
		}
	}
	if(n-tt>=m){
		cnt++;
	}
}
void xz(int g){
	for(int i=1;i<=n;i++){
		if(f[i]!=true){
			f[i]=true;
			a[g]=b[i];
			if(g<n){
				xz(g+1);
			}else{
				sf();
			}
			f[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	xz(1);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
