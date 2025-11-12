#include<bits/stdc++.h>
using namespace std;
int n;
int sticks[5003];
long long ans;
int cnt1(int x){
	int cnt=0;
	while(x){
		cnt+=x&1; 
		x>>1;
	}
	return cnt;
}
bool check(int tmp[5003]){
	int maxl=0;
	int num=0;
	for(int i=1;i<=sizeof(tmp)/sizeof(tmp[0]);i++){
		maxl=max(maxl,tmp[i]);
		num+=tmp[i];
	}
	if(num>2*maxl){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sticks[i];
	}
	if(n==3){
		int maxl=0;
		int num=0;
		for(int i=1;i<=n;i++){
			maxl=max(maxl,sticks[i]);
			num+=sticks[i];
		}
		if(num>2*maxl){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else{
		for(int i=3;i<=n;i++){
			for(int j=0;j<=12;j++){
				if(cnt1(j)==i){
					int tmp[i];
					int tmp1[n];
					int tmpj=j;
					int index=0;
					while(tmpj){
						tmp1[index]=tmpj&1;
						tmpj>>1;
						index++;
					}
					index=0;
					for(int k=1;k<=n;k++){
						if(tmp1[k]){
							tmp[index]=sticks[k];
						}
					}
					if(check(tmp)){
						ans++;
					}
				}
			}
		}
	}
	
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
