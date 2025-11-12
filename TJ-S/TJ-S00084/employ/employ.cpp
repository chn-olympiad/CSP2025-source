#include<bits/stdc++.h>
using namespace std;
int n,m,sum,k;
string s;
int a;
int sda(int k,int m){
	for(int i = 1;i<=k;i++){
		if(m!=2){
			
			if(k!=1){
				sda(k-1,m-1);
			}
		}else{
			sum++;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m; 
	cin >> s;
	k=n;
	for(int i = 1;i<=n;i++){
		cin >> a;
		if(a==0){
			k--;
		}
	}
	if(k<m){
		cout << 0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(m==1){
		cout << k%998244353 << "\n";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(k==0){
		cout << 0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(k==1){
		cout << 1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(m==0){
		cout << 0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i = 1;i<=k;i++){
		sda(k-1,m);
	}
	cout << sum%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
