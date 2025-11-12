#include<iostream>
using namespace;
int main(){
	feropen("seat.in","r",stdin);
	feropen("seat.out","w",stdout);
	int(g,n,m,a,r,c){
		cin >> g >> n >> m >> a >> r >> c;
		g = n * m;
		for(a <= g,a++){
			c = a / n;
		    r = a % n;
		}
		count << c << r << endl;
		break;
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
