#include<bits/stdc++.h>
using namespace std;
int a=0,b,c,d,e,f,g;
int cba[511111];
int abc1[22],abc2[22],abc3[22];
int main(){
	freopen("xor1.in ","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int x=0;x<a;x++){
		cin>>cba[x];
	}
	for(int x=0;x<a;x++){
		if(cba[x]==b){
			g++;
			cba[x]=-1;
		}
	}
	for(int x=2;x<=a;x++){
		for(int y=0;y<a-1;y++){
			if(cba[y]!=-1){
				f=0;
				abc1[22]={0};
				for(int aaa=cba[y];aaa!=0;){
					if(aaa%2!=0){
						abc1[f]=1;
						aaa-=1;
					}else{
						abc1[f]=0;
					}
					aaa/=2;
				}
				for(int z=y+1;z<y+x&&z<a&&cba[z]!=-1;z++){
					f=0;
					abc2[22]={0};
					for(int aaa=cba[z];aaa!=0;){
						if(aaa%2!=0){
							abc2[f]=1;
							aaa-=1;
						}else{
							abc2[f]=0;
						}
						aaa/=2;
					}
					for(int aaa=22;aaa>=0;aaa--){
						if(abc1[aaa]==abc2[aaa]){
							abc3[aaa]=0;
						}else{
							abc3[aaa]=1;
						}
					}
					for(int i=22;i>=0;i--){
						abc1[i]=abc3[i];
					}
				}
				int i=0;
				for(int aaa=22;aaa>=0;aaa--){
					i*=2;
					i+=abc3[aaa];
				}
				if(i==b){
					g++;
					for(int z=y;z<y+x;z++){
					cba[z]=-1;
					}
				}
			}
	    }
	}
	cout<<g;
	return 0;
}
