#include<bits/stdc++.h>
using namespace std;
int n,k,res;
int a[500000];
int pow2[22]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,528288,1048576,2097152};
//艾汐3巅峰打表王
//幸亏背过,要不然就完了 
int calxor(int x,int y){
	bool binx[22]={0};
	bool biny[22]={0};
	int t=0,ans=0,rx=x,ry=y;
	while(rx){
		binx[t]=rx%2;
		rx/=2;
		t++; 
	}
	t=0;
	while(ry){
		biny[t]=ry%2;
		ry/=2;
		t++; 
	}
	for(int i=0;i<22;i++){
		if(binx[i]!=biny[i]){
			ans+=pow2[i];
		}
	}
	return ans;
}
void calxorequals(int s,int f){
	if(s==f||s>f){
		return;
	}
	for(int i=2;i<=(f-s+1);i++){
		for(int j=s+i-1;j<=f;j++){
			int ans=a[j];
			for(int l=1;l<i;l++){
				ans=calxor(ans,a[j-l]);
			}
			if(ans==k){
				res++;
				calxorequals(s,j-i);
				calxorequals(j+1,f);
				return;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int st=0;
	for(int i=0;i<n;i++){
		if(a[i]==k){
			res++;
			calxorequals(st,i-1);
			st=i+1; 
		}
	}
	calxorequals(st,n-1);
	cout<<res<<endl;
}
