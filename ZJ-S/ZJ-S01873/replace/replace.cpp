#include<stdio.h>
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	fclose(stdin);fclose(stdout);
	return 0;
}