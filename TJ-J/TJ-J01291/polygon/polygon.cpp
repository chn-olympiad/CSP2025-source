#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e3+10;
int a[N];
int sum=0;
int summ=0;
int main(){
	//remember freopen!!!
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	int genshin=0;
	int x;
	int y;
	for(int j=1;j<=n-2;j++){
		for(int z=j+2;z<=n;z++){
			x=j;
			y=z;
			cout<<x<<" "<<y<<endl;
			sum=0;
			genshin=0;
			for(int i=x;i<=y;i++){
				if(a[i]>genshin){
					genshin=a[i];
				}
				sum+=a[i];
			}
			cout<<sum<<endl;
			cout<<genshin<<endl;
			if(sum>genshin*2){
				summ++;
			}
			cout<<summ<<endl;
		}
	}
	cout<<summ<<endl;
	return 0;
}
//Best wishes to me first.Thanks alot.
