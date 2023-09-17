/*
Time: O(N) - # of rotten oranges will spread to fresh oranges. Only one process per coordinate;
Space: O(N) - store all coordinates in a queue;

Algo:
Input is a grid[][]
0 = empty cell
1 = fresh Orange
2 rotten Orange

Every minute, a rotten orange will spread rot on its neighbors. Calculate total minute to rotten all oranges. IF not possible, return -1;

Solution:
1. Get all rotten oranges and put it inside queue.
2. Do 1 round of BFS on each rotten oranges.
3. Put all fresh oranges in the queue.
4. Repeat until no more fresh oranges.
*/

public class Solution {
    int[][] grid;
    //0 = empty cell
    //1 = fresh orange
    //2 = rotten orange
    List<int[]> directions;
    int maxRow;
    int maxCol;
    int totalFreshOrangesThatGotRotten;

    public int OrangesRotting(int[][] grid) {
      this.grid = grid;
      if(grid == null) return -1;
      maxRow = grid.Length;
      maxCol = grid[0].Length;
      var queue = new Queue<Coordinates>();
      var ans = 0;
      var initialFreshCount = 0;
      totalFreshOrangesThatGotRotten = 0;

      directions = new List<int[]>();
      addDirections(directions);

      //Traverse grid and get all rotten oranges and put in a queue
      for(int r=0;r<maxRow;r++){
        for(int c=0;c<maxCol;c++){
          if(grid[r][c] == 2){
            queue.Enqueue(new Coordinates(r,c));
          }
          if(grid[r][c] == 1){
            initialFreshCount++;
          }
        }
      }
      

      if(!queue.Any() && initialFreshCount > 0) return -1;
      if(!queue.Any()) return 0;

      //Process Queue
      ans = processQueue(queue);

      return totalFreshOrangesThatGotRotten == initialFreshCount ? ans : -1; 
    }

    //Processes Rotten Oranges and calculate total elapsed time.
    public int processQueue(Queue<Coordinates> queue){
      var minutesElapsed = -1;

      while(queue.Any()){
        var levelSize = queue.Count();

        for(int i=0;i<levelSize;i++){
          var coordinate = queue.Dequeue();

          foreach(var direction in directions){
            var newRow = coordinate.row + direction[0];
            var newCol = coordinate.col + direction[1];

            //calculate out of bounds
            if(newRow < 0 || newRow >= maxRow || newCol < 0 || newCol >= maxCol)
              continue;

            //fetch all neighbor fresh oranges and put in the queue
            if(grid[newRow][newCol] == 0 || grid[newRow][newCol] == 2) continue;
            grid[newRow][newCol] = 2;
            totalFreshOrangesThatGotRotten++;
            queue.Enqueue(new Coordinates(newRow,newCol));
          }
          
        }

        minutesElapsed++;
      }

      return minutesElapsed;
    }

    public void addDirections(List<int[]> directions){
      directions.Add(new int[2]{-1,0});
      directions.Add(new int[2]{0,1});
      directions.Add(new int[2]{1,0});
      directions.Add(new int[2]{0,-1});
    }

    public class Coordinates{
      public int row;
      public int col;

    public Coordinates(int row, int col) {
      this.row = row;
      this.col = col;
    }

  }
}













