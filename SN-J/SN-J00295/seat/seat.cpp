#include<bits/stdc++.h>
using namespace std;
int n,m,score[105],a,pla,cn,cm;
int main(){
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++){
		cin>>score[i];
		if (i == 1) a = score[i];
	}
	for (int i = n*m;i>=1;i--){
		for (int j = 1;j<=i;j++){
			if(score[j+1]>score[j])swap(score[j],score[j+1]);
		}
	}
	for (int i = 1;i<=n*m;i++){
		if (score[i]==a) pla = i;
	}
	int i = 1;
	while(i*n<pla){
		i++;
	}
	cn = i;
	if (cn%2 == 1)cm = pla-(cn-1)*n;
	else cm = n-(pla-(cn-1)*n)+1;
	cout<<cn<<' '<<cm;
	return 0;
}
