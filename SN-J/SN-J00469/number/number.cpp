#include<bits/stdc++.h>
using namespace std;
char r;
int x[5000000],l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&r)!=EOF){
		if(r>='0'&&r<='9'){
			l++;
			x[l]=r-'0';
		}
	}
	sort(x+1,x+l+1);
	if(x[l]==0){printf("0");return 0;} 
	for(int i=l;i>=1;i--) printf("%d",x[i]);
	return 0;
}
