#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> vec;
	char ch;scanf("%c",&ch);
	while(ch!='\n'){
		if(ch>='0' && ch<='9'){
			vec.push_back(ch-'0');
		}
		scanf("%c",&ch);
	}
	sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;i--){
		printf("%d",vec[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
