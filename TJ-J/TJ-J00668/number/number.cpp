#include<bits/stdc++.h>
using namespace std;

char s[1000002],zancun[1000002];
int num[10][1000002]={-1},place[10]={0};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	scanf("%s",s);

	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			zancun[place[0]]=s[i];
			place[0]++;
		}
	}

	place[0]=0;

	for(int i=0;i<strlen(zancun);i++){
		int shu=int(zancun[i])-48;
		num[shu][place[shu]]=shu;
		place[shu]++;
	}

	for(int i=9;i>=0;i--){
		for(int j=0;j<place[i];j++){
			if(num[i][j]>=0){
				printf("%d",num[i][j]);
			}else{
				j=place[i];
			}
		}
	}

	return 0;
}
