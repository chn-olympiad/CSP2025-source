#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[250],b;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) b=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int cntl=1,cnth=1,isok=1;
	int w=1;
	while(isok){
		while(cntl<=n && isok){
			if(a[w]==b){
				cout<<cnth<<" "<<cntl;
				isok=0;
				break;
			}
			cntl++;
			w++;
		}
		cnth+=1;
		cntl-=1;
		while(cntl>=1 && isok){
			if(a[w]==b){
				cout<<cnth<<" "<<cntl;
				isok=0;
				break;
			}
			cntl--;
			w++;
		}
		cnth+=1;
		cntl+=1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

