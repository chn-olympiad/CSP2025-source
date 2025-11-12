#include<bits/stdc++.h>
inline int read(){
	int X=0;char ch;bool f=0;
	do{ch=getchar();f|=(ch=='-');}while(!isdigit(ch));
	do{X=(X<<1)+(X<<3)+(ch^48);}while(isdigit(ch=getchar()));
	return f?-X:X;
}
signed main(){
	return 0;
}