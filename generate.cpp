#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define bitcount __builtin_popcountll
#define INF 1e18
#define endl '\n'
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define trace(x) cerr<<#x<<": "<<x<<endl
using namespace std;



void input(char in[]){
	freopen (in,"w",stdout);
	int t = 10;
	cout << t << endl;
	while(t--){
		int n = 20, m = 150;
		cout << n << " " << m << endl;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cout << rand() % 2 << " ";
			}
			cout << endl;
		}
	}
}

const int N = 25;
long long mask1[N], mask2[N], mask3[N];
void output(char in[], char out[]){
	freopen (in,"r",stdin);
	freopen (out,"w",stdout);
	int n, m, tm;
	int t;
	scanf("%d", &t);
	
	assert(1<=t && t<=10);
	while(t--){
		memset(mask1, 0, sizeof(mask1));
		memset(mask2, 0, sizeof(mask2));
		memset(mask3, 0, sizeof(mask3));
		scanf("%d %d", &n, &m);
		assert(n>=1 && n<=20);
		assert(m>=1 && m<=160);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d", &tm);
				assert(tm <= 1 && tm >= 0);
				if(tm){
					if(j<=60)
						mask1[i] |= (1LL<<(long long)j);
					else if(j <=120)
						mask2[i] |= (1LL<<(long long)(j-60));
					else
						mask3[i] |= (1LL<<(long long)(j-120));
				}
			}
		}
		int ans = 0;
		int sz = 1<<n;
		for(int i = 0; i < sz; ++i){

			long long mk1 = 0, mk2 = 0, mk3 = 0;
			for(int j = 0; j < n; ++j){
				if(i&(1<<j)){
					mk1 |= mask1[j];
					mk2 |= mask2[j];
					mk3 |= mask3[j];
				}
			}
			if(__builtin_popcountll(mk1) + __builtin_popcountll(mk2) + __builtin_popcountll(mk3) == m){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
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