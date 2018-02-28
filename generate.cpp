#include <bits/stdc++.h>
using namespace std;



void input(char in[]){
	freopen (in,"w",stdout);
//	Put test case genaror Code below such that it prints output on STDIO		
}

void output(char in[], char out[]){
	freopen (in,"r",stdin);
	freopen (out,"w",stdout);
//	Put Solution for the question below such that it prints answer on STDIO	
}

int main(){
	srand(time(NULL));
	char in[105][20], out[105][20];
	int files;
	scanf("%d", &files);
	for(int i = 0; i < files; ++i){
		int tmp = i;
		char s[2];
		s[1] = (char)(tmp % 10 + '0');
		tmp /= 10;
		s[0] = (char)(tmp % 10 + '0');
		in[i][0] = 'i'; in[i][1] = 'n'; in[i][2] = s[0]; in[i][3] = s[1]; 
		in[i][4] = '.'; in[i][5] = 't'; in[i][6] = 'x'; in[i][7] = 't'; in[i][8] = '\0';
		out[i][0] = 'o'; out[i][1] = 'u'; out[i][2] = 't'; out[i][3] = s[0]; out[i][4] = s[1];
		out[i][5] = '.'; out[i][6] = 't'; out[i][7] = 'x'; out[i][8] = 't';out[i][9] = '\0';
	}
	for(int i = 8; i < files; ++i){
		input(in[i]);
		output(in[i], out[i]);
	}
}
