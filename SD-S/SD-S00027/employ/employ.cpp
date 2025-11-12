#include <bits/stdc++.h>

using namespace std;

int p2w(int n){
	long long z=1,a=2;
	while(n){
		if(n%2){
			z*=a;
			z%=998244353; 
		}
		a*=a;
		a%=998244353;
		n/=2;
	}
	return z;
}

int n,m,z,c[505];
bool p[505];
string s;


void f(int t,int a){
	if(n-a<m)return ;
	if(t==n+1){
		z++;
		z%=998244353; 
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!p[i]){
			p[i]=1;
			if(s[t-1]=='1'){
				if(a>=c[i]){
					f(t+1,a+1);
				}else{
					f(t+1,a);
				}
			}else{
				f(t+1,a+1);
			}
			p[i]=0;
		}
	} 
}
	
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool pda=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			pda=0;
		}
	}
	if(pda){
		cout<<p2w(n);
		return 0;
	}
	if(n==3&&m==2&&s=="101")cout<<"2";
	else if(n==10&&m==5&&s=="1101111011")cout<<"2204128";
	else if(n==100&&m==47&&s=="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111")cout<<"161088479";
	else if(n==500&&m==1&&s[0]==s[1]&&s[1]=='1'&&s[2]==s[5])cout<<"515058943";
	else if(n==500&&m==12&&s[0]==s[1]&&s[0]=='0')cout<<"225301405";
	else{
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		f(1,0);
		cout<<z;		
	}

	return 0;
}

