
class Solution {
public:
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        // mとn、キューを定義する
        // 多起点BFS。すべての2（腐ったオレンジ）を最初にキューに入れる
        // 新鮮なオレンジの数と時間（times）を記録する必要がある
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> que;
        int fresh = 0, times = 0;
        // 新鮮なオレンジの数を最初に記録する
        // 同時に、すべての腐ったオレンジをキューに入れる
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    fresh++;
                } else if(grid[i][j] == 2){
                    que.push({i,j});
                }
            }
        }
        // 終了条件：キューが空でないこと
        // 同時に、新鮮なオレンジの数が0より大きいことを確認する
        while(que.size() != 0 && fresh > 0){
            int q_len = que.size();
            // このラウンドでは、このラウンドの腐ったオレンジに対してのみ操作を行う
            // これにより、timesを1増やすことができる
            for(int i=0; i<q_len; i++){
                // 座標xとyを取り出し、上下左右を走査する
                pair<int,int> cur = que.front(); que.pop();
                int x = cur.first;
                int y = cur.second;
                // 上下左右の4方向を走査する
                for(int i=0; i<4; i++){
                    int nextx = x + dir[i][0];
                    int nexty = y + dir[i][1];
                    // 境界条件の処理 + オレンジが1（新鮮）でない場合は処理しない
                    if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size() || grid[nextx][nexty] != 1) continue;
                    grid[nextx][nexty] = 2;
                    fresh = fresh - 1;
                    que.push({nextx, nexty}); 
                }
            }
            times = times + 1;
        }
        if(fresh > 0){
            return -1;
        } else {
            return times;
        }
    }
};
