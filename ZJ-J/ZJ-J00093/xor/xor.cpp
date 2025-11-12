#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[100],ans,c[100];
vector <int> ll;
vector <int> rr;
int oki(int x,int y){
	int cc = (x & y),cnt=1,mm=max(x,y),dig=0;
	//int cc=x,cnt=1;
	//memset(0,b,sizeof(b));
	while(cc){
		if(cc%2)b[cnt++]=0;
		else b[cnt++]=1;
		//cout<<b[cnt-1]<<" ";
		cc/=2;
	}
	while(mm){
		mm /= 2;
		dig++;
	}
	int tmmm = 1;
	for(int i = 1;i <= dig - cnt+1;i++){
		c[tmmm++] = 1;
	}
	for(int i = cnt-1;i >= 1;i--){
		c[tmmm++] = b[i];
	}
	int dit=1,aan=0;
	for(int i = tmmm -1;i >= 1;i--){
		aan += dit*c[i];
		dit *= 2;
	}
	//cout<<x<<" "<<y<<" "<<aan<<"\n";
	return aan;
}
int CHK(int l,int r){
	int tmp = a[l];
	for(int i = l+1;i <= r;i++){
		
		tmp = oki(tmp,a[i]);
	}
	return tmp;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			//cout<<"i:"<<i<<" j:"<<j<<"\n";
			int tt = CHK(i,j);
			if(tt == k) {
				ans++;
				i=j;
				//i=max(j-1,1);
				//cout<<i<<" "<<j<<"\n";
			}
		}
	}
	cout<<ans;
	return 0;
}

