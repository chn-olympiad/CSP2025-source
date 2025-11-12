#include<bits/stdc++.h>
using namespace std;
int nl[20][20];
int tongpx[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xrcj;
	cin>>n>>m;
	int fla=true;
	if(n==1&&m==1){
		int a;
		cin>>a;
		cout<<a;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}for(int i=0;i<n*m;i++){
		int a;
		cin>>a;
		tongpx[a]++;
		if(fla){
			xrcj=a;
			fla=false;
		}
	}int dqnz=0,dqmz=0;
	bool sfws=false;
	for(int i=100;i>=0;i--){
		if(tongpx[i]!=1){
			continue;
		}if(i==xrcj){
			cout<<dqmz+1<<' '<<dqnz+1;
			break;
		}if(sfws){
			dqnz--;
			if(dqnz<0){
				dqnz++,dqmz++;
				sfws=false;
			}
		}else{
			dqnz++;
			if(dqnz>=n){
				dqnz--,dqmz++;
				sfws=true;
			}
		}nl[dqnz][dqmz]=i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
