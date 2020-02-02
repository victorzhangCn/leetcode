class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        row = [[False for c in range(9)] for r in range(9)]
        column = [[False for c in range(9)] for r in range(9)]
        box = [[False for c in range(9)] for r in range(9)]
        size = len(board)

        for i in range(size):
            for j in range(size):
                if board[i][j] == '.':
                    continue
                num = int(board[i][j]) - 1
                box_num = i/3 * 3 + j/3
                if row[i][num] or column[j][num] or box[box_num][num]:
                    return False
                else:
                    row[i][num] = True
                    column[j][num] = True
                    box[box_num][num] = True

        return True
