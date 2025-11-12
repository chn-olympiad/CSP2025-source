#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || '9'<ch){
		if(ch=='-'){
			f*=-1;
		}
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(NULL));
	cout<<rand()%10005+11;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


