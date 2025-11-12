#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
int a[N];
int R;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int Posx=1,Posy=0;
	int flag=0;
	for(int i=1;i<=n*m;i++){
		if(flag==0){
			if(Posy==n){
				Posx++;
				Posy=n;
				flag^=1;
			}
			else{
				Posy++;
			}
			if(a[i]==R){
				cout<<Posx<<" "<<Posy<<endl;
				break;
			}
		}
		else{
			if(Posy==1){
				Posy=1;
				Posx++;
				flag^=1;
			}
			else{
				Posy--;
			}
			if(a[i]==R){
				cout<<Posx<<" "<<Posy;
				break;
			}
		}
	}
	return 0;
}