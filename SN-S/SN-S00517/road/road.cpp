#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
int price=0;
struct road{
	int from;
	int to;
	int pay;
}road[N];
struct vill{
	int pay;
	int villpay[N];
	bool city=false;
}vill[12];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&road[i].from,&road[i].to,&road[i].pay);
	}
	for (int i=1;i<=k;i++){
		cin>>vill[i].pay;
		for (int j=1;j<=n;j++){
			cin>>vill[i].villpay[j];
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=k;j++){
			if (vill[j].city==false){
				if (road[i].pay>=vill[j].pay+vill[j].villpay[road[i].from]+vill[j].villpay[road[i].to]){
					price+=vill[j].pay+vill[j].villpay[road[i].from]+vill[j].villpay[road[i].to];
					vill[j].city=true;
					cout<<price<<endl;
				}else{
					price+=road[i].pay;
				}
			}else if(vill[j].city==true){
				if (road[i].pay>vill[j].villpay[road[i].from]+vill[j].villpay[road[i].to]){
					price+=vill[j].villpay[road[i].from]+vill[j].villpay[road[i].to];
					cout<<price<<endl;
				}else{
					price+=road[i].pay;
				}
			}
		}
	}
	cout<<price;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
