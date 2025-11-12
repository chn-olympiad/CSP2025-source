#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,a[N];
int cnt,ans;
bool A(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return false;
	}
	return true;
} 
bool B(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=0) return false;
	}
	return true;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(A()){
		if(k==0){
			n/=2; 
			printf("%d",n);
			return 0;
		}else if(k==1){
			printf("%d",n);
			return 0;
		}else{
			printf("%d",0);
			return 0;
		}
	}if(B()){
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
			if(a[i]==0) ans++;
		}
		if(k==1){
			printf("%d",cnt);
		}else if(k==0){
			cnt/=2;
			ans/=2;
			ans+=cnt;
			printf("%d",ans);
		}else{
			printf("%d",0);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
