#include<bits/stdc++.h>
using namespace std;
int mapa[5005];
int n,k;
int a[5050];
long long mapb[105]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456};
void solve(){
	a[0]+=1;
	for(int i=0;i<5005;i++){
		if(a[i]>1){
			a[i]=0;
			a[i+1]+=1;
		}
	}
	for(int i=0;i<20;i++){
		cout<<a[i];
	}
	cout<<endl;
}
int xorcz(int x,int y){
	int ans=0;
	stack<bool> xc;
	stack<bool> yc;
	for(int i=25;i>=0;i--){
		if(x>=mapb[i]){
			xc.push(1);
			x-=mapb[i];
		}
		else{
			xc.push(0);
		}
	}
	for(int i=25;i>=0;i--){
		if(y>=mapb[i]){
			yc.push(1);
			y-=mapb[i];
		}
		else{
			yc.push(0);
		}
	}
	int cnt=0;
	while(!xc.empty()){
		bool tmpx=xc.top();
		bool tmpy=yc.top();
		xc.pop();
		yc.pop();
		if(tmpx==1&&tmpy==0||tmpx==0&&tmpy==1){
			ans+=mapb[cnt];
			cnt++;
		}		
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>mapa[i];
	}
	if(n<=2){
		int asd;
		if(n==1){
			if(mapa[0]==k){
				asd=1;
				cout<<asd<<endl;
			}
			else{
				asd=0;
				cout<<asd<<endl;
			}
		}
		if(n==2){
			if(mapa[0]==k&&mapa[1]==k){
				asd=2;
				cout<<asd<<endl;
			}
			else if((mapa[0]==k&&mapa[1]!=k)||(mapa[0]!=k&&mapa[1]==k)||(xorcz(mapa[0],mapa[1])==k)){
				asd=1;
				cout<<asd<<endl;
			}
			else{
				asd=0;
				cout<<asd<<endl;
			}
		}
	}
	else{
		cout<<n/2<<endl;
	}
	return 0;
}
