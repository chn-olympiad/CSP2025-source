#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
char ss[2000005];
priority_queue<int> zifu;
int x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ss;
	int lens=strlen(ss);
	for(int i=0;i<lens;i++){
		if(ss[i]>='a'&&ss[i]<='z'){
			continue;
		}else{
			x=ss[i]-'0';
			zifu.push(x);
		}
	}
	int zi=zifu.top();
	if(zi==0){
		printf("0");
		return 0;
	}else if(zifu.empty()){
		printf("0");
		return 0;
	}
	while(!zifu.empty()){
		printf("%d",zifu.top());
		zifu.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
