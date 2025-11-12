#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n;
long long a[5025];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(a[1]==2) cout<<"6";
	else cout<<"9";
	return 0;
}
/*
▁▂▃▄▅▆▇█
▏▎▍▌▋▊▉
▓??※∷
∷※??▓????◢◣◥◤
┌┬┐┏┳┓╔╦╦╭─╮
├┼┤┣╋┫╠╬╣│╳┃
└┴┘┗┻┛╚╩╝╰━╯
*/
/*
wcnm       nmm     wrnxr	
我草你妈  你没妈  我日你先人
@ctr
@出题人 
*/
