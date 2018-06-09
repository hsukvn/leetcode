#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		bool exist(vector<vector<char>>& board, string word) {
			for (int i = 0; i < board.size(); ++i) {
				for (int j = 0; j < board[i].size(); ++j) {
					if (dfs(board, i, j, word, 0)) {
						return true;
					}
				}
			}
			return false;
		}

		bool dfs(vector<vector<char>> &board, int x, int y, string word, int i) {
			if (i == word.size() - 1 && board[x][y] == word[i]) {
				return true;
			}

			if (board[x][y] != word[i]) {
				return false;
			}

			board[x][y] = '-';
			if (x+1 < board.size() && dfs(board, x+1, y, word, i+1)) {
				return true;
			} else if (x-1 >= 0 && dfs(board, x-1, y, word, i+1)) {
				return true;
			} else if (y+1 < board[0].size() && dfs(board, x, y+1, word, i+1)) {
				return true;
			} else if (y-1 >= 0 && dfs(board, x, y-1, word, i+1)) {
				return true;
			}
			board[x][y] = word[i];

			return false;
		}
};

int main()
{
	Solution a;

	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
	};

	vector<vector<char>> board2 = {
		{'A'},
	};

	cout << a.exist(board, "ABCCED");

	return 0;
}
