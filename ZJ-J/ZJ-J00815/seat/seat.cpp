#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int gr[110];
int n,m,fi;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>gr[0];
	fi=gr[0];
	for(int i=1;i<n*m;i++){
		cin>>gr[i];
	}
	sort(gr+0,gr+n*m,cmp);
	int x=1,y=1,way=0;
	for(int i=0;i<n*m;i++){
		if(way==0){
			if(x>n){
				x=n;
				y++;
				way=1;
			}
			if(gr[i]==fi){
				cout<<y<<" "<<x;
				return 0;
			}
			if(way==0){
				x++;
			}else{
				x--;
			}
		}else{
			if(x<1){
				x=1;
				y++;
				way=0;
			}
			if(gr[i]==fi){
				cout<<y<<" "<<x;
				return 0;
			}
			if(way==0){
				x++;
			}else{
				x--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;//#Shang4Shan3Ruo6Shui4
}
