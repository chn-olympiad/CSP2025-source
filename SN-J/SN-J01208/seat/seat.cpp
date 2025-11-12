#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,h;
int aa[15][15],bb[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>bb[i];
	}
	c=bb[1];
	sort(bb+1,bb+a*b+1,cmp);
	for(int i=1;i<=a;i++){
		if(i%2==1){
			for(int j=1;j<=b;j++){
				d++;
				aa[j][i]=bb[d];
//				if(aa[i][j]==c){
//					cout<<i<<" "<<j<<endl;
//				}
			}
		}else{
			for(int j=b;j>=1;j--){
				d++;
				aa[j][i]=bb[d];
//				if(aa[i][j]==c){
//					cout<<i<<" "<<j<<endl;
//				}
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(aa[i][j]==c){
				cout<<j<<" "<<i;
			}
		}
		//cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
