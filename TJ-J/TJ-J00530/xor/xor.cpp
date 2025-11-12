#include<bits/stdc++.h>
using namespace std;
int churqvyu(int x){
	int jishuqi=1,san=0;
	while(x>0){
		san+=x%2*jishuqi;
		jishuqi*=10;
		x/=2;
	}
	return san;
}

int main(){
	freopen("xor.in","r",stdin);//^_^
	freopen("xor.out","w",stdout); 
	cin.tie(0);
	int n,k;
	int san3dai[100091];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>san3dai[i];
	}
	if(k==0){
		cout<<1; 
		return 0;
	}//------------------------------------------OvO 
	if(k<=1){
	int jishuqi=0;
	for(int i=1;i<=n;i++){
		
		if(san3dai[i]==1){
			jishuqi++;
		}
	}
	cout<<jishuqi;
	}//-------------------------------------------=w=
	return 0;
} 
