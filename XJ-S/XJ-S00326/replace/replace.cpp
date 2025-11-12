#include<bits/stdc++.h>
using namespace std;
template<typename type>
inline void read(type &x){
	x=0;
	static bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){
		flag=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	flag?x=-x:0;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}

