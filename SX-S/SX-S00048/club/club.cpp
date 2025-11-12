#include<bits/stdc++.h>
using namespace std;
long long a,b,c[200005],cc[200005],ccc[200005],cmax,ccmax,cccmax,cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		for(int j=1;j<=b;j++){
			cin>>c[j]>>cc[j]>>ccc[j];
		}
		sort(c+1,c+1+b);
		sort(cc+1,cc+1+b);
		sort(cc+1,ccc+1+b);
		int headone,headtwo,headthree;
		headone=headtwo=headthree=b;
		while(b--){
			if(c[headone]>cc[headtwo]){
				if(c[headone]>ccc[headthree]){
					cnt+=c[headone];
					headone--;
				}else{
					cnt+=ccc[headthree];
					headthree--;
				}
			}else{
				if(cc[headtwo]>ccc[headthree]){
					cnt+=cc[headtwo];
					headtwo--;
				}else{
					cnt+=ccc[headthree];
					headthree--;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}