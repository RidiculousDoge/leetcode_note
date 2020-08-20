#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx8[8] = { -1,-1,-1,0,0,1,1,1 };
int dy8[8] = { 0,-1,1,-1,1,-1,0,1 };
class pos {
public:
	int x;
	int y;
	pos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
bool isNum(char ch) {
	return (ch >= '1' && ch <= '9');
}
bool isOutOfBound(vector<vector<char>>& board, int x, int y) {
	return (x<0 || y<0 || x>board.size() - 1 || y>board[0].size() - 1);
}
int getNext2bombNum(vector<vector<char>>& board, int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int new_x = x + dx8[i];
		int new_y = y + dy8[i];
		if (isOutOfBound(board, new_x, new_y)) continue;
		if (board[new_x][new_y] == 'M') cnt++;
	}
	return cnt;
}

void bfs(vector<vector<char>>& board, int x, int y) {
	if (isOutOfBound(board, x, y)) return;
	pos cur(x, y);
	queue<pos> q;
	q.push(cur);
	while (!q.empty()) {
		pos u = q.front();
		q.pop();

		bool flag = false;
		for (int i = 0; i < 8; i++) {
			int new_x = u.x + dx8[i];
			int new_y = u.y + dy8[i];
			if (isOutOfBound(board, new_x, new_y)) continue;
			if (board[new_x][new_y] == 'M') {
				flag = true;
				board[u.x][u.y] = getNext2bombNum(board, u.x, u.y);
			}
			else if (board[new_x][new_y] == 'B' || isNum(board[new_x][new_y])) continue;
		}
		if (!flag) {
			board[u.x][u.y] = 'B';
			for (int i = 0; i < 8; i++) {
				int new_x = u.x + dx8[i];
				int new_y = u.y + dy8[i];
				if (isOutOfBound(board, new_x, new_y) || board[new_x][new_y] == 'B'||isNum(board[new_x][new_y])) continue;
				else {
					pos tmp(new_x, new_y);
					q.push(tmp);
				}
			}
		}
	}
}
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
	int x = click[0];
	int y = click[1];
	if (board[x][y] == 'M') {
		board[x][y] = 'X';
		return board;
	}
	if (board[x][y] == 'B' || isNum(board[x][y])) return board;
	int row = board.size();
	int col = board[0].size();
	bfs(board, x, y);
	return board;
}

int main() {
	vector<vector<char>> board = { vector<char>{'E','E','E','E','E'},vector<char>{'E','E','M','E','E'},
									vector<char>{'E','E','E','E','E'},vector<char>{'E','E','E','E','E'} };
	vector<int> click = { 3,0 };
	board=updateBoard(board, click);
	return 0;
}