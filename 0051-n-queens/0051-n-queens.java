class Solution {
    
    private void findSolution(List<List<String>> sol, List<String> board, int n, int col) {
        if (col == n) {
            sol.add(new ArrayList<>(board));
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (check_legal(board, n, row, col)) {
                StringBuilder rowBuilder = new StringBuilder(board.get(row));
                rowBuilder.setCharAt(col, 'Q');
                board.set(row, rowBuilder.toString());

                // Recur for the next column
                findSolution(sol, board, n, col + 1);

                // Backtrack (remove the queen for the next iteration)
                rowBuilder.setCharAt(col, '.');
                board.set(row, rowBuilder.toString());
            }
        }
    }
    
    private boolean check_legal(List<String> board, int n, int row, int col) {
        // Check for the left side
        for (int i = 0; i < col; i++) {
            if (board.get(row).charAt(i) == 'Q') {
                return false;
            }
        }

        // Check for the left upper diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board.get(i).charAt(j) == 'Q') {
                return false;
            }
        }

        // Check for the left lower diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board.get(i).charAt(j) == 'Q') {
                return false;
            }
        }

        return true;
    }
    
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> sol = new ArrayList<>();
        List<String> board = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < n; j++) {
                row.append('.');
            }
            board.add(row.toString());
        }
        
        findSolution(sol, board, n, 0);
        return sol;
    }
}