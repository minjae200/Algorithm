#include <iostream>
#include <cstring>
using namespace std;
int map[9][9];
bool sero[9][10];
bool garo[9][10];
bool rect[9][10];
bool print_flag= false;
void print_sdoku(void)
{
	for(int i = 0; i<9; i++)
	{
		for(int j = 0; j<9; j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	print_flag = true;
}

void DFS(void)
{
	int r = -1, c = -1;
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			if(map[i][j] == 0){
				r = i; c = j; break;
			}
		}
		if(r != -1) break;
	}

	if(r==-1 && c==-1) {print_sdoku(); return;}
	if(!print_flag){
		for(int i = 1; i<=9; i++){
			if(!garo[r][i] && !sero[c][i] && !rect[r/3*3+c/3][i]){
				garo[r][i] = sero[c][i] = rect[r/3*3+c/3][i] = true;
				map[r][c] = i;
				DFS();
				map[r][c] = 0;
				garo[r][i] = sero[c][i] = rect[r/3*3+c/3][i] = false;
			}
		}
	}
}

int main(void)
{
	memset(sero, false, sizeof(sero));
	memset(garo, false, sizeof(garo));
	memset(rect, false, sizeof(rect));
	memset(map, 0, sizeof(map));
    // freopen("input.txt", "r", stdin);
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			cin>>map[i][j];
			garo[i][map[i][j]] = true;
			sero[j][map[i][j]] = true;
			rect[(i/3)*3+j/3][map[i][j]] = true;
		}
	}
	cout<<endl;
	DFS();
	return 0;
}