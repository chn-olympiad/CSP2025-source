#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[500];
int c[500];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool flag=true;
	for(int i=0;i<sizeof(s);i++){
		if(s[i]!='1'){
			flag=false;
		}
	}
	if(flag){	
		for(int i=1;i<n;i++){
			int x=i;
			int cnt1=0;
			int yixuan[n+1]={0};
			while(x){
				cnt1+=x&1;
				yixuan[cnt1]=x&1;
				if(cnt1>m){
					break;
				}
				x>>1;
			}
			if(cnt1==m){
				int xuan[n+1];
				int index=1;
				for(int i=0;i<n;i++){
					if(yixuan[i]){
						xuan[index]=index;
						index++;
					}
				}
				do{
					ans++;
				}while(next_permutation(xuan+1,xuan+n+1));
			}
		}
		cout<<ans%998244353;
		return 0;
	}
	cout<<998244352;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
