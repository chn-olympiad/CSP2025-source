 #include <cstdio>
 #include <string>
 char a[1000001];
 int b[1000001];
 int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	int l=0;
 	for(int i=1;i<=1000;i++){
 		int f=scanf("%c",&a[i]);
 		if (a[i]>='0'){
 			if (a[i]<='9'){
 				b[i]=a[i]-'0';
			}	
		}
		if (f>=0){
	 		l=i;
	 		break;
	 	}
	}
	for(int i=l;i<=1;i--){
		for(int j=1;j<=l;j++){
	 		if (b[i]>b[j]){
	 			int t=b[i];
	 			b[i]=b[j];
	 			b[j]=t;
			}
		}
	}
	for(int i=1;i<=l;i++){
		printf("%d",b[i]);
	}
	printf("\n");
 	return 0;
 }
