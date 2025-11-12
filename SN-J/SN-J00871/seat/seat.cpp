#include<bits/stdc++.h>
using namespace std;
int main(){
	FILE *fp;
	fp=fopen("seat.in");
	//fp=fopen("s.in")
	int	b[100],i=0,x,y,q=0,n,m,xx,yy,j,k;
	fscanf(fp,"%d%d",&n,&m);
	//cin>>n>>m>>b[100];
	while(b[i]=!"/n"){
		i++;
		//scanf("%d",&b[i],"r");
        fscanf(fp,"%d",&b[i],"r");
    }
    x=b[0];
	for(j=0;j<i;j++){
		for(k=0;k<i-j;k++){
			if(b[j]<=b[j+1]){
				y=b[j];
				b[j]=b[j+1];
				b[j+1]=y;
			}
	    }
	}	
	while(b[q]=!x){
		q++;
	}
	xx=q/n;
	yy=q%n;
	//cout<<xx<<" "<<yy;
	
	fprintf(fopen("seat.out"),xx," ",yy);
	//fprint(fopen("s.out"),xx," ",yy"w");
	fclose(fp);
	return 0;
}
