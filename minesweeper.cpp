
class Solution {
typedef std::pair<int, int> co_ord;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        std::queue<co_ord> breadth_queue;
        std::vector<int> dx = { -1, -1, 0, 1, 1, 1, 0, -1 };
        std::vector<int> dy = { 0, 1, 1, 1, 0, -1, -1, -1 };

        auto isAdjacentMinePresent = [&dx, &dy, &board](co_ord& p, int& c)->bool {
            for (int i = 0; i < dx.size(); ++i) 
                if (p.first + dx[i] >= 0 && p.first + dx[i] < board.size() &&
                    p.second + dy[i] >= 0 && p.second + dy[i] < board[0].size()) 
                    if (board[p.first + dx[i]][p.second + dy[i]] == 'M')
                        ++c;

            return c ? true : false;
        };

        auto enqueue_adjacent = [&dx, &dy, &board](std::queue<co_ord>& q, co_ord& p) {
            for (int i = 0; i < dx.size(); ++i) 
                if (p.first + dx[i] >= 0 && p.first + dx[i] < board.size() &&
                    p.second + dy[i] >= 0 && p.second + dy[i] < board[0].size())
                    q.push(std::make_pair(p.first + dx[i], p.second + dy[i]));
   
        };

        breadth_queue.push(std::make_pair(click[0], click[1]));
        do {
            co_ord aPoint = breadth_queue.front();
            breadth_queue.pop();

            if (board[aPoint.first][aPoint.second] == 'E') {
                int count = 0;
                if (isAdjacentMinePresent(aPoint, count))
                    board[aPoint.first][aPoint.second] = std::to_string(count)[0];
                else {
                    board[aPoint.first][aPoint.second] = 'B';
                    enqueue_adjacent(breadth_queue, aPoint);
                }
            }

            if (board[aPoint.first][aPoint.second] == 'M')
                board[aPoint.first][aPoint.second] = 'X';

        } while (!breadth_queue.empty());

        return board;
    }
};
